//85-最大矩形 
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
//超时 ,思路不对 
class Solution {
public:
	int get_area(int i,int j,vector<vector<char>>& matrix,int row,int col){
		int end_i=i,end_j=j;
		while(end_j<col-1&&matrix[i][end_j+1]=='1') end_j++;	
		int min_i=INT_MAX;
		for(int k=j;k<=end_j;k++){
			end_i=i;
			while(end_i<row-1&&matrix[end_i+1][k]=='1') end_i++;
			min_i=min(end_i,min_i);	
		}	
		return (end_j-j+1)*(min_i-i+1);
	}
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.empty()) return 0;
        int row=matrix.size(),col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(matrix[i][j]=='1'){	
        			int area=get_area(i,j,matrix,row,col);
        			ans=max(ans,area);
				}
			}
		}
		return ans;
    }
};

//1.暴力，遍历每个矩阵，判断是否全部是1 
//2.DP
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.empty()) return 0;
		int maxarea=0;
		int dp[matrix.size()][matrix[0].size()];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[0].size();j++){
				if(matrix[i][j]=='1'){
					dp[i][j]=(j==0)?1:dp[i][j-1]+1;
					int width=dp[i][j];	//连续1的宽度
					for(int k=i;k>=0;k--){
						width=min(width,dp[k][j]);
						maxarea=max(maxarea,width*(i-k+1));
					} 
				}
			} 
		} 
		return maxarea;
    }
}; 

int main(){
	vector<vector<char>> v={
	{'1','0'},{'1','0'}
	};
	Solution s;
	cout<<s.maximalRectangle(v);
	return 0;
} 
