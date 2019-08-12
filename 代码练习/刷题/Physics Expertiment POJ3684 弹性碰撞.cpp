//Physics Expertiment POJ3684 ������ײ
#include <iostream>
#include <cmath> 
#include <algorithm>
using namespace std;
const double g=10.0;
#define MAX_N 101

int N,H,R,T;

double y[MAX_N];	//�������λ��

//���Tʱ�����λ��
double calc(int T){
	if(T<=0) return H;
	double t=sqrt(2*H/g);	//�����ʱ�� 
	int k=(int)(T/t);		//���ͷ����ܴ���
	cout<<"k&1:"<<(k&1)<<endl;
	if((k&1)==0){
		double d=T-k*t;
		return H-g*d*d/2;
	} 
	else{
		double d=t-(T-k*t);
		return H-g*d*d/2;
	}
} 

void solve(){
	for(int i=0;i<N;i++)
		y[i]=calc(T-i);
	sort(y,y+N);
	for(int i=0;i<N;i++)
		printf("%.2f%c",y[i]+2*R*i/100.0,i+1==N?'\n':' ');
}

int main(){
	cin>>N>>H>>R>>T;
	solve();
}
