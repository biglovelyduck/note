//48-旋转图像
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
//1.转置加翻转，先转置矩阵，然后翻转每一行 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //转置 
        for(int i=0;i<n;i++)
        	for(int j=i;j<n;j++)
        		swap(matrix[i][j],matrix[j][i]);			
		//翻转每一行
		for(int i=0;i<n;i++){
			reverse(matrix[i].begin(),matrix[i].end());
		} 
    }
}; 

//2.旋转四个矩形，直观想法 
class Solution1{
public:
	void rotate(vector<vector<int> >& matrix){
	    int n = matrix.size();
	    for (int loop = 0; loop < n / 2; loop++)                    //外层循环：处理 n/2 层
	        for (int i = loop, j = loop; i < n - 1 - loop; i++) {   //中层循环：处理 n-1-loop次替换循环
	            int pre = matrix[i][j];
	            for (int time = 1; time <= 4; time++) {             //内层循环：处理 4 次替换过程
	                int tmpi = i; i = j; j = n - 1 - tmpi;
	                swap(pre, matrix[i][j]);
	            }
	        }
		}
};
