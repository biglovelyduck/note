/*���鼯*/
//���ã���Ч�Ľ������²���
//��ʼ�����ϲ���һ����ĸ�����һ����ĸ����ߣ��ͱ����һ����������ѯ
//�����νṹ�У�Ҫ���ⷢ���˻� 
//ʵ�֣���par[x]=xʱ��x���������ĸ� 
int par[MAX_N];//����
int rank[MAX_N];//���ĸ߶�
//��ʼ��n��Ԫ��
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;//��ʼ��ÿ���ڵ㶼��������
		rank[i]=0; 
	}
}

//��ѯ���ĸ�
int find(int x){
	if(par[x]=x) return x;
	else return par[x]=find(par[x]);
} 

//�ϲ�x��y�����ļ���
void unite(int x,int y){
	x=find(x);//��x 
	y=find(y);//��y
	if(x==y) return;
	if(rank[x]<rank[y]) par[x]=y;
	else{
		par[y]=x;
		if(rank[x]=rank[y])	rank[x]++;
	} 
} 

//�ж�x��y�Ƿ���ͬһ������ 
bool same(int x,int y){
	return find(x)==find(y);
}
 
