//����ɸ�� 
//��n���ڵ��������� 
int prime[MAX_N];//��i������
bool is_prime[MAX_N+1];
//����n���ڵ����� 
int sieve(int n){
	int p=0;
	for(int i=0;i<=n;i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
		}
	}
	return p; 
}

//�������ڵ����� ����  ����������[a,b)��a��b��ֵ���� 
//˼·��������[2,����b)�ı��[a,b)�ı�
//Ȼ��� [2,����b)�ı���ɸ��������ͬʱ��Ҳ�����������[a,b)���л�ȥ 
typedef long long ll;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//������ [a,b)�ڵ�����ִ��ɸ��
//is_prime[i-a]=true��ʾi������
void segment_sieve(ll a,ll b){
	for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
	for(int i=0;i<b-a;i++) is_prime[i]=true;//������[2,����b)�ı��[a,b)�ı�
	
	for(int i=2;(ll)i*i<b;i++){
		if(is_prime_small[i]){
			//��ʼɸ����������
			for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[j]=false; 
			for(ll j=max(2LL,(a+i-1/i)*i;j<b;j+=i))
				is_prime[j-a]=false;9
		}
	}
} 
