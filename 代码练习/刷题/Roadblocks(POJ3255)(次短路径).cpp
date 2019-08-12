//ĳ��������R����·��N���ӿڣ���·����˫��ͨ�С�
//��1��·�ڵ�N�ŵĴζ�·�����Ƕ���
//ͬһ���߿��Ծ������
//1<=N<=5000;
//1<=R<=100000 
//��v�Ĵζ�·����Ҫô�ǵ�u�����·��+u->v�ı�
//				Ҫô�ǵ�u�Ĵζ�·��+u->v�ı�
const int INF=100000;
struct edge{
	int to,cost;
};
int N,R;
vector<edge> G[MAX_N];//ͼ���ڽӱ�
int dist[MAX_N];
int dist2[MAX_N];
typedef pair<int,int> P;//first����̾��룬second�Ƕ�����
void solve(){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dist,dist+N;INF);
	fill(dist2,dist2+N;INF);
	dist[1]=0;
	que.push(P(0,1));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.second,d=p.first;//��̾���ĵ����������̾���
		////����ζ�·����С��d ��ô�Ͳ����ټ���ȥ����
		if(dist2[v]<d) continue;//�ζ�·���Ѿ�ȷ����������ǰ�㵽�õ�����Ϊ�����·�� 
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			//��e.to�ļ���ζ̾��� �ǵ�v������� + e.cost
			int d2=d+e.cost;
			if(dist[e.to]>d2){//����ζ�·С�����· �������·�ʹζ�·
				swap(dist[e.to],d2);
				que.push(P(dist[e.to],e.to));
			}
			if(dist2[e.to]>d2&&dist[e.to]<d2){//������Ը��´ζ�·
				dist2[e.to]=d2;
				que.push(P(dist2[e.to],e.to));
				//������if ���ִζ�· Ҫô�ǵ�������ĳ����������·
				//����u->v�����ߣ�Ҫô�ǵ�u�Ĵζ�·�ټ���u->v������
			}
		} 
	}
	cout<<dist2[N-1];
} 
