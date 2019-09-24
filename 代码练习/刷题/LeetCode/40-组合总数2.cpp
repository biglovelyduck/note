//40-组合总数2 
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
	set<vector<int> > s;
	vector<vector<int> > v;
	vector<int> tmp;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        for(auto i:s) v.push_back(i);
        return v;
    }
    void dfs(int index,vector<int>& candidates,int target){
    	if(target==0){
    		//sort(tmp.begin(),tmp.end());
    		s.insert(tmp);
			return;
		}
    	if(target<0) return;
    	for(int i=index;i<candidates.size();i++){
    		tmp.push_back(candidates[i]);
    		dfs(i+1,candidates,target-candidates[i]);
    		tmp.pop_back();
		}
	}
};
int main(){
	return 0;
}
