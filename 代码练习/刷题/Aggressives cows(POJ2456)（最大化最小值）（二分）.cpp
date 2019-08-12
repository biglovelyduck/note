/*题意：在一位坐标上给N个点，将M头牛放在N个点中的M个点上使M头牛之间的最小距离最大。
解题思路：将M头牛放在N个点中的C个点上的最大距离是：dis=(Pmax-Pmin)/(C-1).
（最大的坐标-最小的坐标在除以M-1）。然后以dis为上限0为下限进行二分搜索。
一道不错的二分+贪心的题，对二分应用有更好的理解。
此题便是以奶牛之间的距离作为二分对象，做题一定要考虑全面，分析清楚。*/
//类似的最大化最小值，最小化最大值的问题，通常用二分搜索就可以很好的解决
//定义：C(d):可以安排牛的位置使得最近的两头牛的距离不小于d
//求解满足C(d)的最大的d 
//也就是：C(d):可以安排牛的位置使得任意的牛的间距都不小于d

//输入 
int N,M;
int x[MAX_N];//牛舍的位置 
//判断是否满足条件
bool C(int d){
	int last=0;//上一头牛的位置  
	for(int i=1;i<M;i++){//i从1开始表示已经有一头牛放在原点了 
		int crt=last+1;//暂时存放牛的位置 ，试探 
		while(crt<N&&x[crt]-x[last]<d) crt++;//必须大于等于d 
		if(crt==N) return false; 
		last=crt;
 	}
 	return true;
} 

void solve(){
	sort(x,x+N);
	int lb=0,ub=INF;
	while(ub-lb>1){
		int mid=(lb+ub)/2;//不停的寻找合适的d
		if(C(mid)) lb=mid;
		else ub=mid; 
	}
	cout<<lb;
}

