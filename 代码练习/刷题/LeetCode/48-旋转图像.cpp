//48-��תͼ��
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
//1.ת�üӷ�ת����ת�þ���Ȼ��תÿһ�� 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //ת�� 
        for(int i=0;i<n;i++)
        	for(int j=i;j<n;j++)
        		swap(matrix[i][j],matrix[j][i]);			
		//��תÿһ��
		for(int i=0;i<n;i++){
			reverse(matrix[i].begin(),matrix[i].end());
		} 
    }
}; 

//2.��ת�ĸ����Σ�ֱ���뷨 
class Solution1{
public:
	void rotate(vector<vector<int> >& matrix){
	    int n = matrix.size();
	    for (int loop = 0; loop < n / 2; loop++)                    //���ѭ�������� n/2 ��
	        for (int i = loop, j = loop; i < n - 1 - loop; i++) {   //�в�ѭ�������� n-1-loop���滻ѭ��
	            int pre = matrix[i][j];
	            for (int time = 1; time <= 4; time++) {             //�ڲ�ѭ�������� 4 ���滻����
	                int tmpi = i; i = j; j = n - 1 - tmpi;
	                swap(pre, matrix[i][j]);
	            }
	        }
		}
};
