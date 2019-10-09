//73-æÿ’Û÷√0
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
    void setZeroes(vector<vector<int>>& matrix) {
    	if(matrix.empty()) return;
        int row=matrix.size();
        int col=matrix[0].size();
        bool r[row],c[col],visited[row][col];
        memset(r,false,sizeof(r));
        memset(c,false,sizeof(c));
        vector<vector<int>> v=matrix;
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if((r[i]||c[j])&&v[i][j]!=0) continue;
        		if(matrix[i][j]==0){
        			r[i]=true;
        			c[j]=true;
        			for(int k=0;k<col;k++) matrix[i][k]=0;
        			for(int k=0;k<row;k++) matrix[k][j]=0;
				}
			}
		}
    }
}; 
