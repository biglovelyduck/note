//快速幂运算，反复平方法
//我们把任意的1<x<n都有x^n≡x(mod n) 成立的合数（非素数）成为Carmichael Number,
//对于给定的整数n，判定他是不是CarMichael Number
// x^n≡x(mod n)表示两个数对n的取余相等
//2<n<65000 

//解析：如果n=2^k 则n=2^k1+2^k2+..
//例如x^22=x^16*x^4*x^2  22的二进制10110 
typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;//如果二进制最低位为1，则乘上x^(2^i)
		x=x*x%mod;
		n>>=1; 
	}
	return res;
}

//解法2：递归法
ll mod_pow(ll x,ll n,ll mod){
	if(n==0) return 1;
	ll res=mod_pow(x*x%mod,n/2,mod);
	if(n&1) res=res*x%mod;
	return res;
} 
