#include <iostream>
using namespace std;
int n,x,a[100000];
int binary_search(int a[],int n,int x){
	int l=0;
	int r=n-1;
	int ans=-1;
	//左必右开写法
	//这里必须等于 
	while(l<=r){
		int m=(1+r)/2;
		if(a[m]==x){
			ans=m;
			break;
		}
		if(a[m]<x) l=m+1;
		else r=m-1; 
	}
	return ans;
}
int main(){
	return 0;
}
