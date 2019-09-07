//31-下一个排列 
//完全没思路，可以求出所有的排列，然后找到下一个 
//思路：
/*从后向前找到第一个小于前面的元素，然后在后面找到刚比这个数大的元素交换，然后反转后面*/ 
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
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i=0, j=0;
		for(i=nums.size()-1; i && nums[i-1]>=nums[i]; --i);
		if(i){
			for(j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
			swap(nums[i-1],nums[j]);
		}
		reverse(nums.begin()+(i-1==j?0:i),nums.end());
	}
};

