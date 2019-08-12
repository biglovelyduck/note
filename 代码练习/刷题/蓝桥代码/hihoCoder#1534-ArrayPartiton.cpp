#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,a[100001];
long long s[100001],ans=0;
unordered_map<long long,int> cnt;
int main(){
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++){//1-n 
		cin>>a[i];
		s[i]=s[i-1]+a[i];//a[i]有正有负，同一个前缀和的值可能会重复 
		if(i<n) cnt[s[i]]++;
	}
	long long s3=0;
	for(int q=n-1;q>=2;q--){
		s3+=a[q+1];
		cnt[s[q]]--;
		for(long long s1=s3-1;s1<=s3+1;s1++){
			long long s2=s[n]-s1-s3;
			if(abs(s1-s2)<=1&&abs(s2-s3)<=1) ans+=cnt[s1];
		}
	}
	cout<<ans;
	return 0;
}
