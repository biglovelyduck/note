//·����ԭ��������·�� 
//���ϵİ�j�滻�� prev[j],ֱ��j=sΪֹ�Ϳ�����
int prev[MAX_V];//���·���ϵ�ǰ������
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
//������t�����·
vector<int> get_path(int t){
	vector<int> path;
	for(;t!=-1;t=prev[t]) path.push_back(t);
	//��ת
	reverse(path.begin(),path.end());
	return path; 
} 
