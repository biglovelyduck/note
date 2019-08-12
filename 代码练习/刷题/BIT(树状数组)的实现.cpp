//BIT(树状数组)的实现 
//[1,n]
int bit[MAX_N+1],n;

//前i项的和 
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	} 
	return s;
} 

//更新第i项的值加上x
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
} 
