//2018天梯赛全国模拟竞赛 抢红包 
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
struct node{
	int id;
	double money;
	int num;	//	抢到的红包个数 
};
bool comp(node &a,node &b){
	if(a.money==b.money){
		if(a.num==b.num) return a.id<b.id;
		return a.num>b.num;
	}
	return a.money>b.money;
}
int main(){
	int N;
	cin>>N;
	double a[N+1]={0.0};	//a[i]表示编号为i的人的钱 ，初始化为0 
	int b[N+1]={0};	//b[i]表示编号为i的人抢到的红包的个数 
	for(int i=1;i<=N;i++){	//每个人发红包 
		int num;	//每个人发的红包个数
		cin>>num;
		double sum=0.0; 
		while(num--){
			int id;double money;
			cin>>id>>money;	//编号为id的人抢了money的钱 
			sum+=money;
			a[id]+=money;
			b[id]+=1; 
		} 
		a[i]-=sum;	//编号为i的人发了sum钱的红包 
	}
	vector<node> v;
	node n;
	for(int i=1;i<=N;i++){
		n.id=i;
		n.money=a[i];
		n.num=b[i];
		v.push_back(n);
	}
	sort(v.begin(),v.end(),comp); 
	for(int i=0;i<N;i++)
		printf("%d %.2f\n",v[i].id,v[i].money/100);
	return 0;
}
