//二分图判定
//给定一个具有n个顶点的图，给每个点染色，要求相邻顶点颜色不同，问能否最多用两种色
//保证无重边自环
//对图进行染色所需要的最小颜色数被称为最小着色数
//最小着色数是2的交二分图
#include <iostream>
vector <int> G[MAX_V];//图
int V; //顶点数
int color[MAX_V];//顶点i的颜色1或-1
//把顶点染成1或-1
bool dfs(int v,int c){
	color[v]=c;
	for(int i=0;i<G[v].size();i++){
		//如果相邻顶点同色，返回false
		if(color[G[v][i]]==c) return false;
		//如果相邻顶点还没被染色，则染成-c
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false; 
	}
	return true;//所有顶点都被染过色了 
} 

//可能是非连通图，就这样写 
void solve(){
	for(int i=0;i<V;i++){
		if(color[i]==0){
			//深搜染色并做个判断 
			if(!dfs(i,1)){
				cout<<"no";
				return;
			}
		}
	}
	cout<<"yes"; 
} 
