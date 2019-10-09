//74-搜索二维矩阵 
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
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row=matrix.size(),col=matrix[0].size();
        vector<int> v;
        for(int i=0;i<row;i++)
        	for(int j=0;j<col;j++)
        		v.push_back(matrix[i][j]);
        //二分查找
		int left=0,right=v.size()-1;
		while(left<=right){
			int mid=left+(right-left)/2;
			if(v[mid]==target) return true;
			else if(v[mid]>target) right=mid-1;
			else left=mid+1;
		} 
		return false;
    }
};
