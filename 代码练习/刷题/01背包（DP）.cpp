/*01����*/
/*�����صķ�������̽����*/
int n,W;//������Ʒ������W �������ֵres 
int w[MAX_N],v[MAX_N];//��������ֵ 
int rec(int i,int j){//�ӵ�i����Ʒ��ʼ��ѡ����С��j�Ĳ��� 
	int res;
	if(i==n){
		//�Ѿ�û��ʣ����Ʒ
		res=0; 
	}
	else if(j<w[i]){
		//�޷���ѡ�����Ʒ 
		res=rec(i+1,j);//����һ����Ʒ 
	}
	else{
		//������ѡ������Ʒ
		//ѡ�����Ʒ�벻ѡ�����������Ҫ����
		res=max(rec(i+1,j-w[i])+v[i],rec(i+1,j)); 
	} 
	return res; //����ֵ 
} 
void solve(){
	cout<<rec(0,W);
}

//��Ϊÿһ�������������Ҫ���η�֧,��n�Ƚϴ�ʱ��û�취���ˣ������򵥵��Ż�
//��Ϊrec(3,2) ������������,�ѵ�һ�μ���ʱ�Ľ����¼����
int dp[MAX_N+1][MAX_N+1];//���仯����
int rec(int i,int j) {
	if(dp[i][j]>=0)//�Ѿ������ֱ��ʹ��֮ǰ�Ľ��
		return dp[i][j];
	int res;
	if(i==n){
		//�Ѿ�û��ʣ����Ʒ
		res=0; 
	}
	else if(j<w[i]){
		//�޷���ѡ�����Ʒ 
		res=rec(i+1,j);//����һ����Ʒ 
	}
	else{
		//������ѡ������Ʒ
		//ѡ�����Ʒ�벻ѡ�����������Ҫ����
		res=max(rec(i+1,j-w[i])+v[i],rec(i+1,j)); 
	}
	//�������¼�������� 
	return dp[i][j]=res;  
}

//����������ϸ�о�,�����µ���ʽ,d[i][j]��ʾ�ӵ�i����Ʒ��ʼ��ѡ����С��jʱ��V���ֵ 
//dp[n][j]=0;
//dp[i][j]={ dp[i+1][j] 	j<w[i]
//			{max(dp[i+1][j],dp[i+1][j-w[i]]+v[i])
//���ԣ�����Ҫ�ݹ麯�����򵥶���ѭ�����ɽ��
int dp[MAX_N][MAX_N];
void solve(){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=W;j++){
			if(j<w[i])
				dp[i][j]=d[i+1][j];
			else
				dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[0][W];
}	

//��ʽ������DP
//iѭ��������У�dp[i+1][j]:=��ǰi����Ʒ��ѡ��������������j����Ʒʱ�ܼ�ֵ�����ֵ
//dp[0][j]=0
//dp[i+1][j]={dp[i][j]		j<w[i] ��ȥi
//			{max(dp[i][j],dp[i][j-w[i]]+v[i])
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=W;j++){
			if(j<w[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
		}
	}
	cout<<dp[n][W];
} 

//���� 
