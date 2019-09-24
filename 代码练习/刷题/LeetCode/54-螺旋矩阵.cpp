//54-��������
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
//1.ģ�� 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ans;
    	if(matrix.size()==0) return {};
    	int R=matrix.size(),C=matrix[0].size();
    	bool seen[R][C];
    	memset(seen,false,sizeof(seen));
    	int dr[]={0,1,0,-1};//�������� 
    	int dc[]={1,0,-1,0};
    	int r=0,c=0,di=0; 
    	//��һ����ѡ�ƶ�λ��(cr,cc) 
    	for(int i=0;i<R*C;i++){
    		//����ÿһ��λ��
			ans.push_back(matrix[r][c]);
			seen[r][c]=true;
			int cr=r+dr[di];
			int cc=c+dc[di];
			if(0<=cr&&cr<R&&0<=cc&&cc<C&&!seen[cr][cc]){
				r=cr;
				c=cc;
			} else{
				di=(di+1)%4;
				r+=dr[di];
				c+=dc[di];
			}
		}
		return ans;
    }
};

//2.����ģ��
class Solution1{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix){
		vector<int> ans;
		if(matrix.size()==0) return ans;
		int r1=0,r2=matrix.size()-1;		//���Ͻǵĵ�	 
		int c1=0,c2=matrix[0].size()-1;		//���½ǵĵ�
		while(r1<=r2&&c1<=c2){
			for(int c=c1;c<=c2;c++)	ans.push_back(matrix[r1][c]);
			for(int r=r1+1;r<=r2;r++) ans.push_back(matrix[r][c2]);
			if(r1<r2&&c1<c2)	//�м仹�в��
				for(int c=c2-1;c>c1;c--) ans.push_back(matrix[r2][c]);
				for(int r=r2;r>r1;r--)	ans.push_back(matrix[r][c1]); 
			r1++,c1++,r2--,c2--;
		} 
		return ans;
	}
};

//3.�߽�˼��
class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //������Ϊ�գ�ֱ�ӷ��ش�
        int u = 0; //��ֵ�������ұ߽�
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //�����ƶ�ֱ������
            if(++ u > d) break; //�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //����
            if(-- r < l) break; //�����趨�б߽�
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //����
            if(-- d < u) break; //�����趨�±߽�
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //����
            if(++ l > r) break; //�����趨��߽�
        }
        return ans;
    }
}; 

int main(){
	int m,n;
	//����m*n�Ķ�ά���� 
	int **arr=(int**)malloc(sizeof(int*)*m);
	for(int i=0;i<m;i++)	arr[i]=(int*)malloc(sizeof(int)*n);
	int **arr1=new int*[m];
	for(int i=0;i<m;i++)	arr1[i]=new int[n];
	//cout<<a[0]<<endl;
	return 0;
}
