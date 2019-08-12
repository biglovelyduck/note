//ccf2018-03 跳一跳 
#include <iostream>
using namespace std;
const int N=30;
int a[N];
int ans=0;
int main(){
	int n,i=0;
	while(cin>>n&&n!=0){
		a[i++]=n;
	}
	int b=0;	//表示连续跳到中心的次数 
	for(int j=0;j<i;j++){
		if(j==0){
			if(a[j]==1)	ans+=1;
			else{
				b++;
				ans+=2;
			}
		}
		else{
			if(a[j]==1){
				b=0;
				ans+=1;
			}
			else{
				if(a[j-1]==1){
					b++;
					ans+=2;
				}
				else{
					b++;
					ans+=2*b;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
