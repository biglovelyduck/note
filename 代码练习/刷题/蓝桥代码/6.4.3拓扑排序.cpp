#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1000;
int c[maxn];
int G[maxn][maxn];
int topo[maxn],t,n;
int dfs(int u){//u是该结点的位置 
	c[u]=-1;//正在深搜该位置
	for(int v=0;v<n;v++){
		//判断不合法性 
		if(G[u][v]){
			if(c[v]==-1) return false;//有向环
			else if(!c[v]&&!dfs(v)) return false; 
		}
		c[u]=1;
		topo[t--]=u;
		return true;
	} 
}
bool toposort(){
	t=n;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		if(!c[i]&&!dfs(i)) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			scanf("%d",&G[j][k]);
		}
	}
	if(toposort())
	    for(int i=n;i>0;i--){
	    	printf("%d ",topo[i]);
		}
		cout<<endl; 
	return 0;
} 
