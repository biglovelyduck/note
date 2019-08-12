#include <iostream>
#include <algorithm> 
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int l=0,r=-1;
	long long ans=0;
	for(int i=0;i<n;i++){
		while(l<n&&a[l]*8<a[i]+64) l++;
		while(r+1<n&&a[r+1]<=a[i]*8*8
			&&(a[i]>=88888||a[r+1]<=88888)) r++;
		if(l<=r){
			ans=ans+(r-l+1);
			if(i>=1&&i<=r) ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
