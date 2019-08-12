//数组中数值和下标相等的元素 
class Solution{
	int GetNUmberSameAsIndex(const int* numbers,int length){
		if(numbers==nullptr||length<=0) return -1;
		int left=0;
		int right=length-1;
		while(left<=right){
			int middle=(left+right)>>2;
			if(middle==numbers[middle]) return middle;
			if(numbers[middle]>middle)	right=middle-1;
			else left=middle+1;
		}
		return -1;
	}
};
