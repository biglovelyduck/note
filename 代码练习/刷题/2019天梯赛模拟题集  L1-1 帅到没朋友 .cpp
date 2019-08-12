//2019天梯赛模拟题集  L1-1 帅到没朋友 
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
int n,k,m;
bool visited[100000]={false};
int a[100000]={0};
int main(){
	cin>>n;
	while(n--){
		cin>>k;
		int index;
		if(k==1)
			cin>>index;
		else{
			while(k--){
				cin>>index;
				a[index]=1;	
			}
		}
	}
	cin>>m;
	int chaxun;
	bool notone=true;
	vector<int> v; 
	while(m--){
		cin>>chaxun;
		if(a[chaxun]==0&&visited[chaxun]==false){
			visited[chaxun]=true;
			notone=false;
			v.push_back(chaxun);
		}
	}
	if(notone)
		cout<<"No one is handsome"<<endl;
	else{
		for(int i=0;i<v.size();i++){
			if(i==v.size()-1)
				printf("%05d",v[i]);
			else 
				printf("%05d ",v[i]);
		}
	}
	return 0;
} 
