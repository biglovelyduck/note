//数组中数字出现的次数56
//找到num的二进制第一位为1的位 
int FindFirstBitIs1(int num){
	int index=0;
	while((num&1)==0&&index<8*sizeof(int)){
		num>>1;
		index++;
	}
	return index;
}
//数字num在二进制中从右边开始第index个位是不是1 
bool isBit1(int num,int index){
	num=num>>index;
	return 1&num; 
}
void FindNumsAppearOnece(int data[],int len,ine *num1,int *num2){
	if(data==NULL||len<2) return ;
	int result=0;
	for(int i=0;i<len;i++)
		result^=data[i];
	int index=FindFirstBitIs1(result);
	*num1*num2=0;
	for(int i=0;i<len;i++){
		if(isBit1(data[i],index))
			*num1^=data[i];
		else
			*num2^=data[i];
	}
}
