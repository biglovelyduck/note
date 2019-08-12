//最小生成树（Kruskal算法） 
//按边的权值从小到大看一遍，如果不产生圈，重边也算在内
//就把当前边加入到生成树 
//可以用并查集高效的判断是否属于同一个连通分量 
struct edge{
	int u,v,cost;
};

bool cmp(const edge &e1,const edge &e2){
	return e1.cost<e2.cost;
}

edge es[MAX_E];
int V,E;

int kruskal(){
	sort(es,es+E,cmp);
	init_union_find(V);//并查集的初始化 
	int res;
	for(int i=0;i<E;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	} 
}		//思路最简单 
