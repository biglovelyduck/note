//任意两点间的最短路问题，让我们试着用DP求解
//只使用顶点0-k,i,j的情况下，记i到j的最短路长度为d[k+1][i][j]
//k=-1时，认为只使用i和j，所以d[0][i][j]=cost[i][j]
//接下来，把只使用0-k的问题归约到只使用0-k-1的问题 
int dp[MAX_V][MAX_V];//d[u][v]表示边e={u,v}的权值，不存在为INF,d[i][i]=0
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
 
