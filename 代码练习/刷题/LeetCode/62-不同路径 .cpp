//62-不同路径 
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
//写傻逼了，蒙了 
class Solution {
public:
	//n*m的表格，最终位置(n-1,m-1) 
	int dfs(int i,int j,int m,int n,bool **visited){
		cout<<"进来了"<<endl;
		visited[i][j]=true;		cout<<"i:"<<i<<"  j:"<<j<<endl;
		if(i==n-1&&m-1==j) return 0;
		if(i==n-1&&!visited[i][j+1]) return dfs(i,j+1,m,n,visited);
		if(j==m-1&&!visited[i+1][j]) return dfs(i+1,j,m,n,visited);
		return (visited[i+1][j]?0:dfs(i+1,j,m,n,visited)+1)+(visited[i][j+1]?0:dfs(i,j+1,m,n,visited)+1);
	}
	//m列n行 
    int uniquePaths(int m, int n) {
    	bool **visited=new bool*[m];
    	for(int i=0;i<n;i++) visited[i]=new bool[n];
    	memset(visited,false,sizeof(visited));
    	cout<<"初始化成功"<<endl;
        return dfs(0,0,m,n,visited); 
    }
};

//超时 
class Solution1{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			int paths = 0;
			paths += uniquePaths(m-1,n);
			paths += uniquePaths(m,n-1);
			return paths;
		}
};

//优化剪枝
static int a[101][101]={0};//记录已经计算过的路径，大大提高效率
class Solution{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			if(a[m][n] > 0)
				return a[m][n];
			a[m-1][n] =  uniquePaths(m-1,n);
			a[m][n-1] =  uniquePaths(m,n-1);
			a[m][n] = a[m-1][n]+a[m][n-1];
			return a[m][n];
		}
};

//DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]={0};
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int j=1;j<n;j++)
            dp[0][j]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


int main(){
	Solution s;
	cout<<s.uniquePaths(3,2);
	return 0;
}
