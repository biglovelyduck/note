//2018 天梯赛题集分享码  猜数字
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
	int N;
	cin>>N;
	string s;
	int num;
	map<string,int> m;
	int sum=0;
	for(int i=0;i<N;i++){
		cin>>s>>num;
		m[s]=num;
		sum+=num;
	}
	int av2=sum/N/2;
	int min_num=101;
	int min=101;
	map<string,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		if(abs(it->second-av2)<min){
			min=abs(it->second-av2);
			min_num=it->second;
		}
	} 
	for(it=m.begin();it!=m.end();it++){
		if(it->second==min_num){
			cout<<av2<<" "<<it->first;
			break;
		}
	}
	return 0;
}
