#include <iostream>
#include <unordered_map> 
using namespace std;
const int maxn=100000;
int n,k,a[maxn+1],s[maxn+1];
unordered_map<int,int> cnt;//哈希表实现，查找速度非常快 
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	s[0]=0;
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1]+a[i])%k;
		cnt[s[i]]++;
	}
	long long ans=0;
	for(int i=0;i<k;i++){
		ans+=(long long)(cnt[i]*(cnt[i]-1)/2);
	}
	cout<<ans<<endl;
	return 0;
}	
