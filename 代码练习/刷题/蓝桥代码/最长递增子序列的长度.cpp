#include <iostream>
#include <algorithm>
using namespace std;
/*动态规划表*/
int dp[5] = {};
int main(){
int arr[11] = {2,4,5,6,7,8,9,10,4,4,1};
dp[0] = 1;
const int oo = 0;
for (int i = 1;i<11;i++){//i从第二个数开始
int _max = oo;//保存最长递增子序列长度
for (int j=0;j<i;j++)//j比i小
if(dp[j]>_max&&arr[i]>arr[j]){
_max = dp[j];
dp[i] = _max+1;
}
}
int maxlist=0;
for (int i = 0; i < 11;i++)
if (dp[i] > maxlist)
maxlist=dp[i];
cout << maxlist << endl;
}
