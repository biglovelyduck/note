//邻接表实现 
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[10001]; 
bool visited[10001];
int n,m;
void DFS(int x){
	visited[x]=true;
	for(int i:g[x]){
		if(!visited[i]) DFS(i);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) visited[i]=false;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(0); 
	bool ans=true;
	for(int i=0;i<n;i++) ans=ans&&visited[i];
	cout<<ans<<endl;
	return 0;
} 
