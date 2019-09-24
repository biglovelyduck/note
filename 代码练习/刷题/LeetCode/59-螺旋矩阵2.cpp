//59-螺旋矩阵2
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
//1.直接模拟 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	if(n==0) return {};
        vector<vector<int>> ret(n);
        for(int i=0;i<n;i++) ret[i].resize(n);
		bool seen[n][n];
		memset(seen,false,sizeof(seen));
		int dr[]={0,1,0,-1};	//上右下左 
		int dc[]={1,0,-1,0};
		int r=0,c=0,di=0,num=1;
		for(int i=0;i<n*n;i++){	//挨个遍历每个点 
			seen[r][c]=true;
			ret[r][c]=num++;
			int next_r=r+dr[di];
			int next_c=c+dc[di];
			if(0<=next_r&&next_r<n&&next_c>=0&&next_c<n&&!seen[next_r][next_c]){
				r=next_r;
				c=next_c;
			}
			else{
				di=(di+1)%4;
				r+=dr[di];
				c+=dc[di];
			}
		}
        return ret;
    }
};

//2.按层模拟
class Solution1{
public:
    vector<vector<int>> generateMatrix(int n){
    	if(n==0) return {};
    	vector<vector<int>> ret(n);
    	for(int i=0;i<n;i++) ret[i].resize(n);
    	int r1=0,r2=n-1,c1=0,c2=n-1,num=1;
    	while(r1<=r2&&c1<=c2){	//左上角和右下角的点不重叠 
    		for(int c=c1;c<=c2;c++) ret[r1][c]=num++;
    		for(int r=r1+1;r<=r2;r++) ret[r][c2]=num++;
    		//if(r1<r2&&c1<c2)	//中间还有层次 
    		for(int c=c2-1;c>c1;c--) ret[r2][c]=num++;
    		for(int r=r2;r>r1;r--) ret[r][c1]=num++;
    		r1++,c1++,r2--,c2--;
		}
		return ret;
	}	
}; 
