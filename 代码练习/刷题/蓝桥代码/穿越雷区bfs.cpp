#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;
struct Pos{
	int x,y;
}pos;
int n,x_A,y_A,x_B,y_B;//n行n列  ，A，B的坐标
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<Pos> q; 
char map[100][100];
int steps[100][100];//从A开始到每个位置的最短长度
bool vis[100][100]={false};
bool inMap(int x,int y){
	return x>=0&&y>=0&&x<n&&y<n;
}
void bfs(){
	pos.x=x_A;
	pos.y=y_A;
//	cout<<"x_A:"<<pos.x<<"y_A:"<<pos.y<<endl;;
	q.push(pos);
	vis[x_A][y_A]=true;
	steps[x_A][y_A]=0;
	while(!q.empty()){
		Pos p=q.front();
		q.pop();
		for(int d=0;d<4;d++){
			int nx=p.x+dir[d][0];
			int ny=p.y+dir[d][1];
			if(inMap(nx,ny)&&!vis[nx][ny]&&map[p.x][p.y]!=map[nx][ny]){
				steps[nx][ny]=steps[p.x][p.y]+1;
				vis[nx][ny]=true;
				pos.x=nx;
				pos.y=ny;
				q.push(pos);
			}
		}
	}
}
int main(){
	cin>>n;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cin>>map[i][j];
//			if(map[i][j]=='A'){
//				x_A=i;
//				y_A=j;
//			}
//			if(map[i][j]=='B'){
//				x_B=i;
//				x_B=j;
//			}
//		}
//	}
	ifstream ifs("H:\\Test\\tank.txt");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ifs.get(map[i][j]);
		}
		ifs.get();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='A'){
				x_A=i;
				y_A=j;
			}
			if(map[i][j]=='B'){
				x_B=i;
				y_B=j;
			}
		}
		cout<<endl;
	}
	cout<<x_A<<" "<<y_A<<endl;
	cout<<x_B<<" "<<y_B<<endl;
	x_B=4;y_B=0; 
	bfs();
	if(!vis[x_B][y_B]) cout<<-1<<endl;
	else cout<<steps[x_B][y_B]<<endl; 
	return 0;
}
