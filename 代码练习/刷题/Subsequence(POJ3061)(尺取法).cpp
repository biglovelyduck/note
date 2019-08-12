//给定长度为n 的数列整数a0,a1,…,an.1 以及整数S。求出总和不小于S 的连续子序列的长度的
//最小值。如果解不存在，则输出0。(所有元素都>0) 
//10 < n < 105
// 0 < ai < 104
// S < 10^8
/*尺取法通常是指对数组保存一对下标（起点、终点），然后根据实际情况交替推进
两个端点直到得出答案的方法，这种操作很像是尺蠖（日文中称为尺取虫）爬行的方式故得名。*/

/*由于所有的元素都大于零，如果子序列[s, t)满足as+…+at.1≥S，那么对于任何的t<t'一定有as+…
+at'.1≥S。此外对于区间[s,t)上的总和来说如果令
sum(i)=a0+a1+…+ai.1
那么
as+as+1+…+at.1=sum(t).sum(s)
因此预先以O(n)的时间计算好sum的话，就可以以O(1)的时间计算区间上的总和。这样一来，子
序列的起点s确定以后，便可以用二分搜索快速地确定使序列和不小于S的结尾t的最小值。*/

int n,S;
int a[MAX_N];
int sum[MAX_N+1];
void solve(){
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+a[i];//前i项的和 
	}
	if(sum[n]<S){
		cout<<0<<endl;
		return;
	}
	int res=n;
	for(int s=0;sum[s]+S<=sum[n];s++){//依次确定起点s 
		//二分搜索求出区间终点t
		int t=lower_bound(sum+s,sum+n,sum[s]+S)-sum;
		res=min(res,t-s); 
	}
	cout<<res;
}

//优化，复杂度O（n) 
void solve(){
	int res=n+1;
	int s=0,t=0,sum=0;
	for(;;){
		while(t<n&&sum<S){
			sum+=a[t++];	//当sum大于S时就跳出 
		}
		if(sum<S) break;
		res=min(res,t-s);
		sum-=a[s++]; 
	}
	if(res>n) res=0;
	cout<<res; 
}

//像这样反复地推进区间的开头和末尾，来求取满足条件的最小区间的方法被称为尺取法。
