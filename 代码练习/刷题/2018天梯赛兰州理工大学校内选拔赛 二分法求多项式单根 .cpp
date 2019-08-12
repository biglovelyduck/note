//2018天梯赛兰州理工大学校内选拔赛 二分法求多项式单根 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
double a3,a2,a1,a0;
double f(double x){
	return a3*x*x*x+a2*x*x+a1*x+a0;
}
double g(double a,double b){
	if(b-a<0.001) return (a+b)/2.0;
	if(f(a)*f(b)<0){
		double mid_v=f((a+b)/2.0);
		if(mid_v==0) return (a+b)/2.0; 
		else if(mid_v*f(a)>0){
			return g((a+b)/2.0,b);
		}
		else if(mid_v*f(b)>0){
			return g(a,(a+b)/2.0);
		}
	} 
} 
int main(){
	cin>>a3>>a2>>a1>>a0;
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%.2lf",g(a,b));
	return 0;
}
