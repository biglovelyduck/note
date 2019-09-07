//18-四数之和
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
using namespace std;


//要合理利用剪枝就可以排去重复，不用使用set 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> vv;
    	set<vector<int> > s;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return {};
        int len=nums.size();
        for(int i=0;i<len-3;i++){
        	//去重，剪枝
			if(i>0&&nums[i]==nums[i-1]) continue; 
			//如果第一个固定数和后面三个最小数的和大于target，跳出
			if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break; 
			//如果第一个固定数和后面三个最大数的和小于target，进入下一个遍历 
			if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
        	for(int j=i+1;j<len-2;j++){
        		//去重，剪枝
				if(j-i-1>0&&nums[j]==nums[j-1]) continue; 
				//如果前两个固定数和后面两个个最小数的和大于target，跳出
				if(nums[i]+nums[j]+nums[j+1]+nums[j+1]>target) break; 
				//如果前两个固定数和后面两个个最大数的和小于target，进入下一个遍历
				if(nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;  
        		int start=j+1,end=len-1;
        		while(start<end){
        			int sum=nums[i]+nums[j]+nums[start]+nums[end];
        			vector<int> v;
        			if(sum==target){
        				v.push_back(nums[i]);
        				v.push_back(nums[j]);
        				v.push_back(nums[start]);
        				v.push_back(nums[end]);
        				sort(v.begin(),v.end());
        				s.insert(v);
        				//vv.push_back(v);
        				start++,end--;
					}
					else if(sum>target) end--;
					else start++;
				}
			}
		}
    	for(auto v:s){
    		vv.push_back(v);
		}
		return vv;
	}
};
