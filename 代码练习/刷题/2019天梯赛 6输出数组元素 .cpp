//2019天梯赛 6输出数组元素 
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
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int len=0;
	for(int i=1;i<n;i++){
		len++;
		if(len==3){
			len=0;
			cout<<a[i]-a[i-1]<<endl;
		}
		else cout<<a[i]-a[i-1]<<" ";
	}
	return 0;
} 
