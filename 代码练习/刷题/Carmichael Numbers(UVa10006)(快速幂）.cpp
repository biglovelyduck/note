//���������㣬����ƽ����
//���ǰ������1<x<n����x^n��x(mod n) �����ĺ���������������ΪCarmichael Number,
//���ڸ���������n���ж����ǲ���CarMichael Number
// x^n��x(mod n)��ʾ��������n��ȡ�����
//2<n<65000 

//���������n=2^k ��n=2^k1+2^k2+..
//����x^22=x^16*x^4*x^2  22�Ķ�����10110 
typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;//������������λΪ1�������x^(2^i)
		x=x*x%mod;
		n>>=1; 
	}
	return res;
}

//�ⷨ2���ݹ鷨
ll mod_pow(ll x,ll n,ll mod){
	if(n==0) return 1;
	ll res=mod_pow(x*x%mod,n/2,mod);
	if(n&1) res=res*x%mod;
	return res;
} 
