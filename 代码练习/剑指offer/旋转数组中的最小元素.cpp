//旋转数组中的最小元素 
//利用旋转数组数组的特性来求出最小值
#include <iostream>
#include <vector>
using namespace std; 
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
        	return 0;
        int index1=0;
        int index2=rotateArray.size()-1;
        int indexMid=index1;
        while(rotateArray[index1]>=rotateArray[index2]){
        	if(index2-index1==1){
        		indexMid=index2;
        		break;
			}
			indexMid=(index1+index2)/2;
			//如果下标三个值数字相等，只能顺序查找
			if(rotateArray[index1]==rotateArray[index2]&&
				rotateArray[indexMid]==rotateArray[index1])
				return MinInOrder(rotateArray,index1,index2); 
			if(rotateArray[indexMid]>=rotateArray[index1])
				index1=indexMid;
			else if(rotateArray[indexMid]<=rotateArray[index2])
				index2=indexMid;
		}
		return rotateArray[indexMid];
    }
    int MinInOrder(vector<int> v,int index1,int index2){
    	int result=v[index1];
    	for(int i=index1+1;i<=index2;++i){
    		if(result>v[i])
    			v[i]=result;
		}
		return result;
	}
}; 
