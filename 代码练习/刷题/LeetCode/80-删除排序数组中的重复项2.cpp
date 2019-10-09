//80-删除排序数组中的重复项2 
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
#include <queue>
#include <regex>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		//肯定用双指针
		if(nums.size()<=1) return nums.size();
		int current=1;	//新数组中有效位置的最后 一位
		for(int i=2;i<nums.size();i++){
			if(nums[i]!=nums[current-1]){
				current+=1;
				nums[current]=nums[i];
			}
		} 
		return current+1;
    }
};
