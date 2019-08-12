/*单源最短路*/ 
//固定一个起点，到其他所有点的最短路的问题
//记从起点s出发到顶点i的最短距离d[i]
//d[i]=min{d[j]+(从j到i的边的权值)|e=(j,i)属于E}
//Bellman-Ford适用于无负环图 ，适用于带负权的图 
 
struct edge{
	int from,to,cost;
};
edge es[MAX_E];
int d[MAX_V];//最短距离
int V,E;

//求解从s出发到所有点的最短距离
void shortest_path(int s){
	
	//初始化 
	for(int i=0;i<V;i++) d[i]=INF;
	d[s]=0;
	
	while(true){
		bool update=false;
		//遍历所有的边
		for(int i=0;i<E;i++){
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update) break; 
	}
} 

//如果一开始把d[i]都初始化为0，就可以检查出所有的负圈 
//如果返回true就存在负圈
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				
				//如果第n次仍然更新了，则存在负圈
				if(i==V-1) return true; 
			}	
		}
	}
	return false;
} 
