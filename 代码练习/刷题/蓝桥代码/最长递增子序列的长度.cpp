#include <iostream>
#include <algorithm>
using namespace std;
/*��̬�滮��*/
int dp[5] = {};
int main(){
int arr[11] = {2,4,5,6,7,8,9,10,4,4,1};
dp[0] = 1;
const int oo = 0;
for (int i = 1;i<11;i++){//i�ӵڶ�������ʼ
int _max = oo;//��������������г���
for (int j=0;j<i;j++)//j��iС
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
