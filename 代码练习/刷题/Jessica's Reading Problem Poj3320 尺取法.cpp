//Jessica's Reading Problem Poj3320 ��ȡ�� 
/*Ϊ��׼�����ԣ�Jessica ��ʼ��һ���ܺ�Ŀα���Ҫ��ͨ�����ԣ�����ѿα������е�֪ʶ��
�����ա��Ȿ���ܹ���P ҳ����i ҳǡ����һ��֪ʶ��ai��ÿ��֪ʶ�㶼��һ��������ţ���
ȫ����ͬһ��֪ʶ����ܻᱻ����ᵽ��������ϣ��ͨ���Ķ�����������һЩҳ�����е�֪
ʶ�㶼���ǵ�������ÿҳд����֪ʶ�㣬�����Ҫ�Ķ�������ҳ����
��������
. 1 �� P �� 106*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX_P=1e6+1;
int P,a[MAX_P];
void solve(){
	set<int> all;
	//ͳ�Ƴ���֪ͬʶ����ܸ��� 
	for(int i=0;i<P;i++){
		all.insert(a[i]);
	}
	int n=all.size();
	
	//��ȡ�����
	int s=0,t=0,num=0;
	map<int,int> count;//֪ʶ��->���ֵĴ���
	int res=P;
	for(;;){
		while(t<P&&num<n){ 
			if(count[a[t++]]++==0)
				//�����µ�֪ʶ�� 
				num++;
		}
		if(num<n) break;
		res=min(res,t-s);
		if(--count[a[s++]]==0)
			//ĳ��֪ʶ����ֵĴ������0��
			num--; 
	} 
	cout<<res<<endl;
}
int main(){
	cin>>P;
	for(int i=0;i<5;i++)
		cin>>a[i];
	solve();
	return 0;
}
