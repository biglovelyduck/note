/*最长上升子序列*/
/*给出一个序列，求出这个序列最长的上升子序列的长度*/
/*限制条件：ai<=1000000*/
//递推关系
//a[i]:以ai为末尾的最长上升子序列的长度{1.只包含ai的子序列
//										{2.前面已经确定好的子序列追加ai
//dp[i]=max{1,dp[j]+1|j<i且a[j]<a[i]}
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX_N=101;
int n;
int a[MAX_N];
int dp[MAX_N];
void solve(){
	int res=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++) if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
//	while(n--){
//		cout<<"n="<<n<<" i="<<i<<endl;
//		cin>>a[i++];
//	}
	int k=0;
	while(n--){
		cout<<a[k++]<<endl;
	}
	solve();
	k=0;
	while(n--){
		cout<<a[k++]<<endl;
	}
	//cout<<max(1,2);
	return 0;
} 

//如果求得不同的子序列长度相同，那么最末尾元素较小的更有优势
//所以反过来针对长度相同的情况下最小的末尾元素求解
//dp[i]:=长度为i+1的上升子序列中末尾元素的最小值(不存在就INF) 
int dp[MAX_N];
void solve(){
	fill(dp,dp+n;INF);
	for(int i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i])=a[i];
	cout<<lower_bound(dp,dp+n,INF)-dp;//此刻dp保存的是每个末尾元素较小的子序列 
	}
}
