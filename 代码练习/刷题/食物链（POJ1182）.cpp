//Nֻ���������������ABC�����ֹ�ϵA��B��B��C��C��A
//����������Ϣ�ĸ���������Ϣ���жϴ�����
//˼·��i-x��ʾi��������x,���鼯��ÿһ�����ʾ�����������ش���������ͬʱ���� 
//��һ�֣�x��y����ͬһ�ࡣ�����ϲ�x-A��y-A,x-B��y-B,x-C��y-C
//�ڶ��֣�x��y�������ϲ�x-A��y-B���ϲ�x-B��y-C���ϲ�x-C��y-A�� 
int N,K;//Nֻ���K����Ϣ
int T[MAX_K],X[MAX_K],Y[MAX_K];
//������ʡ�ԵĲ��鼯�Ĵ���
void solve(){
	//��ʼ�����鼯
	//Ԫ��x��x+N,x+2*N�ֱ����x-A,x-B,x-C
	init(N*3);
	
	int ans=0;
	for(int i=0;i<K;i++){
		int t=T[i];//ÿ����Ϣ
		int x=X[i]-1,y=Y[i]-1;//��������0...N-1�ķ�Χ
		//����ȷ�ı��
		if(x<0||N<=x||y<0||N<=y){
			ans++;
			continue;
		}
		//�ж�������һ����Ϣ 
		if(t==1){
			//x��y����ͬһ�����Ϣ
			//������ͬһ�� 
			//ͬһ��������һ���� 
			if(same(x,y+N)||same(x,y+2*N)) {
				ans++;
			}
			//����ͬһ�� 
			else{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
			}
		} 
		else{
			//x��y����Ϣ
			if(same(x,y)||same(x,y+2*N)){
				ans++;
			} 
			else{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	} 
	cout<<ans;
} 
