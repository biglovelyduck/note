//给定一个0和1组成的矩阵，只允许交换相邻的两行，要把 他转换成下三角矩阵，最少需要交换几次 
//输入
int N;
int M[MAX_N][MAX_N];//矩阵
int a[MAX_N];//a[i]表示第i行最后出现1的位置1~n-1
void solve(){
	int res=0;
	for(int i=0;i<N;i++){
		a[i]=-1;//如果第i行不含1 就当做-1
		for(int j=0;j<N;j++){
			if(M[i][j]==1) a[i]=j;
		} 
	}
	for(int i=0;i<N;i++){
		int pos=-1;//要移动到第i行的行
		for(int j=i;j<N;j++){
			if(a[j]<=i){//遍历每行最后一个1出现的位置 
				pos=j;//保存要移动到第i行的行号 
				break;
			}
		}
		//完成交换
		for(int j=pos;j>i;j--){//i永远是较小的，因为是从第一行还是遍历 
			swap(a[j],a[j-1]);
			res++; 
		} 
	}
} 
