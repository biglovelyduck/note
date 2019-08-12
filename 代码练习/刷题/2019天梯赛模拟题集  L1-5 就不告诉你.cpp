//2019天梯赛模拟题集  L1-5 就不告诉你
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
	int a,b;
	cin>>a>>b;
	int result=a*b;
	vector<int> v;
	while(result){
		v.push_back(result%10);
		result/=10;
	}
	int flag=0;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		if(*it!=0||flag){
			flag=1;
			cout<<*it;
		}
	return 0;
}
