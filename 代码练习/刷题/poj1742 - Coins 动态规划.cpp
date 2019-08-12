/*题目大意：有n种硬币，这n种硬币的价值为a[i]，第i种硬币的个数为c[i]个，问有多少种方案，
使这些硬币加起来等于m
这是一个很裸的多重背包可行性问题*/
//大神代码 
/*#include <iostream>
using namespace std;
#define MAXV 105
#define MAXM 100005
#include<iostream>
using namespace std;
#define MAXV 105
#define MAXM 100005
 
int weight[MAXV],c[MAXV],f[MAXM],user[MAXM];
 
int main(){
	int i,j,n,m,ans;
	while(scanf("%d%d",&n,&m) && n && m){	//n和m都不是0，以0 0退出循环 
		for(i=1;i<=n;i++)
			scanf("%d",&weight[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
 
		memset(f,0,sizeof(f));
		f[0]=1;ans=0;
		for(i=1;i<=n;i++){
			memset(user,0,sizeof(user));
			for(j=weight[i];j<=m;j++){
				if(!f[j] && f[j-weight[i]] && user[j-weight[i]]+1<=c[i]){
					f[j]=1;
					user[j]=user[j-weight[i]]+1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}*/

//基本思路 
/*dp[i][j] := 用前i种硬币能否凑成j

递推关系式：

dp[i][j] = （存在k使得dp[i – 1][j – k * A[i]]为真，0 <= k <= m 且下标合法）*/
/* 
#include <iostream>
#include <algorithm>
using namespace std;
 
bool dp[100 + 16][100000 + 16]; // dp[i][j] := 用前i种硬币能否凑成j
int A[100 + 16];
int C[100 + 16];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		dp[0][0] = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				for (int k = 0; k <= C[i] && k * A[i] <= j; ++k)
				{
					dp[i + 1][j] |= dp[i][j - k * A[i]];
				}
			}
		}
		int answer = count(dp[n] + 1, dp[n] + 1 + m , true); // 总额0不算在答案内
		cout << answer << endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}*/
/*这个算法每次只记录一个bool值，损失了不少信息。在这个问题中，不光能够求出是否能得到某个金额，
同时还能把得出了此金额时A_i还剩下多少个算出来，这样直接省掉了k那重循环。
优化dp定义：

dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个（-1表示配不出来）
            如果dp[i - 1][j] >= 0(前i-1个数可以凑出j，那么第i个数根本用不着)直接为C[i]
dp[i][j] =  如果j < A[i]或者dp[i][j - a[i]] <=0 (面额太大或者在配更小的数的时候就用光了）-1
            其他（将第i个数用掉一个） dp[i][j-a[i]] - 1
            最后统计一下dp数组第n行>=0的个数就知道答案了：
*/
/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int dp[100 + 16][100000 + 16]; // dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个
int A[100 + 16];
int C[100 + 16];
 
int main(int argc, char *argv[])
{

	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[i][j] >= 0)
				{
					dp[i + 1][j] = C[i];
				}
				else if (j < A[i]						// 用一个就超出，不能用
						|| dp[i + 1][j - A[i]] <= 0)		// 连凑比j小的数的时候都用完了，此时更加用完了
				{
					dp[i + 1][j] = -1;
				}
				else
				{
					dp[i + 1][j] = dp[i + 1][j - A[i]] - 1;		// 用上了一个第i个硬币
				}
			}
		}
		int answer = count_if(dp[n] + 1, dp[n] + 1 + m , bind2nd(greater_equal<int>(), 0)); // 总额0不算在答案内
		cout << answer << endl;
	}

    return 0;
}*/
/*
dp[j] := 在第i次循环时之前表示用前i-1种硬币凑成j时第i种硬币最多能剩余多少个（-1表示配不出来），循环之后就表示第i次的状态

于是就省了一维数组：*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int dp[100000 + 16]; // dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个
int A[100 + 16];
int C[100 + 16];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while(cin >> n >> m && n > 0)
	{
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> C[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (dp[j] >= 0)
				{
					dp[j] = C[i];
				}
				else if (j < A[i]						// 用一个就超出，不能用
						|| dp[j - A[i]] <= 0)		// 连凑比j小的数的时候都用完了，此时更加用完了
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - A[i]] - 1;		// 用上了一个第i个硬币
				}
			}
		}
		int answer = count_if(dp + 1, dp + 1 + m , bind2nd(greater_equal<int>(), 0)); // 总额0不算在答案内
		cout << answer << endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}
