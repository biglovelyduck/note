//������Ψһֻ����һ�ε����� 
//ֻ��һ�����ֳ�����һ�Σ�����Ķ��ǳ�������
int Find(int numbers[],int len){
	if(numbers==NULL||len<=0)
		throw new std::exception("invalid input.");
	int bitSum[32];
	for(int i=0;i<len;i++){
		int bitMask=1;	//����bitmask 
		for(int j=31;j>=0;j--){
			if(bitMask&numbers[i])	bitSum[j]+=1; 
			bitMask<<=1;
		}	
	}
	int result=0;
	for(int i=0;i<32;i++){
		result=result<<1;
		result+=bitSum[i]%3;
	}
} 
