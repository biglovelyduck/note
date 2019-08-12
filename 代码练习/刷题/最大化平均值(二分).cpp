//有n个物品的重量和价值分别是wi和vi，从中取出k个物品使得单位重量的价值最大 
//1<=k<=n<=10^4
//1<=wi,vi<=10^6

//定义：条件C(x):可以选择使得单位重量的价值不小于x
//转换：求满足C(x)的最大x 
//所以 C(x)=((vi-x*wi)从大到小排列中的前k个的和不小于0

int n,k;
int w[MAX_N],v[MAX_N];

double y[MAX_N];//v-x*w

//判断是否满足条件
bool C(double x){
	for(int i=0;i<n;i++){
		y[i]=v[i]-x*w[i];
	}
	sort(y,y+n);
	//计算y数组中从大到小的前k个数的和
	double sum=0;
	for(int i=0;i<k;i++){
		sum+=y[n-1-i];
	} 
	return sum>=0;
} 

void solve(){
	double lb=0,ub=INF;
	for(int i=0;i<100;i++){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	cout<<ub;
}
