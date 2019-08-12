//Nͷţ�����1��N
//ţ���Ը��ǿ�������п����ж�ͷţ����ͬһ��λ��
//����ML����ϵ�õ�ţ����Ϣ(AL,BL,DL),��ʾAL��BL��ͷţ��������DL 
//����MD����ϵ���õ�ţ����Ϣ(AD,BD,DD)����ʾAD��BD��ͷţ����С����DD
//������Щ�����������У���1�ź�N��ţ��������

//����ת�� ��i��ţ��λ����d[i] d[i]<=d[i+1]			���Σ�d[i+1]+0>=d[i] 
//���ڹ�ϵ�õ�ţ֮����������  d[AL]+DL>=d[BL]		���Σ� 
//���ڹ�ϵ���õ�ţ֮���������� a[AD]+DD<=d[BD] 	���Σ�a[BD]+(-DD)>=d[AD]
//Bellman-Ford�㷨 
//����
int N,ML,MD;
int AL[MAX_ML],BL[MAX_ML],DL[MAX_ML];
int AD[MAX_MD],BD[MAX_MD],DD[MAX_MD];
int d[MAX_N];//��̾���
void solve(){
	fill(d,d+N,INF);
	d[0]=0;
	for(int k=0;k<N;k++){
		//��i+1��i��ȨֵΪ0
		for(int i=0;i+1<N;i++){
			if(d[i+1]<INF) d[i]=min(d[i],d[i+1]+0);
		} 
		//��AL��BL��ȨֵΪDL
		for(int i=0;i<ML;i++){
			if(d[AL[i]-1]<INF){
				d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
			}
		}
		//��BD��AD��ȨֵΪ-DD
		for(int i=0;i<MD;i++){
			if(d[BD[i]-1]<INF){
				d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
			}
		}
		int res=d[N-1];
		if(d[0]<0){
			//���ڸ�Ȧ�����
			res=-1; 
		} 
		else if(res==INF){
			res=-2;
		}
		cout<<res;
	}
} 
