/*ͳ������n�Ķ�����չ������λ1������:O(logn)*/
int countOnes(unsigned int n){
	int ones=0;
	while(0<n){
		ones+=(1&n);//������λ��Ϊ1����� 
		n>>=1//����һλ,n���� 
	}
	return ones; 
} 
