/*多重部分和问题
有n中不同大小的数字ai,每种个mi个，判断能否取若干使得和为K 
*/
//定义：dp[i+1][j]=前i中数字能否加和成j 
//递推关系:
//dp[i+1][j]=存在使dp[i][j-k*ai]的k
//输入
int n,K,a[MAX_N],m[MAX_N];//数列的长度，目标的和数，值，个数
bool dp[MAX_N+1][MAX_K+1];
void solve(){
	dp[0][0]=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<=K;j++){
			for(int k=0;k<=m[i]&&k*a[i]<=j;k++){
				dp[i+1][j]|=dp[i][j-k*a[i]];
			}
		}
	}
	if(dp[n][K]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
} 

//降低复杂度：
//dp[i+1][j]=用前i中数加和得到j时的第i种数最多剩余多少(不能加和得到i的情况为-1)
//递推关系
//dp[i+1][j]={mi			dp[i][j]>=0
//			={-1			j<ai或dp[i+1][j-ai]<=0
//			={dp[i+1][j-ai]-1	其他
int dp[MAX_K+1];
void solve(){
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=K;j++){
			if(dp[j]>=0)	dp[j]=m[i];
			else if(j<a[i]||dp[j-a[i]]<=0)
				dp[j]=-1;
			else
				dp[j]=dp[j-a[i]]-1;
		}
	}
	if(dp[K]>=0) cout<<"yes";
	else cout<<"no";
} 
