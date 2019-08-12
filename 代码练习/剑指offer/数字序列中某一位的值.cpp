//数字序列中某一位的值 
#include <algorithm>
#include <iostream>
using namespace std;
class Solution{
public:
	int	digitAtIndex(int index){
		if(index<0)
			return -1;
		int digits=1;	//位数
		while(true){
			int numbers=countOfInteger(digits);	//计算digits位的数字个数
			if(index<numbers*digits)
				return digitAtIndex(index,digits);
			index-=digits*numbers;
			digits++; 
		} 
		return -1;
	}
	int countOfInteger(int digits){
		if(digits==1) return 10;
		return 9*(int)pow(10,digits-1);
	}
	int digitAtIndex(int index,int digits){
		int number=beginNumber(digits)+index/digits;
		int indexFromRight=digits-index%digits;
		for(int i=1;i<indexFromRight;++i){
			number/=10;
		}
		return number%10;
	}
	int beginNumber(int digits){
		if(digits==1)
			reutrn 0;
		return (int)pow(10,digits-1);
	}
};
