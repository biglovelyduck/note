#include <iostream>
#include <cstido>
#include <vector>
#include <queue>
using namespace std;
struct Pos{
	int x,y;
}pos;
const int dir[4][2]{{-1,0},{1,0},{0,-1},{0,1}};
const int INF=999999;
char map[102][102];
int steps[102][102];
queue<Pos> q;
int sX,sY;//起点坐标 
bool isValid(int x,int y){
	return 0<=x&&y>=0&&x<n&&y<m&&(map[x][y]=='.'||map[x][y]=='S');
}
void BFS(int startX,int startY){
	pos.x=startX;
	pos.y=startY;
	q.push(pos);
	while(!q.empty()){
		Pos p=q.front();
		q.pop();
		for(int d=0;d<4;d++){
			int dx=p.x+dir[d][0];
			int dy=p.y+dir[d][1];
			if(isValid(dX,dY)&&steps[dX][dY]==INF) {
				//座位不能走，但是能够计算步数 
				steps[dX][dY]=steps[p.x][p.y]+1;
				if(map[dX][dY]!='S'){
					pos.x=dX;
					pos.y=dY;
					q.push(pos);
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			steps[i][j]=INF;
			if(map[i][j]=='H'){
				sX=i;
				sY=j;
				steps[i][j]=0;
			}
		}
	}
	BFS(sX,sY);
	int ans=INF;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='S'){
				//略懒得写了 
			}
		}
	} 
	return 0;
}
