//和为s的连续正数序列
#include <vector>
#include <iostream>
using	namespace std;
class Solution{
	void print(int small,int big){
		for(int i=small;i<=big;i++){
			cout<<i<<" ";
		}
	}
	void Find(int sum){
		if(sum<3) return;
		int small=1;
		int big=2;
		int middle=(1+sum)/2;
		int curSum=small+big;
		while(small<middle){
			if(curSum==sum)
				print(small,big);
			while(curSum>sum&&small<middle){
				curSum-=small;
				small++;
				if(curSum==sum)
					print(small,big);
			}
			big++;
			curSum+=big;
		} 
	}
};
 
