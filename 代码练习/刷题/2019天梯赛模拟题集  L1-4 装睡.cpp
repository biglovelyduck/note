//2019天梯赛模拟题集  L1-4 装睡 
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
int main(){
	int n;
	cin>>n;
	string name;
	int pl,mb;
	while(n--){
		cin>>name>>pl>>mb;
		if(pl<15||pl>20||mb<50||mb>70) cout<<name<<endl;
	}
	return 0;
}

