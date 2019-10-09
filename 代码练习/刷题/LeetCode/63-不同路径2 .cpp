//63-不同路径2 
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
//不会写 
class Solution {
public:
	bool visited[101][101];
	int dfs(int i,int j,vector<vector<int>>& obstacleGrid){
		visited[i][j]=true;
		int row=obstacleGrid.size(),col=obstacleGrid[0].size();
		if(i==row-1&&j==col-1) return 0;
		int sum=0;
		if(i+1<row&&!visited[i+1][j]&&!obstacleGrid[i+1][j]){
			dfs(i+1,j,obstacleGrid);
			sum+=1;
		}
		if(j+1<col&&!visited[i][j+1]&&!obstacleGrid[i][j+1]){
			dfs(i,j+1,obstacleGrid);
			sum+=1;
		}
		return sum;
	}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int row=obstacleGrid.size(),col=obstacleGrid[0].size();
    	if(row==col&&row==1&&obstacleGrid[0][0]==0) return 1;
    	if(row==col&&row==1&&obstacleGrid[0][0]==1) return 0;
    	memset(visited,false,sizeof(visited));
        return dfs(0,0,obstacleGrid);
    }
};

//DP
class Solution1{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
		int row=obstacleGrid.size(),col=obstacleGrid[0].size();
		static long long dp[101][101];
		dp[0][0]=obstacleGrid[0][0]==1?0:1;
		for(int i=1;i<row;i++) dp[i][0]=obstacleGrid[i][0]==1?0:dp[i-1][0];
		for(int j=1;j<col;j++) dp[0][j]=obstacleGrid[0][j]==1?0:dp[0][j-1];
		for(int i=1;i<row;i++)
			for(int j=1;j<col;j++)
				dp[i][j]=obstacleGrid[i][j]==1?0:dp[i-1][j]+dp[i][j-1];
		return dp[row-1][col-1];
	}
};
