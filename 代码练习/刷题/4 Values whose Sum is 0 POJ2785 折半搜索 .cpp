//4 Values whose Sum is 0 POJ2785 折半搜索 
/*给定各有n 个整数的四个数列A、B、C、D。要从每个数列中各取出1 个数，使四个数的和为
0。求出这样的组合的个数。当一个数列中有多个相同的数字时，把它们作为不同的数字看待。
限制条件
. 1 ≤ n ≤ 4000
. |(数字的值)| ≤ 228s*/
/*思路：有时候，问题的规模较大，无法枚举所有元素的组合，但能够枚举一半元素的组合。此时，将问
题拆成两半后分别枚举，再合并它们的结果这一方法往往非常有效。*/
#include <iostream>
#include  <algorithm>
using namespace std;
const int MAX_N=4001;
int n;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N]; 
int CD[MAX_N*MAX_N];		//C和D中数字的组合方法 

void solve(){
	//枚举从C和D中取出数字的所有方法
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			CD[i*n+j]=C[i]+D[j];	//不同的组合方法 
		}
	} 
	sort(CD,CD+n*n);
	
	long long res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int cd=-(A[i]+B[j]);
			//取出C和D中和为cd的部分
			res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
		}
	}
	cout<<res<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];
	for(int i=0;i<n;i++)
		cin>>C[i];
	for(int i=0;i<n;i++)
		cin>>D[i];
	solve();
	return 0;
}
