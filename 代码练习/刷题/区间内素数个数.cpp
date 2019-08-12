//埃氏筛法 
//求n以内的素数个数 
int prime[MAX_N];//第i个素数
bool is_prime[MAX_N+1];
//返回n以内的素数 
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

//求区间内的素数 个数  给定的区间[a,b)的a，b数值超大 
//思路：先做好[2,根号b)的表和[a,b)的表
//然后从 [2,根号b)的表中筛得素数的同时，也将其非素数从[a,b)表中划去 
typedef long long ll;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//对区间 [a,b)内的整数执行筛法
//is_prime[i-a]=true表示i是素数
void segment_sieve(ll a,ll b){
	for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
	for(int i=0;i<b-a;i++) is_prime[i]=true;//先做好[2,根号b)的表和[a,b)的表
	
	for(int i=2;(ll)i*i<b;i++){
		if(is_prime_small[i]){
			//开始筛除非素数了
			for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[j]=false; 
			for(ll j=max(2LL,(a+i-1/i)*i;j<b;j+=i))
				is_prime[j-a]=false;9
		}
	}
} 
