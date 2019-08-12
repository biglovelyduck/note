//和为s的数字
#include <vector>
#include <iostream>
using	namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	vector<int> v;
    	if(array.size()==0) return v;
        int i=0;
		int j=array.size()-1;
		int min=99999999;
		int i_,j_;
		while(i<j){
			int s=array[i]+array[j];
			if(s<sum) i++;
			else if(s>sum) j--;
			else{
				if(array[i]*array[j]<min){
					min=array[i]*array[j];
					i_=i;
					j_=j;
				}
			}
		}
		v.push_back(array[i_]);
		v.push_back(array[j_]); 
		return v;
    }
};
 
