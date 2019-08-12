//2018 天梯赛题集分享码  分而治之 
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

int n,m,k,aa[10010]={0},a[10010];
void check(){
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	cin>>n>>m;
	vector<vector<int> > v(n+1);
	while(m--){
		int c1,c2;
		cin>>c1>>c2;
		aa[c1]++;
		aa[c2]++;
		v[c1].push_back(c2);	//存放兄弟城的编号 
		v[c2].push_back(c1);
	} 
	cin>>k;
	while(k--){
		int cnt,num;
		cin>>cnt;
		for(int i=1;i<=n;i++){
			a[i]=aa[i];
		}
		for(int i=0;i<cnt;i++){
			cin>>num;
			a[num]=0;	//表示每次工程后有多少兄弟城 
			for(int j=0;j<v[num].size();j++){
				a[v[num][j]]--;
			}
		}
		check();
	}
	return 0;
}
