//��n����Ʒ�������ͼ�ֵ�ֱ���wi��vi������ȡ��k����Ʒʹ�õ�λ�����ļ�ֵ��� 
//1<=k<=n<=10^4
//1<=wi,vi<=10^6

//���壺����C(x):����ѡ��ʹ�õ�λ�����ļ�ֵ��С��x
//ת����������C(x)�����x 
//���� C(x)=((vi-x*wi)�Ӵ�С�����е�ǰk���ĺͲ�С��0

int n,k;
int w[MAX_N],v[MAX_N];

double y[MAX_N];//v-x*w

//�ж��Ƿ���������
bool C(double x){
	for(int i=0;i<n;i++){
		y[i]=v[i]-x*w[i];
	}
	sort(y,y+n);
	//����y�����дӴ�С��ǰk�����ĺ�
	double sum=0;
	for(int i=0;i<k;i++){
		sum+=y[n-1-i];
	} 
	return sum>=0;
} 

void solve(){
	double lb=0,ub=INF;
	for(int i=0;i<100;i++){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	cout<<ub;
}
