//2019天梯赛模拟题集  天梯地图  
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
/*分析：用两个Dijkstra + DFS。一个求最快路径（如果相同求路径的那条），
一个求最短路径（如果相同求结点数最小的那条）～～求最快路径可以直接在Dijkstra里
面求前驱结点Timepre数组~~~求最短路径因为要求结点数最小的那条，所以要用dispre的
二维数组存储所有结点的最短路径，然后用DFS求出满足条件的结点数最小的那条～～*/
int dis[510],Time[510];	//最短距离，最短时间
int e[510][510],w[510][510];	//顶点u和v花费的距离，时间 ,邻接矩阵存储 
int Timepre[510],weight[510];	//最快路径前驱结点数组，到达顶点i所用的最短路径 
bool visit[510];
vector<int> Timepath,dispath,temppath,dispre[510];
int st,fin,minnode=inf;

void dfsTimepath(int v){
	Timepath.push_back(v);
	if(v==st) return;
	dfsTimepath(Timepre[v]);
} 

void dfsdispath(int v){
	temppath.push_back(v);
	if(v==st){
		if(temppath.size()<minnode){
			minnode=temppath.size();
			dispath=temppath;
		}
		temppath.pop_back();
		return;
	}
	for(int i=0;i<dispre[v].size();i++)		//dispre[v]可能有多个顶点 
		dfsdispath(dispre[v][i]);
	temppath.pop_back();
}

int main(){
	fill(dis,dis+510,inf);	//初始化都是最大距离
	fill(Time,Time+510,inf);	//初始化都是最大时间 
	fill(weight,weight+510,inf);
	fill(e[0],e[0]+510*510,inf);
	fill(w[0],w[0]+510*510,inf);
	int n,m;	//顶点个数，道路数
	cin>>n>>m;
	int a,b,flag,len,t;
	for(int i=0;i<m;i++){
		cin>>a>>b>>flag>>len>>t;	//顶点a->b 是否是单向边  长度   时间
		e[a][b]=len; 
		w[a][b]=t;
		if(flag!=1){	//双向边 
			e[b][a]=len;
			w[b][a]=t;
		} 
		cin>>st>>fin;	//起点和终点的编号 
	}
	
	Time[st]=0;	//起点的时间为0
	for(int i=0;i<n;i++){
		//顶点编号 0-N-1
		Timepre[i]=i; 	//初始化都等于自身 
	}
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;	//minn保存从当前点出发到相邻点的最短时间 
		for(int j=0;j<n;j++){
			if(!visit[j]&&Time[j]<minn){
				u=j;	//保存最短时间确定的点 
				minn=Time[j];
			}
		}
		if(u==-1) break;
		visit[u]=true;	//u点已经确定ok
		//去更新前面的点 
		for(int v=0;v<n;v++){
			if(visit[v]==false&&w[u][v]!=inf){
				if(w[u][v]+Time[u]<Time[v]){
					Time[v]=Time[u]+w[u][v];
					Timepre[v]=u;	//保存前一个最短时间的点
					weight[v]=weight[u]+e[u][v] ;
				}
				else if(w[u][v]+Time[u]==Time[v]&&weight[v]>weight[u]+e[u][v]){
					//更新最短路径啦
					weight[v]=weight[u]+e[u][v];
					Timepre[v]=u; 
				}
			}
		} 
	} 
	//已经确定好所有的最短时间的点了
	dfsTimepath(fin); 	//参数是终点 
	
	//开始计算最短路径
	fill(visit,visit+510,false);
	dis[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<minn){
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1) break;	//每次都找到最优点
		//根据最优点松弛周围
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v]&&e[u][v]!=inf){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];
					dispre[v].clear();
					dispre[v].push_back(u);
				}
				else if(dis[u]+e[u][v]==dis[v]){
					dispre[v].push_back(u);
				}
			}
		} 
	} 
	dfsdispath(fin);
	
	cout<<"Time = "<<Time[fin];
	if(dispath==Timepath)	//最短路和最快路重合 
		cout<<"; Distance = "<<dis[fin]<<": ";
	else{
		cout<<": ";
		for(int i=Timepath.size()-1;i>=0;i--){
			cout<<Timepath[i];
			if(i!=0) cout<<" =>";
		}
		cout<<endl;
		cout<<"Distance = "<<dis[fin]<<": ";
	}
	for(int i=dispath.size()-1;i>=0;i--){
		cout<<dispath[i];
		if(i!=0) cout<<" =>";
	}
	return 0;
}
