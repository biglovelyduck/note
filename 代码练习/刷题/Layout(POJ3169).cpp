//N头牛，编号1到N
//牛的性格倔强，所以有可能有多头牛挤在同一个位置
//给出ML个关系好的牛的信息(AL,BL,DL),表示AL和BL两头牛的最大距离DL 
//给出MD个关系不好的牛的信息(AD,BD,DD)，表示AD和BD两头牛的最小距离DD
//满足这些条件的排列中，求1号和N号牛的最大距离

//问题转化 第i号牛的位置是d[i] d[i]<=d[i+1]			变形：d[i+1]+0>=d[i] 
//对于关系好的牛之间的最大限制  d[AL]+DL>=d[BL]		变形： 
//对于关系不好的牛之间的最大限制 a[AD]+DD<=d[BD] 	变形：a[BD]+(-DD)>=d[AD]
//Bellman-Ford算法 
//输入
int N,ML,MD;
int AL[MAX_ML],BL[MAX_ML],DL[MAX_ML];
int AD[MAX_MD],BD[MAX_MD],DD[MAX_MD];
int d[MAX_N];//最短距离
void solve(){
	fill(d,d+N,INF);
	d[0]=0;
	for(int k=0;k<N;k++){
		//从i+1到i的权值为0
		for(int i=0;i+1<N;i++){
			if(d[i+1]<INF) d[i]=min(d[i],d[i+1]+0);
		} 
		//从AL到BL的权值为DL
		for(int i=0;i<ML;i++){
			if(d[AL[i]-1]<INF){
				d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
			}
		}
		//从BD到AD的权值为-DD
		for(int i=0;i<MD;i++){
			if(d[BD[i]-1]<INF){
				d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
			}
		}
		int res=d[N-1];
		if(d[0]<0){
			//存在负圈则误解
			res=-1; 
		} 
		else if(res==INF){
			res=-2;
		}
		cout<<res;
	}
} 
