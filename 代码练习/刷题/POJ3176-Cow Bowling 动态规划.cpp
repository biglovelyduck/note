//POJ3176-Cow Bowling
#include <iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(int i,int j){
	int n;
	while(cin>>n){
		int **arr=new int*[n+1];
		for(int i=0;i<=n;i++){
			arr[i]=new int[i+2];
			for(j=0;j<=i;j++){
				arr[i][j]=0;
			}
			if(i!=0)
				for(j=1;j<=i;j++)
					cin>>arr[i][j];
		}
		//dp
		int max_w=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j]);
				if(i==n&&max_w<arr[i][j]) max_w=arr[i][j];
			}
		}
		cout<<max_w<<endl;
		delete[] arr;
	}
	return 0;
} 
