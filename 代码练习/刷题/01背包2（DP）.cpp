/*01����2*/
/*��n�������ͼ�ֵ�ֱ�Ϊwi,vi����Ʒ������Щ��Ʒ����ѡ������������W����Ʒ
����ѡ�����м�ֵ�ܺ͵����ֵ*/ 
//��ǰ��Բ�ͬ���������Ƽ�������ļ�ֵ
//������Բ�ͬ�ļ�ֵ������С������
//����������W�仯��Χ�ϴ�
//d[i][j]:ǰi����Ʒ����ѡ����ֵ�ܺ�Ϊjʱ����������Сֵ
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

