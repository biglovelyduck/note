//2018 天梯赛题集分享码  倒数第N个字符串 
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
	int L,N;
	cin>>L>>N;
	int old_L=L;
	int sum=1;
	for(int i=0;i<L;i++){
		sum*=26;
	}
	int index=sum-N;	//正数第几个位置
	stack<char> stack;
	if(index==0){
		while(L--)
			cout<<'a';	
	}
	else{
		while(index!=0){
			int ys=index%26;
			stack.push('a'+ys);
			index/=26;
		} 
		if(stack.size()<L){
			int len=(old_L-stack.size());
			while(len--)
				cout<<'a';
		}
	}
	while(!stack.empty()){
		cout<<stack.top();
		stack.pop();
	}
	return 0;
}
