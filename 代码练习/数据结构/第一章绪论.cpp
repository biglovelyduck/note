/*统计整数n的二进制展开中数位1的总数:O(logn)*/
int countOnes(unsigned int n){
	int ones=0;
	while(0<n){
		ones+=(1&n);//检查最低位，为1则计数 
		n>>=1//右移一位,n减半 
	}
	return ones; 
} 
