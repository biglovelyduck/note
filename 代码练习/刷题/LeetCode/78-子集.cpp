//78-子集
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
//1.位运算 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int S=nums.size();
		int N=1<<S;
		vector<vector<int>> res;
		for(int i=0;i<N;i++){
			vector<int> v;
			for(int j=0;j<S;j++){
				if(i&(1<<j)) v.push_back(nums[j]);
			}
			res.push_back(v);
		} 
    }
}; 

//2.未剪枝回溯法 ，二叉树，选或者不选,没看懂 
class Solution1{
public:
	void compute(vector<vector<int>>& ret,vector<int> &nums,vector<int>& now,int i){
		if(i>=nums.size()) return;	//i=3跳出 
		now.push_back(nums[i]);		//1
		ret.push_back(now);	//1,12,123,		
		compute(ret,nums,now,i+1);
		now.pop_back();//12
		compute(ret,nums,now,i+1);
		return;
	}
	vector<vector<int>> subsets(vector<int>& nums){	//1,2,3
		vector<vector<int>> ret;	//保存最终结果
		vector<int> now={};
		ret.push_back(now);
		compute(ret,nums,now,0);
		return ret; 
	}
}; 

//3.层次遍历
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res(1);
        for(int i=0;i<nums.size();i++){
            int cnt=res.size();
            for(int j=0;j<cnt;j++){
                vector<int> tmp=res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

//4.回溯
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res,tmp,nums,0);
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
        if(tmp.size()<=nums.size()){
            res.push_back(tmp);
        }
        for(int i=level;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};

//5.dfs
void helper(vector<vector<int> >& res, vector<int> tmp, vector<int>& nums, int level) {
	if (level >= nums.size()) {
		res.push_back(tmp);
		return;
	}
	tmp.push_back(nums[level]);
	helper(res, tmp, nums, level + 1);
	tmp.pop_back();
	helper(res, tmp, nums, level + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int> > res;
	vector<int> tmp;
	helper(res, tmp, nums, 0);
	return res;
}


