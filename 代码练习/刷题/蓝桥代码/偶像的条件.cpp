#include <iostream>
#include <algorithm>
using namespace std;
int n,m,l;
const int maxn=100000;
int a[maxn+10],b[maxn+10],c[maxn+10];
long long ans;
void test(long long x,long long y,long long z){
	long long d=abs(x-y)+abs(y-z)+abs(z-x);
	if(d<ans) ans=d;
} 
int main(){
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=l;i++)
		cin>>c[i];
	a[0]=b[0]=c[0]=-100000000;
	a[n+1]=100000000;
	b[m+1]=100000000;
	c[l+1]=100000000;
	sort(a,a+n+1);
	sort(b,b+m+1);
	sort(c,c+l+1);
	ans=100000000000L;
	for(int i=1,j=0,k=0;i<=n;i++){
		while(b[j+1]<a[i]) j++;
		while(c[k+1]<a[i]) k++;
		test(a[i],b[j],c[k]);
		test(a[i],b[j],c[k+1]);
		test(a[i],b[j+1],c[k]);
		test(a[i],b[j+1],c[k+1]);
	}
	cout<<ans<<endl; 
	return 0;
}
