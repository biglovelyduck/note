/*单源最短路*/
//Dijkstra算法：适用于没有负边的情况 
//对Bellman-Ford算法做出修改
//1.找到最短距离已经确定的顶点，从他出发更新相邻顶点最短距离
//2.此后不需要关系1中的最短距离已经确定的顶点 

//使用邻接矩阵实现，复杂度O(V^2) 
const int MAX_V=10000;
int cost[MAX_V][MAX_V];//cost[u][v]表示边e={u,v}的权值，不存在这条边时为INF
//int d[MAX_V];//顶点s出发的最短距离
bool used[MAX_V];//已经使用过的图
//int V;//顶点数
/*
void dijkstra1(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);//初始化
	d[s]=0; 
	while(true){
		int v=-1;
		//从尚未使用过的顶点中选择一个距离最小的顶点v
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
		}
		if(v==-1) break;
		used[v]=true;//表示v已经确定了 
		for(int u=0;u<V;u++){
			d[u]=min(d[u],d[v]+cost[v][u]);//会更新u的相邻顶点的d，但可能并不是最小距离
			//但总有一个点是最短的距离 
		} 
	}
} */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF=100000;

//使用priority_queue（堆）邻接表实现的
//复杂度:O(|E|log|V|) 
struct edge{
	int to,cost;
}; 
typedef pair<int,int> P;//first是最短距离，second是顶点编号
int V,E;
vector<edge> G[MAX_V];//邻接表 
int d[MAX_V];
void dijkstra2(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;//取出距离最小的顶点v 
		if(d[v]<p.first) continue;//如果该点已经确定最小了就舍弃 
		for(int i=0;i<G[v].size();i++){//该点的邻接点 
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
} 

int main(){
	int from,to,weight;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>from>>to>>weight;
		edge e;
		e.to=to;
		e.cost=weight;
		G[from].push_back(e);
	}
	dijkstra2(0);
	cout<<d[3]<<endl;
	return 0;
} 

