//57-�������� 
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
	//�ϲ��ص������� 
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

//2.�½����� 
class Solution1 {
public:
//�½�������ӣ����ֲ���	
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& a) {
    	vector<vector<int>> v;
		auto it=A.begin();
		for(;it!=A.end()&&a[0]>(*it)[1];v.push_back(*it++));	//�ҵ��н������Ǹ��ط� 
		for(;it!=A.end()&&a[1]>=(*it)[0];++it)
			//����a
			a={min(a[0],(*it)[0]),max(a[1],(*it)[1])};
		v.push_back(a);
		v.insert(v.end(),it,A.end());		//�Ѻ���Ĳ������ 
		return v; 
    }
};

//3.ֱ����ԭ�����о͵غϲ�.���ֲ����ҵ���Ҫ�ϲ�����ʼλ��,Ȼ��͵غϲ�,
//ɾ���Ѿ��ϲ�������,����ϲ���ĵ�������.
class Solution2 {
	static bool comp(const vector<int> &a, const vector<int> &b){
		return a[1]<b[0];
	}
public:
	vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		int i=lower_bound(A.begin(),A.end(),a,comp)-A.begin(), j=0;
		for(j=i; j<A.size() && a[1]>=A[j][0]; ++j)	//��ʼλ�� 
			a={min(a[0],A[j][0]), max(a[1],A[j][1])};
		A.insert(A.begin()+j,a);
		A.erase(A.begin()+i, A.begin()+j);	//ɾ��ǰ���Ԫ�� 
		return A;
	}
}

