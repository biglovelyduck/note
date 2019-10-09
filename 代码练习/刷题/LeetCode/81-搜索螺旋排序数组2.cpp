//81-ËÑË÷ÂÝÐýÅÅÐòÊý×é2 
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
    bool search(vector<int>& nums, int target) {
    	sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        while(left<=right){
        	int mid=left+(right-left)/2;
        	if(nums[mid]==target) return true;
        	else if(nums[mid]>target) right=mid-1;
        	else left=mid+1;
		}
		return false;
    }
};

