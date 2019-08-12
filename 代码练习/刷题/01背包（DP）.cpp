/*01背包*/
/*最朴素的方法，试探放入*/
int n,W;//几个物品，总重W 输出最大价值res 
int w[MAX_N],v[MAX_N];//重量，价值 
int rec(int i,int j){//从第i个物品开始挑选总重小于j的部分 
	int res;
	if(i==n){
		//已经没有剩余物品
		res=0; 
	}
	else if(j<w[i]){
		//无法挑选这个物品 
		res=rec(i+1,j);//换下一种商品 
	}
	else{
		//可以挑选这种商品
		//选择该商品与不选择两种情况都要尝试
		res=max(rec(i+1,j-w[i])+v[i],rec(i+1,j)); 
	} 
	return res; //最大价值 
} 
void solve(){
	cout<<rec(0,W);
}

//因为每一层的搜索都会需要两次分支,当n比较大时就没办法解了，做个简单的优化
//因为rec(3,2) 被调用了两次,把第一次计算时的结果记录下来
int dp[MAX_N+1][MAX_N+1];//记忆化数组
int rec(int i,int j) {
	if(dp[i][j]>=0)//已经计算过直接使用之前的结果
		return dp[i][j];
	int res;
	if(i==n){
		//已经没有剩余物品
		res=0; 
	}
	else if(j<w[i]){
		//无法挑选这个物品 
		res=rec(i+1,j);//换下一种商品 
	}
	else{
		//可以挑选这种商品
		//选择该商品与不选择两种情况都要尝试
		res=max(rec(i+1,j-w[i])+v[i],rec(i+1,j)); 
	}
	//将结果记录在数组中 
	return dp[i][j]=res;  
}

//接下来，仔细研究,有如下递推式,d[i][j]表示从第i个物品开始挑选总重小于j时的V最大值 
//dp[n][j]=0;
//dp[i][j]={ dp[i+1][j] 	j<w[i]
//			{max(dp[i+1][j],dp[i+1][j-w[i]]+v[i])
//所以，不需要递归函数，简单二重循环即可解决
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

//各式各样的DP
//i循环正向进行，dp[i+1][j]:=从前i个物品中选出总重量不超过j的物品时总价值的最大值
//dp[0][j]=0
//dp[i+1][j]={dp[i][j]		j<w[i] 不去i
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

//此外 
