//2019������ģ���⼯  ͼ��ɫ���� 
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
//�����ڽӾ���ĵݹ�ʵ��
int V,E,K;
int m[MAX_V][MAX_V]={0};
bool visited[MAX_V]={false};
int a[MAX_V]={0};	//	a[i]��ʾ����i����ɫ ,a[0]������ 
bool flag=true;
bool DFS(int v){	//�Ӷ���v��ʼ���� 
	visited[v]=true;
	for(int i=1;i<=V;i++){	//��������v���ڵĸ������� 
		if(!visited[i]&&m[v][i]){
			//cout<<"�����һ��if"<<endl;
			visited[i]=true;
			if(a[v]==a[i]){
				flag=false;
				//cout<<"��������"<<endl;
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
		m[a][b]=1;	m[b][a]=1;	//��Ϊ������ͼ 
	} 
	int N;
	cin>>N;
	while(N--){
		set<int> s;
		for(int i=1;i<=V;i++){
			cin>>a[i];
			s.insert(a[i]);
		}
		//�����ж��ǲ���k����ɫ 
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

