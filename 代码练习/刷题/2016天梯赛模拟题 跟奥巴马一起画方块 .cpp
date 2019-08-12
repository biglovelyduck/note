//2016天梯赛模拟题 跟奥巴马一起画方块 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int main(){
	int n;char c;
	cin>>n>>c;
	int h=(n&1)?n/2+1:n/2;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			cout<<c;
			if(j==n-1) cout<<endl;
		}
	}
	return 0;
} 
