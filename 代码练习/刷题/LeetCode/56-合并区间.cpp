//56-合并区间
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
//1.越写越麻烦 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        vector<vector<int> > res;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
			if(i>intervals.size()-1&&intervals[i][1]<intervals[i+1][0])
				res.push_back(intervals[i]);
			//两两合并去中间 
			else{
				set<int> st;
				st.insert(intervals[i][0]);
				st.insert(intervals[i][1]);
				st.insert(intervals[i+1][0]);
				st.insert(intervals[i+1][1]);
				st.erase(1);
				st.erase(1);
				vector<int> tmp;
				tmp.push_back(*st.begin());
				tmp.push_back(*st.rbegin());
				res.push_back(tmp);
			}
		}
    }
};

class Solution1{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals){
		if(intervals.empty()) return {};
		vector<vector<int>> res;
		sort(intervals.begin(),intervals.end());
		int i=1;
		for(;i<intervals.size();i++){
			if(intervals[i][0]>=intervals[i-1][0]&&intervals[i][0]<=intervals[i-1][1]){
				//如果有交集，就合并，并且将合并后的结果更新到自己身上，然后下一个
				//直到没有交集 
				intervals[i][0]=intervals[i-1][0];
				intervals[i][1]=max(intervals[i-1][1],intervals[i][1]);
			}
			else	res.push_back(intervals[i-1]);	//将上一个确定好的集合加入结果集 
		}
		res.push_back(intervals[i-1]);
		return res;
	}
};
int main(){
	return 0;
} 
