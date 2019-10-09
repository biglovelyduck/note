//64-��С·���� 
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
//�ҵ�DP 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int dp[row][col];
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<row;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int j=1;j<col;j++) dp[0][j]=grid[0][j]+dp[0][j-1];
        for(int i=1;i<row;i++)
        	for(int j=1;j<col;j++)
        		dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        return dp[row-1][col-1];
    }
};
