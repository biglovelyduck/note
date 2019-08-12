//poj 2385 Apple Catching DP 
/*题目大意：有两棵苹果树，编号为1，2，每分钟有一棵树会掉落一个苹果。
一头牛在树下接苹果，每分钟只能站在一棵树下，但在树间转移的时间忽略不计。
给定最大的转移次数w，问这只牛最多能接住多少苹果?*/ 
/*分析：这道题用动态规划求解，关键问题是状态是什么？

　　  不妨按时间来思考，一给定时刻i，转移次数已知为j, 则它只能由两个状态转移而来。

　　  即上一时刻同一棵树或上一时刻不同的树

　　  则这一时刻在转移次数为j的情况下最多能接到的苹果为那两个状态的最大值再加上当前能接受到的苹果。
（注意当前能否拿到苹果只与转移次数有关）

　　 即

1 dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
2 if(j%2+1 == i) {
3     dp[i][j]++;
4 }
在0时刻，不管移动次数为几，接受的苹果都为0*/
/* 1 /*dp[t][w]
 2 
 3 dp[0][0..w] = 0;
 4 dp[i][0] = dp[i-1][0];
 5 dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
 6 if(j%2+1 == i) {		j为偶数，回到原地  j为奇数，移到下一棵树 
 7     dp[i][j]++;
 8 }*/
 
 #include <cstdio>
 #include <cstring>
 #include <iostream>
 using namespace std;
 int dp[1002][35];
 int apple[1002];
 int main(){
 	int t,w;	//时刻，移动次数 
 	cin>>t>>w;
 	for(int i=1;i<=t;i++)
		cin>>apple[i]; 	//从1时刻开始 
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=t;i++){
		for(int j=0;j<=w;j++){
			if(j==0){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
			}
			if(j%2+1==apple[i]){
				dp[i][j]++; 
			}
		}
	}
	int ans=dp[t][0];
	for(int j=1;j<=w;j++)
		if(ans<dp[t][j])
			ans=dp[t][j];
	cout<<ans<<endl;
 	return 0;
 }
