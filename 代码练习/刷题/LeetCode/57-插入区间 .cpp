//57-插入区间 
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
	//合并重叠的区间 
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
	
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    	vector<vector<int>> res;
        if(intervals.empty()){
        	res.push_back(newInterval);
        	return res;
		}
        if(newInterval.empty()) return intervals;
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};

//2.新建数组 
class Solution1 {
public:
//新建数组添加，二分查找	
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& a) {
    	vector<vector<int>> v;
		auto it=A.begin();
		for(;it!=A.end()&&a[0]>(*it)[1];v.push_back(*it++));	//找到有交集的那个地方 
		for(;it!=A.end()&&a[1]>=(*it)[0];++it)
			//更新a
			a={min(a[0],(*it)[0]),max(a[1],(*it)[1])};
		v.push_back(a);
		v.insert(v.end(),it,A.end());		//把后面的插入进来 
		return v; 
    }
};

//3.直接在原数组中就地合并.二分查找找到需要合并的起始位置,然后就地合并,
//删除已经合并的区间,插入合并后的单个区间.
class Solution2 {
	static bool comp(const vector<int> &a, const vector<int> &b){
		return a[1]<b[0];
	}
public:
	vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		int i=lower_bound(A.begin(),A.end(),a,comp)-A.begin(), j=0;
		for(j=i; j<A.size() && a[1]>=A[j][0]; ++j)	//起始位置 
			a={min(a[0],A[j][0]), max(a[1],A[j][1])};
		A.insert(A.begin()+j,a);
		A.erase(A.begin()+i, A.begin()+j);	//删除前面的元素 
		return A;
	}
}

