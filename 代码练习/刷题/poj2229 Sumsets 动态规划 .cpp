//poj2229 Sumsets 动态规划 
/*题意：把n拆分为2的幂相加的形式，问有多少种拆分方法。

分析：dp，任何dp一定要注意各个状态来源不能有重复情况。根据奇偶分两种情况，
如果n是奇数则与n-1的情况相同。如果n是偶数则还可以分为两种情况，有1和没有1。
这样分可以保证两种情况没有重复，对于有1的情况可以直接拆出两个1（拆一个也行，
但变成奇数之后一定会拆另一个），然后变为n-2的情况。对于没有1的情况可以直接将其转化为n/2。
因为n拆分出所有的数字都是2的倍数。只需要将每种拆分结果中的数字都除以2就会与n/2的一种拆分相对应。
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 1000006
int ans[maxn];
int main(){
	//freopen("t.txt","r",stdin);
	int n;
	cin>>n;
	ans[1]=1;	//1的组合数为1
	for(int i=2;i<=n;i++){
		if(i&1)	//奇数
			ans[i]=ans[i-1]; 
		else{
			//偶数:有1的情况，没1的情况 
			ans[i]=ans[i-1]+ans[i/2];
			ans[i]=ans[i]%1000000000;
		}
	} 
	cout<<ans[n]<<endl;
}
