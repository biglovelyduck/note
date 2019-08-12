//数组中唯一只出现一次的数字 
//只有一个数字出现了一次，其余的都是出现三次
int Find(int numbers[],int len){
	if(numbers==NULL||len<=0)
		throw new std::exception("invalid input.");
	int bitSum[32];
	for(int i=0;i<len;i++){
		int bitMask=1;	//重置bitmask 
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
