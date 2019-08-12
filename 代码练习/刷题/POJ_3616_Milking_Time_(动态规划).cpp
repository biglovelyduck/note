/*给奶牛挤奶,共m次可以挤,给出每次开始挤奶的时间st,结束挤奶的时间ed,还有挤奶的量ef,
每次挤完奶要休息r时间,问最大挤奶量.*/
/*对于每一次挤奶,结束时间+=休息时间.

先把m次挤奶按照开始时间排个序,用f[i]表示挤完第i个时间段的奶以后的最大挤奶量,那么有:

f[i]=max(f[i],f[j]+(第i次挤奶.ef)) (1<=j<i&&(第j次挤奶).ed<=(第i次挤奶).st).

 

注意:

1.答案不是f[m]而是max(f[i]) (1<=i<=m) (因为不一定最后一次挤奶是哪一次).*/
#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxm=1005;
using namespace std;
struct node{
	int st,ed,ef;
	bool operator<(const node& a) const{
		return st<a.st;
	}
}a[maxm];
int n,m,r;
int f[maxm];
void init(){
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++){
		cin>>a[i].st>>a[i].ed>>a[i].ef;
		a[i].ed+=r;
	}
	sort(a+1,a+m+1);
}
void solve(){
	for(int i=1;i<=m;i++){
		f[i]=a[i].ef;
		for(int j=1;j<i;j++){
			if(a[j].ed<=a[i].st)
				f[i]=max(f[i],f[j]+a[i].ef);
		}
	}
	int ans=f[1];
	for(int i=2;i<=m;i++) ans=max(ans,f[i]);
	cout<<ans<<endl;
}
int main(){
	init();
	solve();
	return 0;
}
