//某街区共有R条道路，N个接口，道路可以双向通行。
//问1号路口到N号的次短路长度是多少
//同一条边可以经过多次
//1<=N<=5000;
//1<=R<=100000 
//到v的次短路径：要么是到u的最短路径+u->v的边
//				要么是到u的次短路径+u->v的边
const int INF=100000;
struct edge{
	int to,cost;
};
int N,R;
vector<edge> G[MAX_N];//图的邻接表
int dist[MAX_N];
int dist2[MAX_N];
typedef pair<int,int> P;//first是最短距离，second是顶点编号
void solve(){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dist,dist+N;INF);
	fill(dist2,dist2+N;INF);
	dist[1]=0;
	que.push(P(0,1));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.second,d=p.first;//最短距离的点和这个点的最短距离
		////如果次短路径都小于d 那么就不用再继续去更新
		if(dist2[v]<d) continue;//次短路径已经确定，舍弃当前点到该点所认为的最短路径 
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			//到e.to的假设次短距离 是到v的最距离 + e.cost
			int d2=d+e.cost;
			if(dist[e.to]>d2){//如果次短路小于最短路 交换最短路和次短路
				swap(dist[e.to],d2);
				que.push(P(dist[e.to],e.to));
			}
			if(dist2[e.to]>d2&&dist[e.to]<d2){//如果可以更新次短路
				dist2[e.to]=d2;
				que.push(P(dist2[e.to],e.to));
				//这两句if 体现次短路 要么是到达其他某个顶点的最短路
				//加上u->v这条边，要么是到u的次短路再加上u->v这条边
			}
		} 
	}
	cout<<dist2[N-1];
} 
