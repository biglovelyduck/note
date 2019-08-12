//Face The Right Way Poj3276 反转 
/*N 头牛排成了一列。每头牛或者向前或者向后。为了让所有的牛都面向前方，农夫约翰买了
一台自动转向的机器。这个机器在购买时就必须设定一个数值K，机器每操作一次恰好使K
头连续的牛转向。请求出为了让所有的牛都能面向前方需要的最少的操作次数M 和对应的
最小的K。
限制条件
. 1≤N≤5000*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=5001;
int N;
int dir[MAX_N];	//牛的方向0：F  1：B
int f[MAX_N];	//区间[i,i+K-1]是否进行了反转

//固定K，求解最小的操作回数
//无解返回-1
int calc(int K){
	memset(f,0,sizeof(f));
	int res=0;	//反转的次数 
	int sum=0;	//对于在区间内包含位置i的所有f的和
	for(int i=0;i+K<=N;i++){
		//计算区间[i,i+K-1]
		if((dir[i]+sum)%2!=0){
			//前端的牛面朝后方
			res++;
			f[i]=1; 
		} 
		sum+=f[i];
		if(i-K+1>=0){
			//端点到头了，重新设定sum的值，就是取消开头端点的反转的影响
			sum-=f[i-K+1]; 
		}
	} 
	
	//检查剩下的牛是否有面朝后方的情况，剩下N-K+1头牛
	for(int i=N-K+1;i<N;i++){
		if((dir[i]+sum)&1!=0)
			//无解，有面朝后面的牛
			return -1;
		if(i-K+1>=0)
			sum-=f[i-K+1]; 
	}
	return res; 
} 

void solve(){
	int K=1,M=N;
	for(int k=1;k<N;k++){
		int m=calc(k);
		if(m>=0&&m<M){	//是最小的次数，就保存K 
			M=m;K=k;
		}
	}
	cout<<K<<" "<<M<<endl;
}

int main(){
	cin>>N;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='F') dir[i]=0;
		else dir[i]=1;
	}
	solve();
	return 0;
}
