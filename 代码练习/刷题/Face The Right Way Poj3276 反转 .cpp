//Face The Right Way Poj3276 ��ת 
/*N ͷţ�ų���һ�С�ÿͷţ������ǰ�������Ϊ�������е�ţ������ǰ����ũ��Լ������
һ̨�Զ�ת��Ļ�������������ڹ���ʱ�ͱ����趨һ����ֵK������ÿ����һ��ǡ��ʹK
ͷ������ţת�������Ϊ�������е�ţ��������ǰ����Ҫ�����ٵĲ�������M �Ͷ�Ӧ��
��С��K��
��������
. 1��N��5000*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=5001;
int N;
int dir[MAX_N];	//ţ�ķ���0��F  1��B
int f[MAX_N];	//����[i,i+K-1]�Ƿ�����˷�ת

//�̶�K�������С�Ĳ�������
//�޽ⷵ��-1
int calc(int K){
	memset(f,0,sizeof(f));
	int res=0;	//��ת�Ĵ��� 
	int sum=0;	//�����������ڰ���λ��i������f�ĺ�
	for(int i=0;i+K<=N;i++){
		//��������[i,i+K-1]
		if((dir[i]+sum)%2!=0){
			//ǰ�˵�ţ�泯��
			res++;
			f[i]=1; 
		} 
		sum+=f[i];
		if(i-K+1>=0){
			//�˵㵽ͷ�ˣ������趨sum��ֵ������ȡ����ͷ�˵�ķ�ת��Ӱ��
			sum-=f[i-K+1]; 
		}
	} 
	
	//���ʣ�µ�ţ�Ƿ����泯�󷽵������ʣ��N-K+1ͷţ
	for(int i=N-K+1;i<N;i++){
		if((dir[i]+sum)&1!=0)
			//�޽⣬���泯�����ţ
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
		if(m>=0&&m<M){	//����С�Ĵ������ͱ���K 
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
