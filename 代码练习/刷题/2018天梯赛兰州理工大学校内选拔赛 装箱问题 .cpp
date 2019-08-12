//2018天梯赛兰州理工大学校内选拔赛 装箱问题 
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

int main(){
	int n;
	cin>>n;
	int a[n],b[n],x[n];
	//memset(b,100,sizeof(b));
	for(int i=0;i<n;i++){
		b[i]=100;
		x[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<=b[j]){
				b[j]-=a[i];		//cout<<"b[j]:"<<b[j]<<endl; 
				x[i]=j;
				if(max<j) max=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" "<<x[i]<<endl;
	}
	cout<<max;
	return 0;
}
