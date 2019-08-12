//Subsequence poj3061 尺取法 
/*给定长度为n 的数列整数a0,a1,…,an.1 以及整数S。求出总和不小于S 的连续子序列的长度的
最小值。如果解不存在，则输出0。
限制条件
. 10 < n < 105
. 0 < ai ≤ 104
. S < 108*/
#include <bits/stdc++.h> 
using namespace std;
/* 普通做法 
const int MAX_N=100001;
int n,S,a[MAX_N];
int sum[MAX_N+1];
void solve(){
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+a[i];
	}
	if(sum[n]<S){
		cout<<0<<endl;
		return;
	}
	int res=n;
	for(int s=0;sum[s]+S<=sum[n];s++){
		//利用二分搜索求出t
		int t=lower_bound(sum+s,sum+n,sum[s]+S)-sum;
		res=min(res,t-s); 
	}
	cout<<res<<endl;
}
int main(){
	cin>>n>>S;
	for(int i=0;i<n;i++)
		cin>>a[i];
	solve();
	return 0;
}*/

//尺取法 
const int MAX_N=100001;
int n,S,a[MAX_N];
int sum[MAX_N+1];
void solve(){
	int res=n+1;
	int s=0,t=0,sum=0;
	for(;;){
		while(t<n&&sum<S){
			sum+=a[t++];
		}//sum>=S就跳出循环
		if(sum<S) break;
		res=min(res,t-s);
		sum-=a[s++]; 
	}
	if(res>n) res=0;
	cout<<res<<endl;
} 

int main(){
	cin>>n>>S;
	for(int i=0;i<n;i++)
		cin>>a[i];
	solve();
	return 0;
}
