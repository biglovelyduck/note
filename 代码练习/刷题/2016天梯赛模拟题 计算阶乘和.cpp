//2019天梯赛模拟题 计算阶乘和
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int jiecheng(int N){
	if(N==1) return 1;
	return N*jiecheng(N-1);
}
int main(){
	int N;
	cin>>N;
	int sum=0;
	for(int i=1;i<=N;i++)
		sum+=jiecheng(i);
	cout<<sum<<endl;
	return 0;
}
