//3.��Զ�����ܵ���ĵط� 
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
//�����ڽӾ���ͼ
const int MAX_N=101; 
bool visited[MAX_N];
int d[MAX_N][MAX_N];
int n,m,u,v,s,e;
vector<int> sta;
set<int> ss;
void DFS(int start,int end)//������ջ��ѯ����·��
{
	visited[start] = true;//visited����洢������ı��������trueΪ�ѱ�������ǣ�
	sta.push_back(start);//��ջ
	for (int j = 1; j <=n; j++) {
		if (start== end) {//�ҵ��յ�
			for(auto i:sta) ss.insert(i);
			sta.pop_back();//��ջ
			visited[start] = false;
			break;
		}
		if (!visited[j]&&d[start][j]!=-1) {//�ö���δ�����ʹ�
			DFS(j,end);
		}
		if (j == n ) {//����ö�������������
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
