//˳ʱ���ӡ����
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
    	//�����Ҵ�ӡ��һ��
		for(int i=start;i<=endX;i++){
			v.push_back(matrix[start][i]);
		} 
		//���ϵ��´�ӡ�ڶ���
		if(start<endY){
			for(int i=start+1;i<=endY;i++){
				v.push_back(matrix[i][endX]);
			}
		} 
		//���ҵ����ӡ������
		if(start<endX&&start<endY){
			for(int i=endX-1;i>=start;i--){
				v.push_back(matrix[endY][i]);
			}
		} 
		//���µ��ϴ�ӡ���Ĳ�
		if(start<endX&&start<endY-1){
			for(int i=endY-1;i>start;i--){
				v.push_back(matrix[i][start]);
			}
		} 
	}
};
