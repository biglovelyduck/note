/*���ز��ֺ�����
��n�в�ͬ��С������ai,ÿ�ָ�mi�����ж��ܷ�ȡ����ʹ�ú�ΪK 
*/
//���壺dp[i+1][j]=ǰi�������ܷ�Ӻͳ�j 
//���ƹ�ϵ:
//dp[i+1][j]=����ʹdp[i][j-k*ai]��k
//����
int n,K,a[MAX_N],m[MAX_N];//���еĳ��ȣ�Ŀ��ĺ�����ֵ������
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

//���͸��Ӷȣ�
//dp[i+1][j]=��ǰi�����Ӻ͵õ�jʱ�ĵ�i�������ʣ�����(���ܼӺ͵õ�i�����Ϊ-1)
//���ƹ�ϵ
//dp[i+1][j]={mi			dp[i][j]>=0
//			={-1			j<ai��dp[i+1][j-ai]<=0
//			={dp[i+1][j-ai]-1	����
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
