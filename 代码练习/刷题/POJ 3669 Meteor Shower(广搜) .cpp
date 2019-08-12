//POJ 3669 Meteor Shower(广搜) 
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX_M=50000;	//M个流星 
const int MAX_N=400+1;	//
const int INF=100000000; 
//输入
int M;
int X[MAX_M],Y[MAX_M],T[MAX_M];//坐标+时间

int maze[MAX_N][MAX_N];//保存该位置最早被袭击的时间 
int d[MAX_N][MAX_N]; //保存最短时间

//4个方向
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

int bfs(){
	//一开始就被炸
	if(maze[0][0]==0) return -1; 
	
	queue<P> q;
	q.push(P(0,0));
	d[0][0]=0;
	while(!q.empty()){
		P p=q.front();
		q.pop();
		int x=p.first;
		int y=p.second;
		//已经到达安全位置
		if(maze[x][y]==INF) return d[x][y];
		//四个方向走
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			//判断是否可以移动，是否访问过，以及下一个时刻是否安全
			if(0 <= nx && 0 <= ny && d[nx][ny] == INF && d[x][y] + 1 < maze[nx][ny]){
				q.push(P(nx,ny));
				d[nx][ny]=d[x][y]+1;
			} 
		} 
	}
	return -1;
} 

void solve(){
	for(int i=0;i<MAX_N;i++){
		fill(maze[i],maze[i]+MAX_N,INF);//666 
	} 
	//模拟轰炸场景
	for(int i=0;i<M;i++){
		maze[X[i]][Y[i]]=min(maze[X[i]][Y[i]],T[i]);
		for(int d=0;d<4;d++){
			int nx=X[i]+dx[d];
			int ny=Y[i]+dy[d];
			if(nx>=0&&ny>=0)
				maze[nx][ny]=min(maze[nx][ny],T[i]);
		} 
	}
	//初始化地图的最短时间（最小步数）
	for(int i=0;i<MAX_N;i++)
		fill(d[i],d[i]+MAX_N,INF);
	cout<<bfs();
}

int main(){
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>X[i]>>Y[i]>>T[i];
	}
	solve();
	return 0;
}
