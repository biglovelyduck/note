//56-�ϲ�����
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
//1.ԽдԽ�鷳 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        vector<vector<int> > res;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
			if(i>intervals.size()-1&&intervals[i][1]<intervals[i+1][0])
				res.push_back(intervals[i]);
			//�����ϲ�ȥ�м� 
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
				//����н������ͺϲ������ҽ��ϲ���Ľ�����µ��Լ����ϣ�Ȼ����һ��
				//ֱ��û�н��� 
				intervals[i][0]=intervals[i-1][0];
				intervals[i][1]=max(intervals[i-1][1],intervals[i][1]);
			}
			else	res.push_back(intervals[i-1]);	//����һ��ȷ���õļ��ϼ������� 
		}
		res.push_back(intervals[i-1]);
		return res;
	}
};
int main(){
	return 0;
} 
