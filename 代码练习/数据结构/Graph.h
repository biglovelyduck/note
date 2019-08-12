/*Graphͼģ��*/
#define INT_MAX 10000001
typedef enum{
	UNDISCOVERED,DISCOVERED,VISITED
}VStatus;//����״̬
typedef enum{
	UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD
}EStatus; //��״̬

template <typename Tv,typename Te>//�������ͣ�������
class Graph{
private:
	void reset(){//���ж��㣬�ߵĸ�����Ϣ��λ 
		for(int i=0;i<n;i++){
			status(i)=UNDISCOVERED;
			dTime(i)=fTime(i)=-1;//ʱ���ǩ״̬
			parent(i)=-1;
			priority(i)=INT_MAX;
			for(int j=0;j<n;j++){
				if(exists(i,j)) status(i,j)=UNDETERMINED;
			}
		}
	}
	void BFS(int,int&);//��ͨ�򣬹���
	void DFS(int,int&);
	void BCC(int,int&,Stack<int>&);
	bool TSort(int,int&,Stack<Tv>*);
	template <typename PU> void PFS(int,PU); 
public:
	int n;//��������
	int e;//������
	//����ӿ� 
	virtual int insert(Tv const&)=0;//���붥�㣬���ر��
	virtual Tv remove(int)=0;//ɾ�����㼰������ߣ����ظö�����Ϣ
	virtual Tv& vertex(int)=0;//����v�����ݣ��ö����ȷ���ڣ�
	virtual int inDegree(int)=0;//����v�����
	virtual int outDegree(int)=0;//����v�ĳ���
	virtual int firstNbr(int)=0;//����v���׸����Ӷ���
	virtual int nextNbr(int,int)=0;//����v����ڶ���j����һ���ڽӶ���
	virtual VStatus& status(int)=0;//����v��״̬
	virtual int& dTime(int)=0;//����v��ʱ���ǩdTime 
	virtual int& fTime(int)=0;//����v��ʱ���ǩfTime
	virtual int& parent(int)=0;//����v�ڱ������еĸ���
	virtual int& priority(int)=0;//����v�ڱ����������ȼ���
	
	//�߽ӿ�
	virtual bool exists(int,int)=0;//�ߣ�v,u���Ƿ����
	virtual void insert(Te const&,int,int,int)=0;//�ڶ���u��v֮�����Ȩ��Ϊw��e 
	virtual Te remove(int,int)=0;//ɾ��v��u֮��ı�e�������ظñ���Ϣ
	virtual EStatus& status(int,int)=0;//�ߣ�v,u����״̬
	virtual Te& edge(int,int)=0;//�ߣ�v,u��������
	virtual int& weight(int,int)=0;//��v,u��Ȩֵ
	
	//�㷨
	void bfs(int);
	void dfs(int);
	void bcc(int);//����dfs��˫��ͨ�����ֽ��㷨
	Stack<Tv> *tSort(int);//����dfs�����������㷨
	void prim(int);//��С������prim�㷨
	void dijkstra(int);//���·��dijkstra�㷨
	template <typename PU> void pfs(int,PU);//���ȼ�������� 
}; 

#include "Vector.h"
//������
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
		//�ݲ�����Ȩ����� 
	}
};

//����
template <typename Te>
struct Edge{
	Te data;
	int weight;
	EStatus status;
	Edge(Te const& d,int w):data(d),weight(w),status(UNDETERMINED){
		
	}
}; 

//�ڽӾ���
template <typename Tv,typename Te>
class GraphMatrix:public Graph<Tv,Te>{
private:
	Vector<VerTex<Tv> > V;//���㼯��������
	Vector<Vector<Edge<Te>*> > E;//�߼����ڽӾ��� 
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
		// ����Ļ�����������ѯ��i�����㣨0 <= i < n��
	 virtual Tv& vertex(int i) { return V[i].data; } //����
	 virtual int inDegree(int i) { return V[i].inDegree; } //���
	 virtual int outDegree(int i) { return V[i].outDegree; } //����
	 virtual int firstNbr(int i) { return nextNbr(i, n); } //�׸��ڽӶ���
	 virtual int nextNbr(int i, int j) //���Ѿ�ö����j������ڶ���j����һ�ڽӶ���
	 { while ((-1 < j) && (!exists(i, --j))); return j; } //����������̽�������ڽӱ�����Ч�ʣ�
	 virtual VStatus& status(int i) { return V[i].status; } //״̬
	 virtual int& dTime(int i) { return V[i].dTime; } //ʱ���ǩdTime
	 virtual int& fTime(int i) { return V[i].fTime; } //ʱ���ǩfTime
	 virtual int& parent(int i) { return V[i].parent; } //�ڱ������аm����
	 virtual int& priority(int i) { return V[i].priority; } //�ڱ������аm���ȼ���
	 // ����Ķ�̬����
	 virtual int insert(Tv const& vertex) { //���붥�㣬���ر��
	 	for (int j = 0; j < n; j++) 
		 	E[j].insert(NULL); 
		n++; //������Ԥ��һ��Ǳ�ڵĹ�����
	 	E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL)); //�����¶����Ӧ�ı�����
	 	return V.insert(Vertex<Tv>(vertex)); //����һ���¶��㲢�ڶ�����������һ������
	 }
	 //����i��ɾ������ 
	 virtual Tv remove(int i) { 
	 	for (int j = 0; j < n; j++) //�������
	 		if (exists(i, j)) { delete E[i][j]; V[j].inDegree--; } //�����ڱ߾���������
	 	E.remove(i); n--; //������i��
	 	for (int j = 0; j < n; j++) //���г���
	 		if (exists(j, i)) { delete E[j].remove(i); V[j].outDegree--; } //��������
	 	Tv vBak = vertex(i); V.remove(i); //��������i
	 	return vBak; //ކ����ɾ���������Ϣ
	 }
	 // �ߵ�ȷ�ϲ���
	 virtual bool exists(int i, int j) //��(i, j)�Ƿ����
	 { return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL; }
	 // �ߵĻ�����������ѯ����i��j֮������ߣ�0 <= i, j < n��exists(i, j)��
	 virtual EStatus& status(int i, int j) { return E[i][j]->status; } //��(i, j)��״̬
	 virtual Te& edge(int i, int j) { return E[i][j]->data; } //��(i, j)������
	 virtual int& weight(int i, int j) { return E[i][j]->weight; } //��(i, j)�mȨ��
	 // �ߵĶ�̬����
	 virtual void insert(Te const& edge, int w, int i, int j) { //�I��Ȩ��Ϊw�m��e = (i, j)
	 	if (exists(i, j)) return; //ȷ���߲����� 
	 	E[i][j] = new Edge<Te>(edge, w); //�����±�
	 	e++; 
		V[i].outDegree++; 
		V[j].inDegree++; //���±߼�������������m����
	 }
	 virtual Te remove(int i, int j) { //��������i��j�T��m���ߣ�exists(i, j)��
	 	Te eBak = edge(i, j); 
		delete E[i][j]; 
		E[i][j] = NULL; //����������߼Ǐ�
	 	e--; 
		V[i].outDegree--; 
		V[j].inDegree--; //���±߼�������������m����
	 	return eBak; //ކ�ر������߰m��Ϣ
	 }
}; 

//������ͨ���bfs 
template <typename Tv,typename Te>
void Graph<Tv,Te>::BFS(int v,int &clock){
	Queue<int> Q;
	status(v)=DISCOVERED;
	Q.enqueue(v);
	while(!Q.empty()){
		int v=Q.dequeue();
		dTime(V)=++clock;
		for(int u=firstNbr(v);-1<u;u=nextNbr(v,u)){
			/*��u��״̬���ֱ���*/
			if(UNDISCOVERD==status(u)){//��u��δ�����֣����ָö��� 
				status(u)=DISCOVERED;
				Q.enqueue(u);
				status(v,u)=TREE;
				parent(u)=v; 
			}
			else{//���������Ѿ��ڶ����У������Ѿ�������ϳ����� 
				status(v,u)=CROSS;//��(v,u)���ڿ�� 
			}
			status(v)=VISITED;
		}
	}
}
//ȫͼ��bfs
template <typename Tv,typename Te>
void Graph<Tv,Te>::bfs(int s){
	reset();
	int clock=0;
	int v=s;
	do{
		if(UNDISCOVERED==status(v))
			BFS(v,clock);
	}while(s!=(v=(++v%n)));//����ż�� 
} 

template <typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int &clock){
	dTime(v)=++clock;
	status(v)=DISCOVERED;
	for(int u=firstNbr(v),-1<u;u=nextNbr(v,u)){
		/*��u��״̬�ֱ���*/
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
		
		/*��bfs��ͬ�����еݹ�*/
		status(v)=VISITED;
		fTime(v)= ++clock;
	}
} 
