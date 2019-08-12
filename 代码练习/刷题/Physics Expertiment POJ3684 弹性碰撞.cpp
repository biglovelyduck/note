//Physics Expertiment POJ3684 弹性碰撞
#include <iostream>
#include <cmath> 
#include <algorithm>
using namespace std;
const double g=10.0;
#define MAX_N 101

int N,H,R,T;

double y[MAX_N];	//球的最终位置

//求出T时刻球的位置
double calc(int T){
	if(T<=0) return H;
	double t=sqrt(2*H/g);	//下落的时间 
	int k=(int)(T/t);		//往和返的总次数
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
