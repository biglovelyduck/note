/*����ţ����,��m�ο��Լ�,����ÿ�ο�ʼ���̵�ʱ��st,�������̵�ʱ��ed,���м��̵���ef,
ÿ�μ�����Ҫ��Ϣrʱ��,���������.*/
/*����ÿһ�μ���,����ʱ��+=��Ϣʱ��.

�Ȱ�m�μ��̰��տ�ʼʱ���Ÿ���,��f[i]��ʾ�����i��ʱ��ε����Ժ���������,��ô��:

f[i]=max(f[i],f[j]+(��i�μ���.ef)) (1<=j<i&&(��j�μ���).ed<=(��i�μ���).st).

 

ע��:

1.�𰸲���f[m]����max(f[i]) (1<=i<=m) (��Ϊ��һ�����һ�μ�������һ��).*/
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
