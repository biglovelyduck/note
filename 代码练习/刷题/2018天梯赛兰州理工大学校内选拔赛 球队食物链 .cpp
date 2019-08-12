//2018天梯赛兰州理工大学校内选拔赛 球队食物链 
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
int n;
char a[22][22];
bool visited[22]={false};
vector<int> v;
void dfs(int i){
	if(v.size()==4){
		v.push_back(i+1);
		return;
	}
	for(int j=0;j<n;j++){
		if(a[i][j]=='W'&&visited[j]==false){
			visited[i]=true;
			v.push_back(i+1);
			dfs(j);
		} 
		else{
			j++;
		} 
	}
}
int main(){
	cin>>n;
	getchar();
	memset(a,0,sizeof(a));
	//n*n
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);
	if(v.size()==0) cout<<"No Solution"<<endl;
	else{
		for(int i=0;i<v.size();i++){
		if(i==v.size()-1) cout<<v[i];
		else cout<<v[i]<<" ";	
	}	
	}	
	return 0;
} 
