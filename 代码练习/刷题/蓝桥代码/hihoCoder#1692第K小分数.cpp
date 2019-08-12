//暂时不会 
#include <iostream>
using namespace std;
int n,k;//n个质数，第k小的分数 
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>p[i];//分母
	double l=0.0,r=1.0,m;
	while(true){
		m=(l+r)/2;//m是0-1区间的中间值 
		long long cnt=0,bestz=-1,bestm=-1;
		for(int i=0;i<n;i++){
			long long x=p[i]*m;
			cnt+=x;
			if(bestz==-1){
				
			}
		}
	} 
	return 0;
}
