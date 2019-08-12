#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,ka,ks;//行，列， 岛屿编号，面积不相等岛屿数量，不同形状岛屿数量 
char g[100][100];//保存整个图片 
bool vis[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> islands[1000];//保存每座岛屿的陆地标号序列 ，具体来说islands[i]这个vector里是第i座岛屿的陆地编号序列 

//返回陆地编号 
int has_func(int x,int y){
	return x*m+y;
}

//判断是否到达边界 
int inb(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
} 

//dfs岛屿上的所有陆地 
void dfs(int x,int y,vector<int>& island){
	vis[x][y]=true;
	island.push_back(has_func(x,y));
	for(int d=0;d<4;d++){
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(inb(nx,ny)&&!vis[nx][ny]&&g[nx][ny]=='#'){
			dfs(nx,ny,island);
		}
	}	
} 

//判断形状是否相同
bool shape_similar(vector<int>& islandi,vector<int>& islandj) {
	if(islandi.size()!=islandj.size()) return false;
	int d=islandi[0]-islandj[0];
	for(int i=1;i<islandi.size();i++){
		if(islandi[i]-islandj[i]!=d) return false;
	}
	return true;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>g[i];
	memset(vis,false,sizeof(vis));
	k=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(!vis[i][j]&&g[i][j]=='#'){
		islands[k].clear();
		dfs(i,j,islands[k]);//将k岛屿上所有的陆地添加到k里
		//k岛屿遍历完 
		sort(islands[k].begin(),islands[k].end());//按编号排序
		k++; 
	}
	ka=ks=0;
	for(int i=0;i<k;i++){
		bool fa=false,fs=false;
		for(int j=0;j<i;j++){
			if(islands[i].size()==islands[j].size()) fa=true;
			if(shape_similar(islands[i],islands[j])) fs=true;
		}
		if(!fa) ka++;
		if(!fs) ks++;
	}
	cout<<k<<' '<<ka<<' '<<ks<<endl; 
	return 0;
}
