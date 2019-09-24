//34-在排序数组中查找元素的第一个和最后一个位置
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
	int findFirst(vector<int>& nums,int target){
		int left=0;
		int right=nums.size()-1;
		int mid;
		while(left<=right){
			mid=left+(right-left)/2;
			if(target<=nums[mid]) right=mid-1;
			else left=mid+1;
		}
		if(left<nums.size()&&nums[left]==target) return left;
		return -1;
	}
	int findLast(vector<int> &nums,int target){
		int left=0;
		int right=nums.size()-1;
		int mid;
		while(left<=right){
			mid=left+(right-left)/2;
			if(target<nums[mid]) right=mid-1;
			else left=mid+1; 
		}
		if(right>=0&&nums[right]==target) return right;
		return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> v;
        if(nums.size()==0) return {-1,-1};
		v.push_back(findFirst(nums,target));
		v.push_back(findLast(nums,target));
		return v;
    }
};

int main(){
	Solution s;
	vector<int> nums={5,7,7,8,8,10};
	int target=6;
	vector<int> v=s.searchRange(nums,target);
	for(auto i:v) cout<<i<<" ";
	return 0;
}
