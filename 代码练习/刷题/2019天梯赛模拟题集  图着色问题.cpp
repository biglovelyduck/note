//2019天梯赛模拟题集  图着色问题 
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)

const int MAX_V=501;
//采用邻接矩阵的递归实现
int V,E,K;
int m[MAX_V][MAX_V]={0};
bool visited[MAX_V]={false};
int a[MAX_V]={0};	//	a[i]表示顶点i的着色 ,a[0]不考虑 
bool flag=true;
bool DFS(int v){	//从顶点v开始深搜 
	visited[v]=true;
	for(int i=1;i<=V;i++){	//遍历顶点v相邻的各个顶点 
		if(!visited[i]&&m[v][i]){
			//cout<<"进入第一个if"<<endl;
			visited[i]=true;
			if(a[v]==a[i]){
				flag=false;
				//cout<<"跳出来啦"<<endl;
				break;
			}
			DFS(i);
		}
	}
	return flag; 
} 
int main(){
	cin>>V>>E>>K;
	for(int i=0;i<E;i++){
		int a,b;
		cin>>a>>b;
		m[a][b]=1;	m[b][a]=1;	//因为是无向图 
	} 
	int N;
	cin>>N;
	while(N--){
		set<int> s;
		for(int i=1;i<=V;i++){
			cin>>a[i];
			s.insert(a[i]);
		}
		//还得判断是不是k种颜色 
		if(s.size()<K||s.size()>K) cout<<"No"<<endl;
		else{
			if(DFS(1)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		flag=true;
		for(int i=1;i<=V;i++){
			a[i]=0;
			visited[i]=false;
		}
	} 
	return 0;
}

