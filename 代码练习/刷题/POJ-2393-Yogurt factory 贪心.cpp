//POJ-2393-Yogurt factory
/*题目是说你每周可以生产牛奶，每周生产的价格为Ci，每周需要上交的牛奶量Yi，
你可以选择本周生产牛奶，也可选择提前几周生产出存储在仓库中（仓库无限大，而且保质期不考虑），
每一周存仓库牛奶需要花费S元，让你求出所有周的需求量上交的最少花费。

将S转换到花费中~*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=10011;
int n,s;
int y[maxn],c[maxn];
int main(){
	while(scanf("%d%d",&n,&s)!=EOF){
		for(int i=0;i<n;i++){
			cin>>c[i]>>y[i];
		}
		long long ans=0;
		for(int i=1;i<n;i++)
			c[i]=min(c[i-1]+s,c[i]);
		for(int i=0;i<n;i++)
			ans+=c[i]*y[i];
		cout<<ans<<endl;
	}
	return 0;
} 
