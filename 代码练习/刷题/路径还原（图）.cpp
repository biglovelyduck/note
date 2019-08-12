//路径还原，输出最短路径 
//不断的把j替换成 prev[j],直到j=s为止就可以了
int prev[MAX_V];//最短路径上的前驱顶点
void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	fill(prev,prev+V,-1);
	d[s]=0;
	while(true){
		int v=-1;
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
		}
		if(v==-1) break;
		used[v]=true;
		for(int u=0;u<V;u++){
			if(d[u]>d[v]+cost[u][v]){
				d[u]=d[v]+cost[v][u];
				prev[u]=v;
			}
		}
	}
} 
//到顶点t的最短路
vector<int> get_path(int t){
	vector<int> path;
	for(;t!=-1;t=prev[t]) path.push_back(t);
	//翻转
	reverse(path.begin(),path.end());
	return path; 
} 
