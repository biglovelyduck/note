//33-搜索旋转排序数组 
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
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){	//分两种情况 
        	mid=start+(end-start)/2;
        	if(nums[mid]==target) return mid;
        	//前半部分有序，注意此处用小于等于
			if(nums[start]<=nums[mid]){
				//target在前半部分
				if(target>=nums[start]&&target<nums[mid])
					end=mid-1;
				else
					start=mid+1; 
			} 
			else{
				if(target<=nums[end]&&target>nums[mid]){
					start=mid+1; 
				}
				else{
					end=mid-1;
				} 
			} 
		}
		return -1;
    }
};

int main(){
	vector<int> nums={4,5,6,7,0,1,2};
	int target=0;
	Solution s;
	cout<<s.search(nums,target);
}
