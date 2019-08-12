#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX_N 500000	//root也使用这个范围 
#define MAX_M 100000
#define MAX_T 1000000
int n,m,root; 
int u,v,t;
int old_m;
//实现并查集 
int par[MAX_N];
int ran[MAX_N];
set<int> s;
//初始化n个元素
void init(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		ran[i]=0;
	}
}
//查询树的根.返回树的根 
int find(int x){
	if(par[x]==x) return x;
	else return par[x]=find(par[x]); 
} 
//合并xy所属的集合
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(ran[x]<ran[y]) par[x]=y;
	else{
		par[y]=x;
		if(ran[x]==ran[y]) ran[x]++;
	}
} 
bool same(int x,int y){
	return find(x)==find(y);
} 
struct edge{
	int u,v,cost;
	edge(){
	}
	edge(int u,int v,int cost):u(u),v(v),cost(cost){
	} 
};
bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}
edge es[MAX_M];	//边集合 
int kruskal(){
	sort(es,es+old_m,comp);
	init(n);	//初始化并查集 
	for(int i=0;i<old_m;i++){
		edge e=es[i];	//从小到大取边
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			s.insert(e.cost);
		} 
	}
	return *(--s.end());
}
int main(){
	int i=0;
	cin>>n;
	cin>>m;
	cin>>root;
	old_m=m;
	while(m--){
		cin>>u>>v>>t;
		es[i++]=edge(u,v,t); 
	}
	cout<<kruskal()<<endl;;
	return 0;
}
