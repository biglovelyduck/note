#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char g[100][100];
int steps[100][100];
bool vis[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
struct Pos{
	int x,y;
}pos;
queue<Pos> q;
void bfs(int x,int y){
	vis[x][y]=true;
	pos.x=x;
	pos.y=y;
	q.push(pos);
	while(!q.empty()){
		Pos p=q.front();
		q.pop();
		x=p.x;
		y=p.y;
		for(int d=0;d<4;d++){
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]&&g[nx][ny]=='.'){	
				vis[nx][ny]=true;
				pos.x=nx;
				pos.y=ny;
				q.push(pos);
				steps[nx][ny]=steps[x][y]+1;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	memset(vis,false,sizeof(vis));
	steps[0][0]=0;
	bfs(0,0);
	cout<<steps[n-1][m-1];
	return 0;
}
