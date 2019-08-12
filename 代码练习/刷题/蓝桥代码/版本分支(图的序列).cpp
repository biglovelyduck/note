#include <iostream>
#include <vector>
using namespace std;
int n,q,ts=0;
vector<int> g[100001];
int d[100001],f[100001];//d[i]表示i的左端点，f[i]表示i的右端点 
void dfs(int x){
	ts++;
	d[x]=ts;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		dfs(y);
	}
	ts++;
	f[x]=ts;
}
int main(){
	cin>>n>>q;
	for(int i=2;i<=n;i++){//接下来n-1行 
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);//u是v的父结点 
	}
	dfs(1);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(d[x]<=d[y]&&f[y]<=f[x]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
