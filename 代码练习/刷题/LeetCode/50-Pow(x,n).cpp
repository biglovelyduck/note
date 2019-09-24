//50-Pow(x,n)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
//1.暴力，超时 
class Solution {
public:
    double myPow(double x, int n) {
       long long N=n;
	   if(N<0){
	    	x=1/x;
	    	N=-N;			//将N变为正的 
	   } 
	   double ans=1;
	   for(long long i=0;i<N;i++){
	   		ans=ans*x;
	   }
	   return ans; 
    }
};

//2.快速幂算法，递归
class Solution1{
public:
	double fastPow(double x,long long n){
		if(n==0) return 1.0;
		
		double half=fastPow(x,n/2);
		if(n%2==0) return half*half;
		else return half*half*x;
	}

	double myPow(double x,int n){
		long long N=n;
		if(N<0){
			x=1/x;
			N=-N;
		}
		return fastPow(x,N);
	}
};

//3.快速幂，非递归
class Solution2{
public:
	double myPow(double x,int n){
		long long N=n;
		if(N<0){
			x=1/x;
			N=-N;
		}
		double ans=1;
		double current_product=x;
		for(long long i=N;i;i/=2){
			if(i%2) ans=ans*current_product;
			current_product=current_product*current_product;
		}
		return ans;
	}
};
