//3.永远不可能到达的地方 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
//采用邻接矩阵画图
const int MAX_N=101; 
bool visited[MAX_N];
int d[MAX_N][MAX_N];
int n,m,u,v,s,e;
vector<int> sta;
set<int> ss;
void DFS(int start,int end)//深搜入栈查询所有路径
{
	visited[start] = true;//visited数组存储各定点的遍历情况，true为已遍历（标记）
	sta.push_back(start);//入栈
	for (int j = 1; j <=n; j++) {
		if (start== end) {//找到终点
			for(auto i:sta) ss.insert(i);
			sta.pop_back();//出栈
			visited[start] = false;
			break;
		}
		if (!visited[j]&&d[start][j]!=-1) {//该顶点未被访问过
			DFS(j,end);
		}
		if (j == n ) {//如果该顶点无其它出度
		    sta.pop_back();
		    visited[start] = false;
		}
	}
}

bool dfs(int start,int end){
	visited[start]=true;
	if(start==end) return true;
	for(int i=0;i<=n;i++){
		if(d[start][i]!=-1&&!visited[i]){
			return dfs(i,end);
		}
	}
	return false;	
}
int main(){
	memset(visited,false,sizeof(visited));
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		d[u][v]=1;
		d[v][u]=1;
	}
	cin>>s>>e;
	DFS(s,e);
	//for(auto i:ss) cout<<i<<endl;
	set<int> res;
	for(int i=1;i<=n;i++){
		if(!ss.count(i)) res.insert(i);
	}
	if(res.empty()) return 0;
	for(auto i:res) cout<<i<<" ";
	return 0;
}
