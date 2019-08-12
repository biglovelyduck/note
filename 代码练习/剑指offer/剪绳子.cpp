//剪绳子
/* 
编程题
【问题描述】
给你一根长度为n的绳子，请把绳子剪成m段 (m和n都是整数，n>1并且m>1)每段绳子的长度记为k[0],k[1],...,k[m].请问k[0]*k[1]*...*k[m]可能的最大乘积是多少？
【要求】 
【数据输入】绳子长度，一个整型数n(n>1)
【数据输出】把绳子剪成m段后, 可能的最大乘积数，也是一个整型数
【样例输入】 
绳子的长度n=9
【样例输出】 
我们把它剪成长度分别为3,3,3的三段，此时得到的最大乘积是3*3*3=27 */

#include <bits/stdc++.h>
using namespace std;

//动态规划算法 
int max(int n){
	if(n<2) return 0;
	if(n==2) return 1;
	if(n==3) return 2;
	int* a=new int[n+1];
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for(int i=4;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			a[i]=max(a[j]*a[i-j],a[i]);
		}
	}
	int m=a[n];
	delete[] a;
	return m;
}

//贪婪算法实现
int max1(int n){
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(n==3)
		return 2;
	//尽可能多的剪去长度为3的绳子段
	int timesOf3=n/3;
	//当绳子剩下最后的长度为4时，不用再去剪去长度为3的绳子
	if(n-timesOf3*3==1)
		timesOf3-=1;
	int timesOf2 =(n-timesOf3*3)/2;
	return (int)(pow(3,timesOf3*))*(int)(pow,2,timesOf2);tt 
} 
int main(){
	int n;
	cin>>n;
	cout<<max(n)<<endl;
}
