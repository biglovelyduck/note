//44-通配符匹配
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
//动态规划
//1.状态：f[i][j]表示s1的前i个字符和s2的前j个字符能否匹配
//2.转移方程： 1)如果ij对应的字符相等或s2[j]=.		f[i][j]=f[i-1][j-1]
//				2)如果s2[j]为*，
//					1.若匹配空串，f[i][j]=f[i][j-1]		举例子：(a,a*) 
//					2.f[i][j]=f[i-1][j]
//3.初始化；f[0][i]=f[0][i-1]&&s2[i]==* 
class Solution {
public:
    bool isMatch(string s, string p) {
    	int m=s.size(),n=p.size(); 
//		//第一种方法 	
//		bool **f=new bool*[m+1];
//		for(int i=0;i<m+1;i++){
//			f[i]=new bool[n+1]; 
//			memset(f[i],false,sizeof(f));
//		}
//		//第二种方法：
//		bool **f=(bool**)malloc(sizeof(bool)*(m+1));
//		for(int i=0;i<m+1;i++){
//			f[i]=new bool[n+1]; 
//			memset(f[i],false,sizeof(f));
//		} 
//		//第三种方法
//		vector<vector<int> > swp(n);//表示二维数组有  4行  后面两个> >中间的空格不能省略
//		for(int i=0;i<n;i++)
//		{swp[i].resize(m);}//表示二维数组有   2列		

		bool f[m+1][n+1]={false};
		f[0][0]=true;
		for(int i=1;i<=n;i++){
			f[0][i]=f[0][i-1]&&p[i-1]=='*';
		}
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1]==p[j-1]||p[j-1]=='?') f[i][j]=f[i-1][j-1];
				if(p[j-1]=='*') f[i][j]=f[i][j-1]||f[i-1][j];
			}
		}
		return f[m][n];
	}
};

//暴力
class Solution1{
public:
	bool isMatch(string s,string p){
		int int start=0,i=0,last=0,j=0;
		while(i<s.length()){
			if(j<p.size()&&(s[i]==p[j]||p[j]=='?')) i++,j++;
			else if(j<p.size()&&p[j]=='*') last=i,start=++j;	//last保存当前i的位置，start保存*后面j的的位置 
			else if(start!=0)	i=++last,j=start;
			else return 0;
		}
		for(;j<p.size()&&p[j]=='*';++j);
		return j==p.size(); 
	}
}; 

int main(){
	Solution1 s;
	cout<<s.isMatch("abefcdgiescdfimde","ab*cd?i*de");
}
