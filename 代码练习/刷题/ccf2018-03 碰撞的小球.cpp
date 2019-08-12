//ccf2018-03 碰撞的小球 
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=100+1;	//n,t
const int MAX_L=1000+1;	//L
int n,L,t;	//n个球,L长度，t时间 
int a[MAX_N],v[MAX_N];
typedef long long ll;	
int main(){
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>a[i];	//初始时n个小球的位置，a[i]的值位于0和L之间 
		v[i]=1;	//每个位置的速度
		if(a[i]==L) v[i]=-1; 
	}
	while(t--){
		for(int i=0;i<n;i++){	//遍历每个小球 
			a[i]+=v[i];
			for(int j=0;j<n&&j!=i;j++){
				if(a[i]==a[j]){
					v[i]=-v[i];
					v[j]=-v[j];
				}
			}
			if(a[i]==L||a[i]==0)
				v[i]=-v[i];
		}
	}
	for(int i=0;i<n;i++)	cout<<a[i]<<" ";
}
