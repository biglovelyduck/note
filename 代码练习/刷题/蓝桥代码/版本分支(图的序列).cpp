#include <iostream>
#include <vector>
using namespace std;
int n,q,ts=0;
vector<int> g[100001];
int d[100001],f[100001];//d[i]��ʾi����˵㣬f[i]��ʾi���Ҷ˵� 
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
	for(int i=2;i<=n;i++){//������n-1�� 
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);//u��v�ĸ���� 
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
