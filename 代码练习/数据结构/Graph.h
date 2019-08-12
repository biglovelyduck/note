/*Graph图模板*/
#define INT_MAX 10000001
typedef enum{
	UNDISCOVERED,DISCOVERED,VISITED
}VStatus;//顶点状态
typedef enum{
	UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD
}EStatus; //边状态

template <typename Tv,typename Te>//顶点类型，边类型
class Graph{
private:
	void reset(){//所有顶点，边的辅助信息复位 
		for(int i=0;i<n;i++){
			status(i)=UNDISCOVERED;
			dTime(i)=fTime(i)=-1;//时间标签状态
			parent(i)=-1;
			priority(i)=INT_MAX;
			for(int j=0;j<n;j++){
				if(exists(i,j)) status(i,j)=UNDETERMINED;
			}
		}
	}
	void BFS(int,int&);//连通域，广搜
	void DFS(int,int&);
	void BCC(int,int&,Stack<int>&);
	bool TSort(int,int&,Stack<Tv>*);
	template <typename PU> void PFS(int,PU); 
public:
	int n;//顶点总数
	int e;//边总数
	//顶点接口 
	virtual int insert(Tv const&)=0;//插入顶点，返回编号
	virtual Tv remove(int)=0;//删除顶点及其关联边，返回该顶点信息
	virtual Tv& vertex(int)=0;//顶点v的数据（该顶点的确存在）
	virtual int inDegree(int)=0;//顶点v的入度
	virtual int outDegree(int)=0;//顶点v的出度
	virtual int firstNbr(int)=0;//顶点v的首个连接顶点
	virtual int nextNbr(int,int)=0;//顶点v相对于顶点j的下一个邻接顶点
	virtual VStatus& status(int)=0;//顶点v的状态
	virtual int& dTime(int)=0;//顶点v的时间标签dTime 
	virtual int& fTime(int)=0;//顶点v的时间标签fTime
	virtual int& parent(int)=0;//顶点v在遍历树中的父亲
	virtual int& priority(int)=0;//顶点v在遍历树的优先级数
	
	//边接口
	virtual bool exists(int,int)=0;//边（v,u）是否存在
	virtual void insert(Te const&,int,int,int)=0;//在顶点u，v之间插入权重为w的e 
	virtual Te remove(int,int)=0;//删除v和u之间的边e，并返回该边信息
	virtual EStatus& status(int,int)=0;//边（v,u）的状态
	virtual Te& edge(int,int)=0;//边（v,u）的数据
	virtual int& weight(int,int)=0;//边v,u的权值
	
	//算法
	void bfs(int);
	void dfs(int);
	void bcc(int);//基于dfs的双连通分量分解算法
	Stack<Tv> *tSort(int);//基于dfs的拓扑排序算法
	void prim(int);//最小生成树prim算法
	void dijkstra(int);//最短路径dijkstra算法
	template <typename PU> void pfs(int,PU);//优先级搜索框架 
}; 

#include "Vector.h"
//顶点类
template <typename Tv>
struct Vertex{
	Tv data;
	int inDegree,outDegree;
	VStatus status;
	int dTime,fTime;
	int parent;
	int priority;
	Vertex(Tv const& d=(Tv)0):data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),
	dTime(-1),fTime(-1),parent(-1),priority(INT_MAX){
		//暂不考虑权重溢出 
	}
};

//边类
template <typename Te>
struct Edge{
	Te data;
	int weight;
	EStatus status;
	Edge(Te const& d,int w):data(d),weight(w),status(UNDETERMINED){
		
	}
}; 

//邻接矩阵
template <typename Tv,typename Te>
class GraphMatrix:public Graph<Tv,Te>{
private:
	Vector<VerTex<Tv> > V;//顶点集（向量）
	Vector<Vector<Edge<Te>*> > E;//边集（邻接矩阵） 
public:
	GraphMatrix(){
		n=e=0;
	} 
	~GraphMatrix(){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				delete E[j][k];
			}
		}
	}
		// 顶点的基本操作：查询第i个顶点（0 <= i < n）
	 virtual Tv& vertex(int i) { return V[i].data; } //数据
	 virtual int inDegree(int i) { return V[i].inDegree; } //入度
	 virtual int outDegree(int i) { return V[i].outDegree; } //出度
	 virtual int firstNbr(int i) { return nextNbr(i, n); } //首个邻接顶点
	 virtual int nextNbr(int i, int j) //，已经枚举至j，相对于顶点j的下一邻接顶点
	 { while ((-1 < j) && (!exists(i, --j))); return j; } //逆向线性试探（改用邻接表可提高效率）
	 virtual VStatus& status(int i) { return V[i].status; } //状态
	 virtual int& dTime(int i) { return V[i].dTime; } //时间标签dTime
	 virtual int& fTime(int i) { return V[i].fTime; } //时间标签fTime
	 virtual int& parent(int i) { return V[i].parent; } //在遍历树中癿父亲
	 virtual int& priority(int i) { return V[i].priority; } //在遍历树中癿优先级数
	 // 顶点的动态操作
	 virtual int insert(Tv const& vertex) { //插入顶点，返回编号
	 	for (int j = 0; j < n; j++) 
		 	E[j].insert(NULL); 
		n++; //各顶点预留一条潜在的关联边
	 	E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL)); //创建新顶点对应的边向量
	 	return V.insert(Vertex<Tv>(vertex)); //创建一个新顶点并在顶点向量增加一个顶点
	 }
	 //顶点i的删除操作 
	 virtual Tv remove(int i) { 
	 	for (int j = 0; j < n; j++) //所有入边
	 		if (exists(i, j)) { delete E[i][j]; V[j].inDegree--; } //，存在边就逐条初除
	 	E.remove(i); n--; //初除第i行
	 	for (int j = 0; j < n; j++) //所有出边
	 		if (exists(j, i)) { delete E[j].remove(i); V[j].outDegree--; } //逐条初除
	 	Tv vBak = vertex(i); V.remove(i); //初除顶点i
	 	return vBak; //迒返被删除顶点的信息
	 }
	 // 边的确认操作
	 virtual bool exists(int i, int j) //边(i, j)是否存在
	 { return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL; }
	 // 边的基本操作：查询顶点i与j之间的联边（0 <= i, j < n且exists(i, j)）
	 virtual EStatus& status(int i, int j) { return E[i][j]->status; } //边(i, j)的状态
	 virtual Te& edge(int i, int j) { return E[i][j]->data; } //边(i, j)的数据
	 virtual int& weight(int i, int j) { return E[i][j]->weight; } //边(i, j)癿权重
	 // 边的动态操作
	 virtual void insert(Te const& edge, int w, int i, int j) { //揑入权重为w癿边e = (i, j)
	 	if (exists(i, j)) return; //确保边不存在 
	 	E[i][j] = new Edge<Te>(edge, w); //创建新边
	 	e++; 
		V[i].outDegree++; 
		V[j].inDegree++; //更新边计数不兲联顶点癿度数
	 }
	 virtual Te remove(int i, int j) { //初除顶点i和j乀间癿联边（exists(i, j)）
	 	Te eBak = edge(i, j); 
		delete E[i][j]; 
		E[i][j] = NULL; //备仹后初除边记弽
	 	e--; 
		V[i].outDegree--; 
		V[j].inDegree--; //更新边计数不兲联顶点癿度数
	 	return eBak; //迒回被初除边癿信息
	 }
}; 

//单个连通域的bfs 
template <typename Tv,typename Te>
void Graph<Tv,Te>::BFS(int v,int &clock){
	Queue<int> Q;
	status(v)=DISCOVERED;
	Q.enqueue(v);
	while(!Q.empty()){
		int v=Q.dequeue();
		dTime(V)=++clock;
		for(int u=firstNbr(v);-1<u;u=nextNbr(v,u)){
			/*试u的状态，分别处理*/
			if(UNDISCOVERD==status(u)){//若u尚未被发现，则发现该顶点 
				status(u)=DISCOVERED;
				Q.enqueue(u);
				status(v,u)=TREE;
				parent(u)=v; 
			}
			else{//若被发现已经在队列中，或者已经访问完毕出队列 
				status(v,u)=CROSS;//将(v,u)归于跨边 
			}
			status(v)=VISITED;
		}
	}
}
//全图的bfs
template <typename Tv,typename Te>
void Graph<Tv,Te>::bfs(int s){
	reset();
	int clock=0;
	int v=s;
	do{
		if(UNDISCOVERED==status(v))
			BFS(v,clock);
	}while(s!=(v=(++v%n)));//按序号检查 
} 

template <typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int &clock){
	dTime(v)=++clock;
	status(v)=DISCOVERED;
	for(int u=firstNbr(v),-1<u;u=nextNbr(v,u)){
		/*视u的状态分别处理*/
		switch(status(u)){
			case UNDISCOVERED:
				status(v,u)=TREE;
				parent(u)=v;
				DFS(u,clock);
				break;
			case DISCOVERED:
				status(v,u)=BACKWORD;
				break;
			default:
				status(v,u)=dTime(v)<dTime(u)?FORWARD:CROSS;
				break;
		}
		
		/*与bfs不同，含有递归*/
		status(v)=VISITED;
		fTime(v)= ++clock;
	}
} 
