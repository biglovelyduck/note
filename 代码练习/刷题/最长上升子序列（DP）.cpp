/*�����������*/
/*����һ�����У�����������������������еĳ���*/
/*����������ai<=1000000*/
//���ƹ�ϵ
//a[i]:��aiΪĩβ������������еĳ���{1.ֻ����ai��������
//										{2.ǰ���Ѿ�ȷ���õ�������׷��ai
//dp[i]=max{1,dp[j]+1|j<i��a[j]<a[i]}
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX_N=101;
int n;
int a[MAX_N];
int dp[MAX_N];
void solve(){
	int res=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++) if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
//	while(n--){
//		cout<<"n="<<n<<" i="<<i<<endl;
//		cin>>a[i++];
//	}
	int k=0;
	while(n--){
		cout<<a[k++]<<endl;
	}
	solve();
	k=0;
	while(n--){
		cout<<a[k++]<<endl;
	}
	//cout<<max(1,2);
	return 0;
} 

//�����ò�ͬ�������г�����ͬ����ô��ĩβԪ�ؽ�С�ĸ�������
//���Է�������Գ�����ͬ���������С��ĩβԪ�����
//dp[i]:=����Ϊi+1��������������ĩβԪ�ص���Сֵ(�����ھ�INF) 
int dp[MAX_N];
void solve(){
	fill(dp,dp+n;INF);
	for(int i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i])=a[i];
	cout<<lower_bound(dp,dp+n,INF)-dp;//�˿�dp�������ÿ��ĩβԪ�ؽ�С�������� 
	}
}
