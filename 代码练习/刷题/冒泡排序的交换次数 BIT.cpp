//冒泡排序的交换次数 BIT
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MAX_N=1000;
int n=4;
int a[4]={3,1,2,4};
//BIT
int bit[MAX_N+1];
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}i
}
void solve(){
	ll ans=0;
	for(int j=0;j<n;j++){
		ans+=j-sum(a[j]);
		
		add(a[j],1);

	}
	cout<<ans<<endl;
}
int main(){
	solve();
	return 0;
} 
