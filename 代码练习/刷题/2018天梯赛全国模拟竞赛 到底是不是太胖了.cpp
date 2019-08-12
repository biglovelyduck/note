//2018天梯赛全国模拟竞赛 到底是不是太胖了 
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
	int H,W;
	while(N--){
		cin>>H>>W;
		int B=(H-100)*0.9*2;
		if(abs(W-B)<B*0.1) cout<<"You are wan mei!"<<endl;
		else if(W-B>B*0.1||W-B==B*0.1) cout<<"You are tai pang le!"<<endl;
		else if(B-W>B*0.1||B-W==B*0.1) cout<<"You are tai shou le!"<<endl;
	}
	return 0;
}
