//POJ 3259 Wormholes 
/*虫洞：农夫约翰有F个农场，每个农场有N块地，其间有M条路，W条时光隧道（时间倒流）。问是否可能回到过去？

2.5 它们其实都是“图”

最短路

依然很水很基础的 Bellman-Ford 判定负圈，什么都不用考虑，一个 Bellman-Ford 就结束了。*/
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_E (2500+200+16)*2
struct edge{
	int from,to,cost;
	edge(){
		
	}
	edge(int from,int to,int cost):from(from),to(to),cost(cost){
		
	} 
}; 
edge es[MAX_E];
int d[MAX_E];
int V,E; 
bool find_negative_loop(){	//存在负圈返回true 
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;i<E;j++){	//从每个点开始遍历所有的边 
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				//如果更新了V次，表表示存在负圈
				if(i==V-1)	return true; 
			} 
		}
	}
	return false;
}
int main(){
	int F;	//农场数
	cin>>F;
	while(F--){
		int N,M,W;	//田地数，路径数，虫洞数
		cin>>N>>M>>W;
		V=N;
		E=0;
		//M条路径 
		for(int i=0;i<M;i++){
			int from,to,cost;
			cin>>from>>to>>cost;
			--from;
			--to;
			es[E].from=from;
			es[E].to=to;
			es[E].cost=cost;
			++E;
			//无向图再来一次
			es[E].from = to;
  			es[E].to = from;
  			es[E].cost = cost;
  			++E; 
		} 
		for(int i=0;i<W;i++){
			int from,to,cost;
			cin>>from>>to>>cost;
			--from;
			--to;
			es[E].from = from;
			es[E].to = to;
			es[E].cost = -cost;
			++E;
		}
		if (find_negative_loop())
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	} 
	return 0;
}
