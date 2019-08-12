//2019天梯赛模拟题集  L2-2 月饼 
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
#include <sstream>
#include <iterator>
#include <functional>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
bool cmp(double a,double b){
	return a>b;
}
int main(){
	int N,D;
	cin>>N>>D;
	double a[N],b[N];	//库存量，总售价
	double c[N]; 	//单价
	for(int i=0;i<N;i++){
		cin>>a[i];
	} 
	for(int i=0;i<N;i++){
		cin>>b[i];
		c[i]=double(b[i])/a[i];
	}
	double d[N];
	for(int i=0;i<N;i++){
		d[i]=c[i];	
	}
	sort(d,d+N,greater<double>());
	
	int index=0;
	double sum=0; 
	while(D){
		double max=d[index++];
		int find=0;
		for(int i=0;i<N;i++){
			if(max==c[i]){
				find=i;
				break;
			}
		}
		if(D>a[find]){
			D-=a[find];
			sum+=b[find];
		} 
		else{
			sum+=D*c[find];
			D=0;
		}
	}
	printf("%.2f",sum);
	return 0;
}
