//超大背包问题 折半搜索 
/*有重量和价值分别为wi,vi 的n 个物品。从这些物品中挑选总重量不超过W 的物品，求所有
挑选方案中价值总和的最大值。
限制条件
. 1 ≤ n ≤ 40
. 1 ≤ wi,vi ≤ 1015
. 1 ≤ W ≤ 1015*/
/* 
#include <iostream>
#include <algorithm> 
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 40
#define INF  0x3fffffff 
typedef long long ll; 
int n;					//n个物品 
ll w[MAX_N],v[MAX_N];	//wi,vi
ll W;					//不超过总重W
pair<ll,ll> ps[1<<(MAX_N/2)];	//(重量，价值) 2^20

void solve(){
	//枚举前半部分
	int n2=n/2;			//一半的物品 
	for(int i=0;i<(1<<n2);i++){	//i<5,i存储各种组合的结果 
		ll sw=0,sv=0;
		for(int j=0;j<n2;j++){
			if((i>>j)&1){		//判断要不要j这个位置的物品 
				sw+=w[j];
				sv+=v[j];
			} 
		} 
		ps[i]=make_pair(sw,sv);			//各种组合组成的各种不同的重量和对应的不同的价值， 
	} 
	//去除多余的元素
	sort(ps,ps+(1<<n2));	//先排序,按照总重量从小到大 
	int m=1;
	for(int i=1;i<(1<<n2);i++){
		if(ps[m-1].second<ps[i].second)	//应该优先选择重量小并且价值大的选择 
			ps[m++]=ps[i];
	}  
	//前m个元素都是存储着某个重量最优的价值 
	//枚举后半部分并且求解
	ll res=0;
	for(int i=0;i<(1<<(n-n2));i++){
		ll sw=0,sv=0;
		for(int j=0;j<n-n2;j++){
			if((i>>j)&1){
				sw+=w[n2+j];	//枚举后半部分的各种选择 
				sv+=v[n2+j];
			}
		}
		if(sw<=W){
			//W-sw是前半部分需要的重量 
			ll tv=(lower_bound(ps,ps+m,make_pair(W-sw,INF))-1)->second;
			res=max(res,sv+tv);
		} 
	}
	printf("%lld\n",res);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
		cin>>v[i];
	cin>>W;
	solve();
	return 0;
}*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50;
const long long INF = 0x3fffffff;
typedef long long LL;
int n;
LL w[N], v[N];
LL W;
pair <LL, LL> pi[1 << (N / 2)];
 
void solve() {
    int n2 = n / 2;
    for(int i = 0; i < (1 << n2); i++) {
        LL sw = 0, sv = 0;
        for(int j = 0; j < n2; j++) {
            if((i >> j) & 1) {
                sw += w[j];
                sv += v[j];
            }
        }
        pi[i] = make_pair(sw, sv);
    }
 
    sort(pi, pi + (1 << n2));
    int m = 1;
    for(int i = 1; i < (1 << n2); i++) {
        if(pi[m-1].second < pi[i].second) {
            pi[m++] = pi[i];
        }
    }
 
    LL res = 0;
    for(int i = 0; i < (1 << (n - n2)); i++) {
        LL sw = 0, sv = 0;
        for(int j = 0; j < n - n2; j++) {
            if((i >> j) & 1) {
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }
        if(sw <= W) {
            LL tv = (lower_bound(pi, pi + m, make_pair(W - sw, INF)) - 1)->second;
            res = max(res, sv + tv);
        }
    }
    printf("%lld\n", res);
}
 
int main() {
    while(~scanf("%d%lld", &n, &W)) {
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld", &w[i], &v[i]);
        }
        solve();
    }
    return 0;
}

