/*��һ��ϰ��*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*1-25.���������---����ʽ*/ 
/*
__int64 gcdCN(__int64 a,__int64 b){
	int r=0;//a��b��2^r��ʽ�Ĺ����� 
	while(!((a&1)||(b&1)))//��a��b����ż�� 
		a>>=1;b>>=1;r++;
	//���£�a��b֮����һ��ż��
	while(1){
		while(!(a&1)) a>>=1;//��ֻ��a��ż�������޳�a��������2
		while(!(b&1)) b>>=1;
		(a>b)?(a=a-b):(b=b-a);
		if(0==a) return b<<r;
		if(0==b) return a<<r;
	} 
}
*/
//շת�����
int GCD(int a,int b)
{    
	return b==0?a:GCD(b,a%b);
}
int main(){
	cout<<6%9<<endl;
	cout<<GCD(6,9); 
	return 0;
} 

/*1-26*/
int shift2(int *A,int n,int k){//���������㷨��������ѭ������kλ 
	k%=n;//ȷ��k<=n
	reverse(A,k);//������o-k���� 
	reverse(A+k,n-k);//������k-n����
	reverse(A,n);//������������
	return 3*n; 
	 
}

/*1-29*/
template <typename T> 
struct Hailstone{//�������� 
	virtual void operator()(T &e){
		int step=0;
		while(1!=e){//��������ż����ת����ֱ��Ϊ1 
			(e%2)?e=3*e+1:e/=2;
			step++;			
		}
		//����ת������Ĳ���
		e=step; 
	}
}
