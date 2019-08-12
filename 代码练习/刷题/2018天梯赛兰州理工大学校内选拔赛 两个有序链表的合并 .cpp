//2018天梯赛兰州理工大学校内选拔赛 两个有序链表的合并 
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
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
int main(){
	int n;
	vector<int> v1,v2;
	while(cin>>n&&n!=-1){
		v1.push_back(n);
	}
	while(cin>>n&&n!=-1){
		v2.push_back(n);
	}
	for(int i=0;i<v2.size();i++){
		v1.push_back(v2[i]);
	}
	sort(v1.begin(),v1.end());
	if(v1.size()==0) cout<<"NULL";
	else{
		for(int i=0;i<v1.size();i++){
			if(i==(v1.size()-1)) cout<<v1[i];
			else cout<<v1[i]<<" ";
		}
	}
	return 0;
}
