/*第一章习题*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*1-25.更相减损术---迭代式*/ 
/*
__int64 gcdCN(__int64 a,__int64 b){
	int r=0;//a和b的2^r形式的公因子 
	while(!((a&1)||(b&1)))//若a和b都是偶数 
		a>>=1;b>>=1;r++;
	//以下，a和b之多有一个偶数
	while(1){
		while(!(a&1)) a>>=1;//若只有a是偶数，则剔除a所有因子2
		while(!(b&1)) b>>=1;
		(a>b)?(a=a-b):(b=b-a);
		if(0==a) return b<<r;
		if(0==b) return a<<r;
	} 
}
*/
//辗转相除法
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
int shift2(int *A,int n,int k){//借助倒置算法，将数组循环左移k位 
	k%=n;//确保k<=n
	reverse(A,k);//将区间o-k倒置 
	reverse(A+k,n-k);//将区间k-n倒置
	reverse(A,n);//倒置整个数组
	return 3*n; 
	 
}

/*1-29*/
template <typename T> 
struct Hailstone{//函数对象 
	virtual void operator()(T &e){
		int step=0;
		while(1!=e){//按照奇数偶数逐步转换，直至为1 
			(e%2)?e=3*e+1:e/=2;
			step++;			
		}
		//返回转换所需的步数
		e=step; 
	}
}
