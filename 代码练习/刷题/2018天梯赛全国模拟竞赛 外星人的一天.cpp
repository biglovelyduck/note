//2018天梯赛全国模拟竞赛 外星人的一天 
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
int main(){
	int n;
	int d,h,m;
	cin>>n;
	while(n--){
		scanf("%d %02d:%02d",&d,&h,&m);
		if(d==0) printf("%d %02d:%02d\n",d,h,m);
		else{
			int minute=((d-1)*24+h)*60+m;
			int D=minute/(48*60)+1;
			int H=(minute%(48*60))/120;
			int M=(minute-(D-1)*48*60-H*120)/2;
			printf("%d %02d:%02d\n",D,H,M);
		}	
	}
	return 0;
}
