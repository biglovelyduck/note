/*完全背包问题*/
//每种物品的数量无限 
//递推关系： 
//dp[i+1][j]:=从前i种物品挑选总重量不超过j时总价值的最大值 
//dp[0][j]=0;
//dp[i+1][j]=max{dp[i][j-k*w[i]]+k*v[i]} 		k是数量，不知道是多少 
int dp[MAX_N+1][MAX_W+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=W;j++){
			if(0==i) dp[i][j]=0;
			for(int k=0;k*w[i]<=j;k++){
				dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*w[i]]+k*v[i]);
			}
		}
	}
	cout<<dp[n][W]; 
} 

//变形 因为在dp[i+1][j]的计算中选择物品i的k个的情况和dp[i+1][j-w[i]]选择物品i的k-1个情况相同 
//所以k部分的情况已经在dp[i+1][j-w[i]]的计算中完成了
//max{dp[i][j-k*w[i]]+k*v[i]}  k>=0
//=max(dp[i][j], max{dp[i][j-k*w[i]]+k*v[i]})  k>=1
//=max(dp[i][j],dp[i+1][j-w[i]]+v[i]) 
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=W;j++){
			if(j<w[i])	//不选物品i 
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);//比普通背包i多了+1 
		}
	}
	cout<<dp[n][W];
}

//此外，01背包和完全背包可以不断重复利用一个数组来实现
//dp[W]:从这i种物品挑选出重量不超过W的最大价值 
//01背包
int dp[MAX_W+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=W;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W];
}
//完全背包
int dp[MAX_W+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=w[i];j<=W;j++){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W];
}
