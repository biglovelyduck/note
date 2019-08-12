#include <iostream>
using namespace std;
int n,k;//n���ɿ�����k��С���� 
int h[100010],w[100010];
bool ok(int m){//mΪ�ɿ����ı߳� ,�ܷ��и�� 
	long long c=0;
	for(int i=0;i<n;i++){
		c+=(long long)(h[i]/m)*(w[i]/m);
	} 
	if(c>=k) return true;
	return false; 
} 
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>h[i]>>w[i];
	} 
	int ans=1;
	int l=1,r=n;
	while(l<=r){
		int m=l+(r-l)/2;
		if(ok(m)){
			ans=m;
			l=m+1;
		}
		else {
			r=m-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
