//77-组合 
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
//我的 ，又写不出来。。。。 
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> tmp; 
	void fun(int start,int n,int k){
		if(start>n) return;
		if(k==0){
			ret.push_back(tmp);
			tmp.pop_back();
			k+=1;
		}
		tmp.push_back(start);
		for(int i=start+1;i<=n+1;i++){
			fun(i,n,k-1);
		}
		tmp.pop_back(); 
	} 
    vector<vector<int>> combine(int n, int k) {
		for(int i=1;i<=n-k+1;i++){
			fun(i,n,k);		//计算以i开头的组合 
		}
		return ret;
    }
};

class Solution1{
public:
	void get_combine(vector<int> &nums,vector<int> &combine,
	vector<vector<int>> &ans,int k,int count,int p){
		if(count==k){
			ans.push_back(combine);	//count记录combine中数的个数
			return; 
		}	
		for(int i=p;i<nums.size();++i){
			combine.push_back(nums[i]);
			get_combine(nums,combine,ans,k,count+1,i+1);
			combine.pop_back();
		}
	}
	vector<vector<int>> combine(int n,int k){
		vector<int> nums,combine;
		vector<vector<int>> ans;
		for(int i=1;i<=n;i++) nums.push_back(i);	//num是1~n的数组
		get_combine(nums,combine,ans,k,0,0);
		return ans; 
	}
}; 
