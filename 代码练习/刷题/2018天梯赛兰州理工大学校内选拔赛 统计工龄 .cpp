//2018天梯赛兰州理工大学校内选拔赛 统计工龄 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>v[i];
		s.insert(v[i]);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<":"<<count(v.begin(),v.end(),*it)<<endl;
	}
	return 0;
}
