//二分查找，判断一个解是否可行
//有N条绳子，长度分别为Li,如果从中切割出K条长度相同的绳子，求每条最长?
//1<=N,K<10000    1<=Li<=100000 
//C(x)=(floor(Li/x)的总和是否大于或者等于K)

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
using namespace std;
const int MAX_N=10000+1;
int INF;
int N,K;
double L[MAX_N];
//判断每条长度x是否满足条件
bool C(double x){
	int num=0;
	for(int i=0;i<N;i++){
		num+=(int)(L[i]/x);
	}
	return num>=K;
} 

void solve(){
	//初始化解的范围
	double lb=0,ub=INF;
	//重复循环，直到解的范围足够小
	for(int i=0;i<100;i++){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	cout<<floor(ub*100)/100;
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>L[i];
	}
	sort(L,L+N);
	INF=L[N-1];
	solve();
	return 0;
}
