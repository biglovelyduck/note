//�������������·���⣬������������DP���
//ֻʹ�ö���0-k,i,j������£���i��j�����·����Ϊd[k+1][i][j]
//k=-1ʱ����Ϊֻʹ��i��j������d[0][i][j]=cost[i][j]
//����������ֻʹ��0-k�������Լ��ֻʹ��0-k-1������ 
int dp[MAX_V][MAX_V];//d[u][v]��ʾ��e={u,v}��Ȩֵ��������ΪINF,d[i][i]=0
int V; 
void warshall_floyd(){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
} 
 
