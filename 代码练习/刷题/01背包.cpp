//01背包
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N=100;
int n,W;
int w[MAX_N],v[MAX_N];	//重量和价值
//最朴素的，针对每个物品是否放入背包进行搜索 ，求价值最大化 
int rec(int i,int j){			//从第i个物品开始挑选总重小于等于j的最大价值 
	int res;
	if(i==n)	res=0;
	else if(j<w[i])
		res=rec(i+1,j);			//不能挑选这个物品 
	else						//可以挑选这个物品，选与不选 
		res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
	return res;
}
//记忆数组优化
int dp[MAX_N+1][MAX_N+1];
int rec1(int i,int j){			//从第i个物品开始挑选总重小于等于j的最大价值 
	if(dp[i][j]>=0)	return dp[i][j];
	int res;
	if(i==n)	res=0;
	else if(j<w[i])
		res=rec(i+1,j);			//不能挑选这个物品 
	else						//可以挑选这个物品，选与不选 
		res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
	return dp[i][j]=res;
}
//写法简化
void solve(){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=W;j++){
			if(j<w[i])	dp[i][j]=dp[i+1][j];
			else	dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[0][W];
} 
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<4;i++)	cin>>w[i]>>v[i];
	cin>>W;
	//cout<<rec(0,W);
	solve();
	return 0;
}
