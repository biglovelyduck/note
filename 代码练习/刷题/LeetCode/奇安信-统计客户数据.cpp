//奇安信-统计客户数据
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
const int MAX_N=101; 

int main(){
	int n;
	vector<int> v; 
	cin>>n;
	int m;
	for(int i=0;i<n;i++){
		cin>>m;
		v.push_back(m);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int l,r,k;
		cin>>l>>r>>k;
		int count=0;
		for(int d=l;d<=r;d++){
			if(v[d-1]==k) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
