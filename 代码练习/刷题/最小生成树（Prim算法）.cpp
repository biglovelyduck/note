/*最小生成树MST（Prim算法）*/
//类似dijkstra算法
/*有一种向外扩大分支感觉*/
int cost[MAX_V][MAX_V];//cost[u][v]表示边e=(u,v)的权值，不存在为INF 
int mincost[MAX_V];//从集合x出发到每个顶点的最小权值
bool used[MAX_V];//顶点i是否包含在集合x中
int V;
int prim(){
	//初始化所有顶点 
    for(int i=0;i<V;i++){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;//x为空，到顶点0的最小权值为0 
    int res=0;//最小距离
    while(true){
    	//没有可以更新最短距离的标志 
        int v=-1;
        //从不属于x集合的顶点中选取从x到其权值最小的顶点v
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;//v=-1是新顶点第一次循环，从s相邻顶点中找打权值最小的点
            //找到权值最小的点v 
        }
        if(v==-1) break;//全部都更新完
        used[v]=true;//把顶点v加入到集合s
        res+=mincost[v];
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[v][u]);//更新v相邻顶点u的最小权值
        }
    }
    return res;
}
