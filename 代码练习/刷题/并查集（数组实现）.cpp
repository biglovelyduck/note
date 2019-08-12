/*并查集*/
//作用：高效的进行如下操作
//初始化。合并（一个组的根向另一个组的根连边，就变成了一棵树）。查询
//在树形结构中，要避免发生退化 
//实现，当par[x]=x时，x是所在树的根 
int par[MAX_N];//父亲
int rank[MAX_N];//树的高度
//初始化n个元素
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;//初始化每个节点都独立成树
		rank[i]=0; 
	}
}

//查询树的根
int find(int x){
	if(par[x]=x) return x;
	else return par[x]=find(par[x]);
} 

//合并x，y所属的集合
void unite(int x,int y){
	x=find(x);//根x 
	y=find(y);//根y
	if(x==y) return;
	if(rank[x]<rank[y]) par[x]=y;
	else{
		par[y]=x;
		if(rank[x]=rank[y])	rank[x]++;
	} 
} 

//判断x，y是否是同一个集合 
bool same(int x,int y){
	return find(x)==find(y);
}
 
