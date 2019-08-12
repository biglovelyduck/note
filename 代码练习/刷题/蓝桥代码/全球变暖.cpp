#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int n;//n行n列 
string s[1000];//每行的字符串 
int mark[1000][1000];//坐标(i,j)是否被访问过 
int m;//连通分量的个数 
int ans=0;//解的个数 
int cnt[1000];//大陆对应的#个数 
int flood[1000];//大陆里与.相邻的#的个数 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x,int y,int m){
	mark[x][y]=m;
	cnt[m]++;
	bool flooded=false;
	for(int d=0;d<4;d++){
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(s[nx][ny]=='.') flooded=true;
		if(s[nx][ny]=='#'&&mark[nx][ny]==0){
			dfs(nx,ny,m);
		}
	}
	if(flooded) flood[m]++;
	
}

int main(){
	ifstream ifs("H:\\Test\\daoyu.txt");
	cin>>n; 
//	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		ifs>>s[i];
		cout<<s[i]<<endl;;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mark[i][j]=0;
		}
	}
	m=0;
	ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='#'&&mark[i][j]==0){
				m++;//是新大陆，m是大陆编号 
				cnt[m]=flood[m]=0;//初始化大陆 
				dfs(i,j,m);
				if(cnt[m]==flood[m]) ans++;
			}
		}
	} 
	cout<<ans<<endl;
	return 0;
}
