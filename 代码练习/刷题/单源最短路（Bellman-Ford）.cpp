/*��Դ���·*/ 
//�̶�һ����㣬���������е�����·������
//�Ǵ����s����������i����̾���d[i]
//d[i]=min{d[j]+(��j��i�ıߵ�Ȩֵ)|e=(j,i)����E}
//Bellman-Ford�������޸���ͼ �������ڴ���Ȩ��ͼ 
 
struct edge{
	int from,to,cost;
};
edge es[MAX_E];
int d[MAX_V];//��̾���
int V,E;

//����s���������е����̾���
void shortest_path(int s){
	
	//��ʼ�� 
	for(int i=0;i<V;i++) d[i]=INF;
	d[s]=0;
	
	while(true){
		bool update=false;
		//�������еı�
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

//���һ��ʼ��d[i]����ʼ��Ϊ0���Ϳ��Լ������еĸ�Ȧ 
//�������true�ʹ��ڸ�Ȧ
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				
				//�����n����Ȼ�����ˣ�����ڸ�Ȧ
				if(i==V-1) return true; 
			}	
		}
	}
	return false;
} 
