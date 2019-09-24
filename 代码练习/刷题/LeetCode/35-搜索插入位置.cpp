//35-搜索插入位置
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
//1.循环搜索 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0) return 0;
        for(int i=0;i<len;i++)
        	if(nums[i]>=target) return i;
        return len;
    }
}; 

//2.二分查找
class Solution{
public:
	int searchInsert(vector<int>& nums,int traget){
		int left=0;
		int right=nums.size()-1;
		int mid=0;
		while(left<right){
			mid=left+(right-left)/2;
			if(target<nums[mid]) right=mid-1;
			else if(target>nums[mid]) left=mid+1;
			else return mid;
		}
		if(target<=nums[left]) return left;	//插入在开头的情况 
		return left+1; 						//插入在结尾的情况 
	}
}; 
