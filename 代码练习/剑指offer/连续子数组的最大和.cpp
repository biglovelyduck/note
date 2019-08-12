//连续子数组的最大和
#include <iostream>
using namespace std;
int FindMaxSumOfSubArray(int *a,int len){
	if(a==NULL||len<=0) return 0;
	int curSum=a[0];
	int curMax=~(1<<sizeof(int)*8)-1;
	for(int i=1;i<len;i++){
		if(curSum<=0)
			curSum=a[i];
		else
			curSum+=a[i];
		if(curSum>curMax)	curMax=curSum;
	}
	return curMax;
}
int main(){
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
//	for(int i=0;i<N;i++)
//		cout<<a[i];
	int max=FindMaxSumOfSubArray(a,N);
	cout<<max;
}
 
