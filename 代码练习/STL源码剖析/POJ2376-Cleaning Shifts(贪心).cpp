//POJ2376-Cleaning Shifts
//【题目大意】
//给出几个小区间和大区间，求覆盖整个大区间的最少小区间个数，如果不可能则输出-1。
/*题解：给定T个时间区间，区间范围[1,T]，不同牛有不同的工作时间，求至少多少头牛工作可以覆盖这个区间。
首先以牛开始工作的时间先后顺序排序，之后不断循环更新起点=终点+1，在开始工作时间能覆盖起点的牛中，
每次选出一头工作时间最晚的牛，更新终点   */
#include <iostream>
#include <algorithm>
using namespace std;
const int N_MAX=25000+1;
pair<int,int> cows[N_MAX];
int N,T;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return (a.first<b.first||(a.first==b.first&&a.second>b.second));
}
int solve(){
	int used_cows=0;
	int end=0,num=0;
	while(end<T){
		int begin=end+1;
		//此时的end是上一头牛的工作结束时间，此时的begin是当前牛的工作开始时间要在begin之前 
		for(int i=num;i<N;i++){//选出新的一头牛，使得工作时间结束的越晚越好 
			if(cows[i].first<=begin){
				if(cows[i].second>=begin)//有可能牛的工作时间只有一个
					end=max(end,cows[i].second); 
			}
			else{
				num=i;//没有符合要求的牛可以选了，换新牛 
				break;
			}
		}
		if(begin>end) return -1;
		else used_cows++; 
	}
	return used_cows;
}
int main(){
	cin>>N>>T;
	for(int i=0;i<N;i++){
		cin>>cows[i].first>>cows[i].second;
	}
	sort(cows,cows+N,cmp);
	cout<<solve();
	return 0;
}
