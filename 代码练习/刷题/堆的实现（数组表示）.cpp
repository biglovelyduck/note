/*�ѵ�ʵ��*/ 
//����ӱ�ţ��Լ����*2+1  �Ҷ��ӱ�ţ��Լ����*2+2 
int heap[MAX_N],sz=0;//��С 
void push(int x){
	int i=sz++;//�Լ����ı��
	while(i>0){
		//���׽����
		int p=(i-1)/2;
		//����Ѿ�û�д�С�ߵ������˳�
		if(heap[p]<=x) break;
		//�͸��׽���д�С�ߵ�
		heap[i]=heap[p];
		i=p; 
	} 
	heap[i]=x;
} 
int pop(){
	//��Сֵ
	int ret=heap[0];
	//Ҫ�ᵽ������ֵ
	int x=heap[--sz]; 
	//�Ӹ���ʼ���½���
	int i=0;
	while(i*2+1<sz){
		//�Ƚ϶��ӵ�ֵ
		int a=i*2+1,b=i*2+2;
		if(b<sz&&heap[b]<heap[a]) a=b;//a�����С���ӵ��±� 
		//����Ѿ�û�д�С�ߵ����˳�
		if(heap[a]>=x) break;
		//�Ѷ��ӵ���ֵ������
		heap[i]=heap[a]; 
		i=a;//���������� 
	}
	heap[i]=x;
	return ret; 
}

//�Ѽ����ȶ��е�ʵ�֣�stl��priority_queue���ǣ�ȡ����ֵ�õ����ֵ 
