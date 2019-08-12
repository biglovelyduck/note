//POJ 3268 Silver Cow Party
/*奶牛派对：有分别来自 N 个农场的 N 头牛去农场 X 嗨皮，农场间由 M 条有向路径连接。每头牛来回都挑最短的路走，求它们走的路的最大长度？

2.5 它们其实都是“图”

最短路 dijkstra 解决任意两点最短路的变种

用warshall_floyd的话会TLE，10003复杂度果然不是盖的，另外X的编号记得减一，测试用例很恶心的，
即使忘了减一也照样得出正确答案10，但是一提交就WA，让我深深地感到了来自命题者的恶意：*/

//warshall_floyd超时
/* 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 1024
int d[MAX_V][MAX_V];
int V;
void warshall_floyd(){
	for(int k=0;k<V;++k)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
	//freopen("in.txt","r",stdin)
	//freopen("out.txt","w",stdout);
	int M,X;
	cin>>V>>M>>X;
	--X;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<V;i++){
		d[i][i]=0;
	}
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;
		--B;
		d[A][B]=T;
	}
	warshall_floyd();
	int ans=0;
	for(int i=0;i<V;i++)
		ans=max(ans,d[i][X]+d[X][i]);
	cout<<ans<<endl;
}
*/
//普通的dijkstra是解决单源最短路问题的，稍微修改一下就可以支持任意两点最短路：
//邻接表实现 
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
#define MAX_V 1024
//从顶点from指向to权值为cost的边
struct edge{
	int to,cost;
	edge(){
	}
	edge(int to,int cost):to(to),cost(cost){
	}
}; 
typedef pair<int,int> P;	//first是最短路径，second是顶点编号
vector<edge> G[MAX_V] ;	//图 

int d[MAX_V][MAX_V];	//最短距离
int V,E;	//顶点数，边数
void dijkstra(int s){	//从顶点s出发到所有点的最短距离 
	priority_queue<P,vector<P>,greater<P> > que;
	memset(d[s],0x3f,MAX_V*sizeof(int));
	d[s][s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[s][v]<p.first) continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];	//与顶点v相邻的边 
			if(d[s][e.to]>d[s][v]+e.cost){
				d[s][e.to]=d[s][v]+e.cost;
				que.push(P(d[s][e.to],e.to));
			}
		}
	}
} 
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int M,X;
	cin>>V>>M>>X;
	--X;
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;
		--B;
		G[A].push_back(edge(B,T));
	}
	for(int i=0;i<V;i++)
		dijkstra(i);	//修改的dijkstra，能够求得任意两点最短路径
	int ans=0;
	for(int i=0;i<V;i++){
		if(i==X)	continue;
		ans=max(ans,d[i][X]+d[X][i]);
	} 
	cout<<ans<<endl;
	return 0;
}
*/
//邻接矩阵实现
/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_V=1024;
int cost[MAX_V][MAX_V];	//表示边cost[u][v]的权值
int d[MAX_V];
bool used[MAX_V];	//已经使用过的点
int V; 
void dijkstra(int s){
	d[s]=0;
	while(true){
		int v=-1;	//跳出循环的变量
		//从尚未使用过的结点里选出一个距离最小的点
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;//v保存最小距离的点
		} 
		if(v==-1) break; //结束
        used[v]=true;//v已经确定
        for(int u=0;u<V;u++){//再次遍历所有的点
            d[u]=min(d[u],d[v]+cost[v][u]);//更新
        }
	}
}
int main(){
	int M,X;
	cin>>V>>M>>X;
	--X;
	for(int i=0;i<V;i++)
		used[i]=false;
	memset(d,0x3f,sizeof(d));
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;--B;
		cost[A][B]=T;
	} 
 
	return 0;
} */

/*不过上面那个实在太浪费，我只想计算起点或终点是X的路径最短路问题，可以在上面
while (!que.empty())的循环里加入判断条件，还可以这么玩：

来一个反向图，交换边的起点和终点得到反向的有向图，两次dijkstra解决问题：*/
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX_V 10240
 
// 从顶点from指向顶点to的权值为cost的边
struct edge
{
	int to, cost;
	edge(){}
	edge(int to, int cost) : to(to), cost(cost){}
};
 
// first 最短路径，second顶点编号
typedef pair<int, int> P;
 
// 图
vector<vector<edge> > G(MAX_V);
// 反向图
vector<vector<edge> > RG(MAX_V);
 
// 最短距离
int d[MAX_V];
int rd[MAX_V];
// V是顶点数，E是边数
int V, E;
 
// 求解从顶点s出发到所有点的最短距离
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	que.push(P(0, s));
 
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int M, X;
	cin >> V >> M >> X;
	--X;
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		--A;
		--B;
		G[A].push_back(edge(B, T));
		RG[B].push_back(edge(A, T));
	}
	dijkstra(X);
	G = RG;
	memcpy(rd, d, sizeof(d));
	dijkstra(X);
	for (int i = 0; i < V; ++i)
	{
		d[i] += rd[i];
	}
 
	cout << *max_element(d, d + V) << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
