//顺时针打印矩阵
#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> v;
		int rows=matrix.size();
		int columns=matrix[0].size();
		int start=0;
		while(columns>start*2&&rows>start*2){
			PrintMatrixCircle(matrix,v,columns,rows,start);
			++start;
		}
		return v;
    }
    void PrintMatrixCircle(vector<vector<int> > matrix,vector<int>& v,int columns,int rows,
							int start){
    	int endX=columns-1-start;
    	int endY=rows-1-start;
    	//从左到右打印第一步
		for(int i=start;i<=endX;i++){
			v.push_back(matrix[start][i]);
		} 
		//从上到下打印第二步
		if(start<endY){
			for(int i=start+1;i<=endY;i++){
				v.push_back(matrix[i][endX]);
			}
		} 
		//从右到左打印第三步
		if(start<endX&&start<endY){
			for(int i=endX-1;i>=start;i--){
				v.push_back(matrix[endY][i]);
			}
		} 
		//从下到上打印第四步
		if(start<endX&&start<endY-1){
			for(int i=endY-1;i>start;i--){
				v.push_back(matrix[i][start]);
			}
		} 
	}
};
