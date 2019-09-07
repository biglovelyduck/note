//26-删除排序数组中的重复项
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
using namespace std; 
//双指针 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
        	if(nums[j]!=nums[i]){
        		nums[++i]=nums[j];
			}
			//如果相等的话j就会继续增加 
		}
		return i+1; 
    }
}; 
