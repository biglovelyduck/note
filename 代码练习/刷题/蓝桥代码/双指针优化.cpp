#include <iostream> 
#include <algorithm>
using namespace std;
int n,k,ans;
int a[100000];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[n-1]-a[0]<k){
		cout<<"no solution"<<endl;
		return 0;
	}
	ans=a[n-1]-a[0];//初始化ans最大 
	for(int i=0,j=0;i<n;i++){
		while(j<n&&a[j]-a[i]<k) j++;
		if(a[j]-a[i]>=k&&a[j]-a[i]<ans){
			ans =a[j]-a[i];
		}
	}
	cout<<ans<<endl;
	return 0; 
} 
