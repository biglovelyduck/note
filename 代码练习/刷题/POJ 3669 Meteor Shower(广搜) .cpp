//POJ 3669 Meteor Shower(����) 
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX_M=50000;	//M������ 
const int MAX_N=400+1;	//
const int INF=100000000; 
//����
int M;
int X[MAX_M],Y[MAX_M],T[MAX_M];//����+ʱ��

int maze[MAX_N][MAX_N];//�����λ�����类Ϯ����ʱ�� 
int d[MAX_N][MAX_N]; //�������ʱ��

//4������
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

int bfs(){
	//һ��ʼ�ͱ�ը
	if(maze[0][0]==0) return -1; 
	
	queue<P> q;
	q.push(P(0,0));
	d[0][0]=0;
	while(!q.empty()){
		P p=q.front();
		q.pop();
		int x=p.first;
		int y=p.second;
		//�Ѿ����ﰲȫλ��
		if(maze[x][y]==INF) return d[x][y];
		//�ĸ�������
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			//�ж��Ƿ�����ƶ����Ƿ���ʹ����Լ���һ��ʱ���Ƿ�ȫ
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
	//ģ���ը����
	for(int i=0;i<M;i++){
		maze[X[i]][Y[i]]=min(maze[X[i]][Y[i]],T[i]);
		for(int d=0;d<4;d++){
			int nx=X[i]+dx[d];
			int ny=Y[i]+dy[d];
			if(nx>=0&&ny>=0)
				maze[nx][ny]=min(maze[nx][ny],T[i]);
		} 
	}
	//��ʼ����ͼ�����ʱ�䣨��С������
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
