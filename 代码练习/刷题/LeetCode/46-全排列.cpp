//46-È«ÅÅÁĞ 
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
using namespace std;
class Solution {
public:
	vector<vector<int>> v;
    vector<vector<int>> permute(vector<int>& nums) {
        permute1(nums,0);
        return v;
    }
    
	void permute1(vector<int> &nums,int start){
		if(start==nums.size()-1){
			v.push_back(nums);
			return;
		}
		for(int i=start;i<nums.size();i++){
			swap(nums[start],nums[i]);
			permute1(nums,start+1);
			swap(nums[start],nums[i]);
		}
	}
};

class Solution1{
public:
	vector<vector<int>> v;
    vector<vector<int>> permute(vector<int>& nums){
    	sort(nums.begin(),nums.end());
    	do{
    		v.push_back(nums);
		}while(next_permutation(nums.begin(),nums.end()));
		return v;
	}
};
