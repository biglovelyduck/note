/*��ȫ��������*/
//ÿ����Ʒ���������� 
//���ƹ�ϵ�� 
//dp[i+1][j]:=��ǰi����Ʒ��ѡ������������jʱ�ܼ�ֵ�����ֵ 
//dp[0][j]=0;
//dp[i+1][j]=max{dp[i][j-k*w[i]]+k*v[i]} 		k����������֪���Ƕ��� 
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

//���� ��Ϊ��dp[i+1][j]�ļ�����ѡ����Ʒi��k���������dp[i+1][j-w[i]]ѡ����Ʒi��k-1�������ͬ 
//����k���ֵ�����Ѿ���dp[i+1][j-w[i]]�ļ����������
//max{dp[i][j-k*w[i]]+k*v[i]}  k>=0
//=max(dp[i][j], max{dp[i][j-k*w[i]]+k*v[i]})  k>=1
//=max(dp[i][j],dp[i+1][j-w[i]]+v[i]) 
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=W;j++){
			if(j<w[i])	//��ѡ��Ʒi 
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);//����ͨ����i����+1 
		}
	}
	cout<<dp[n][W];
}

//���⣬01��������ȫ�������Բ����ظ�����һ��������ʵ��
//dp[W]:����i����Ʒ��ѡ������������W������ֵ 
//01����
int dp[MAX_W+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=W;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W];
}
//��ȫ����
int dp[MAX_W+1];
void solve(){
	for(int i=0;i<n;i++){
		for(int j=w[i];j<=W;j++){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W];
}
