/*最长公共子序列*/
/*给出俩串，给出最长的公共子序列的长度*/ 
//dp[i][j]:s1...si和t1...tj对应的最长公共子序列长度 
//递推关系
//dp[i+1][j+1]={max(dp[i][j]+1,dp[i][j+1],dp[i+1][j])    si+1=tj+1
//				{max(dp[i][j+1],dp[i+1][j]				其他
int n,m;//输入，两个子序列的长度
char s[MAX_N],t[MAX_N];
int dp[MAX_N+1][MAXN+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i]==t[i])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	}
	cout<<dp[n][m];
}
