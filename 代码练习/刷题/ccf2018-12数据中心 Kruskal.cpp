#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX_N 500000	//rootҲʹ�������Χ 
#define MAX_M 100000
#define MAX_T 1000000
int n,m,root; 
int u,v,t;
int old_m;
//ʵ�ֲ��鼯 
int par[MAX_N];
int ran[MAX_N];
set<int> s;
//��ʼ��n��Ԫ��
void init(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		ran[i]=0;
	}
}
//��ѯ���ĸ�.�������ĸ� 
int find(int x){
	if(par[x]==x) return x;
	else return par[x]=find(par[x]); 
} 
//�ϲ�xy�����ļ���
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
edge es[MAX_M];	//�߼��� 
int kruskal(){
	sort(es,es+old_m,comp);
	init(n);	//��ʼ�����鼯 
	for(int i=0;i<old_m;i++){
		edge e=es[i];	//��С����ȡ��
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
