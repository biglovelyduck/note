/*�����������*/
/*����������������Ĺ��������еĳ���*/ 
//dp[i][j]:s1...si��t1...tj��Ӧ������������г��� 
//���ƹ�ϵ
//dp[i+1][j+1]={max(dp[i][j]+1,dp[i][j+1],dp[i+1][j])    si+1=tj+1
//				{max(dp[i][j+1],dp[i+1][j]				����
int n,m;//���룬���������еĳ���
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
