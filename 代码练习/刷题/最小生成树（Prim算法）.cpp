/*��С������MST��Prim�㷨��*/
//����dijkstra�㷨
/*��һ�����������֧�о�*/
int cost[MAX_V][MAX_V];//cost[u][v]��ʾ��e=(u,v)��Ȩֵ��������ΪINF 
int mincost[MAX_V];//�Ӽ���x������ÿ���������СȨֵ
bool used[MAX_V];//����i�Ƿ�����ڼ���x��
int V;
int prim(){
	//��ʼ�����ж��� 
    for(int i=0;i<V;i++){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;//xΪ�գ�������0����СȨֵΪ0 
    int res=0;//��С����
    while(true){
    	//û�п��Ը�����̾���ı�־ 
        int v=-1;
        //�Ӳ�����x���ϵĶ�����ѡȡ��x����Ȩֵ��С�Ķ���v
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;//v=-1���¶����һ��ѭ������s���ڶ������Ҵ�Ȩֵ��С�ĵ�
            //�ҵ�Ȩֵ��С�ĵ�v 
        }
        if(v==-1) break;//ȫ����������
        used[v]=true;//�Ѷ���v���뵽����s
        res+=mincost[v];
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[v][u]);//����v���ڶ���u����СȨֵ
        }
    }
    return res;
}
