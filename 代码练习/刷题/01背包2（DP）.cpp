/*01背包2*/
/*有n个重量和价值分别为wi,vi的物品，从这些物品中挑选总重量不超过W的物品
求挑选方案中价值总和的最大值*/ 
//此前针对不同的重量限制计算出最大的价值
//现在针对不同的价值计算最小的重量
//限制条件，W变化范围较大
//d[i][j]:前i个物品中挑选出价值总和为j时总重量的最小值
int dp[MAX_N+1][MAX_N*MAX_V+1]
void solve(){
	fill(dp[0],dp[0]+MAX_N*MAX_V+1,INF);
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<MAX_N*MAX_V;j++){
			if(j<v[i])	dp[i+1][j]=dp[i][j]; 
			else
				dp[i+1][j]=min(dp[i][j],dp[i][j-w[i]]+w[i]);
		}
	}
	int res=0;
	for(int i=0;i<=MAX_N*MAX_V+1;i++) if(dp[n][i]<=W) res=i;
	cout<<res;
} 

