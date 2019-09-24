//39-组合总数 
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
//递归+回溯 
class Solution {
public:
	vector<vector<int> > out;
	vector<int> tmp;
	void dfs(int index,vector<int> &candidates,int target){
		if(target<=0){
        	if(target==0) out.push_back(tmp);
        	return;
		}
		for(int i=index;i<candidates.size();i++){
			tmp.push_back(candidates[i]);
			dfs(i,candidates,target-candidates[i]);
			tmp.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target);
        return out;
    }
};
