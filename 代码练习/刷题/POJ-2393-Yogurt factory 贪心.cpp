//POJ-2393-Yogurt factory
/*��Ŀ��˵��ÿ�ܿ�������ţ�̣�ÿ�������ļ۸�ΪCi��ÿ����Ҫ�Ͻ���ţ����Yi��
�����ѡ��������ţ�̣�Ҳ��ѡ����ǰ�����������洢�ڲֿ��У��ֿ����޴󣬶��ұ����ڲ����ǣ���
ÿһ�ܴ�ֿ�ţ����Ҫ����SԪ��������������ܵ��������Ͻ������ٻ��ѡ�

��Sת����������~*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=10011;
int n,s;
int y[maxn],c[maxn];
int main(){
	while(scanf("%d%d",&n,&s)!=EOF){
		for(int i=0;i<n;i++){
			cin>>c[i]>>y[i];
		}
		long long ans=0;
		for(int i=1;i<n;i++)
			c[i]=min(c[i-1]+s,c[i]);
		for(int i=0;i<n;i++)
			ans+=c[i]*y[i];
		cout<<ans<<endl;
	}
	return 0;
} 
