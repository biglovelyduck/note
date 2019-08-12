//2018天梯赛全国模拟竞赛  社交集群 
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
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)

int p[1005],ai[1005],cir[1005];
void init(int n){
	for(int i=1;i<=n;i++)
		p[i]=i;
}
int find(int x){
	if(p[x]==x) return x;
	else return p[x]=find(p[x]);
}
void join(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx!=ry) p[ry]=rx;
}
int main(){
	int n,i,j,k,x;
	char ch;
	cin>>n;
	init(n);
	for( i=1;i<=n;i++){
		cin>>k>>ch;
		for( j=1;j<=k;j++){
			cin>>x;
			if(ai[x]==0) ai[x]=i;	//将i作为爱好x的根 
			join(i,find(ai[x])) ;	//将i号人和爱好x的人群连接 
		}
	}
	int sum=0;
	for(i=1;i<=n;i++)
		cir[find(i)]++;
	sort(cir+1,cir+1001,greater<int>());	
	for( i=1;i<=1000;i++){
		if(cir[i]==0){
			i--;
			break;
		}
	}
	cout<<i<<endl;
	for(j=1;j<=i;j++){
		if(j==1) cout<<cir[j];
		else cout<<" "<<cir[j];
	} 
	return 0;
}
