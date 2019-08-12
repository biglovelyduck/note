//���󱳰����� �۰����� 
/*�������ͼ�ֵ�ֱ�Ϊwi,vi ��n ����Ʒ������Щ��Ʒ����ѡ������������W ����Ʒ��������
��ѡ�����м�ֵ�ܺ͵����ֵ��
��������
. 1 �� n �� 40
. 1 �� wi,vi �� 1015
. 1 �� W �� 1015*/
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
int n;					//n����Ʒ 
ll w[MAX_N],v[MAX_N];	//wi,vi
ll W;					//����������W
pair<ll,ll> ps[1<<(MAX_N/2)];	//(��������ֵ) 2^20

void solve(){
	//ö��ǰ�벿��
	int n2=n/2;			//һ�����Ʒ 
	for(int i=0;i<(1<<n2);i++){	//i<5,i�洢������ϵĽ�� 
		ll sw=0,sv=0;
		for(int j=0;j<n2;j++){
			if((i>>j)&1){		//�ж�Ҫ��Ҫj���λ�õ���Ʒ 
				sw+=w[j];
				sv+=v[j];
			} 
		} 
		ps[i]=make_pair(sw,sv);			//���������ɵĸ��ֲ�ͬ�������Ͷ�Ӧ�Ĳ�ͬ�ļ�ֵ�� 
	} 
	//ȥ�������Ԫ��
	sort(ps,ps+(1<<n2));	//������,������������С���� 
	int m=1;
	for(int i=1;i<(1<<n2);i++){
		if(ps[m-1].second<ps[i].second)	//Ӧ������ѡ������С���Ҽ�ֵ���ѡ�� 
			ps[m++]=ps[i];
	}  
	//ǰm��Ԫ�ض��Ǵ洢��ĳ���������ŵļ�ֵ 
	//ö�ٺ�벿�ֲ������
	ll res=0;
	for(int i=0;i<(1<<(n-n2));i++){
		ll sw=0,sv=0;
		for(int j=0;j<n-n2;j++){
			if((i>>j)&1){
				sw+=w[n2+j];	//ö�ٺ�벿�ֵĸ���ѡ�� 
				sv+=v[n2+j];
			}
		}
		if(sw<=W){
			//W-sw��ǰ�벿����Ҫ������ 
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

