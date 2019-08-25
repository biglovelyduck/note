//数组子数组的最大值 
#include <iostream>
using namespace std;
int getMaxSum(int a[],int len){
	int maxSum=0;
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=a[i];
		if(maxSum<sum)	maxSum=sum;
		else if(sum<0)	sum=0;
	}
	return maxSum;
}
int main(){
	int n;
	//int a[n];	//鬼他妈知道这是多大，错误！ 
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	cout<<getMaxSum(a,n);
	return 0;
} 
