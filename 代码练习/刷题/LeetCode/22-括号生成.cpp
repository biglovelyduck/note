//22-括号生成
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
using namespace std; 

//1.暴力法 +剪枝
/*1.如果右括号比左括号多，说明无效则返回
2.如果左括号数量超过N，则与题意不符，返回
3.如果左右括号都达到了指定数量，则可以将其添加到数组中保存
4.如果以上条件都没有满足，则尝试加入新的左括号和右括号
*/ 
class Solution {
public:
	int N;
	vector<string> ans;
	void dfs(int l,int r,string has){
		if(r>l) return;
		if(l>N) return;
		if(l==r&&r==N){
			ans.push_back(has);
			return;
		}
		dfs(l+1,r,has+"(");
		dfs(l,r+1,has+")");
	}
    vector<string> generateParenthesis(int n) {
    	N=n;
		if(!N) return {};
		dfs(0,0,"");
		return ans;   
    }
}; 

//动态规划,p在括号内，q在括号外 
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {		//开始计算第i组括号的排列组合 
			for (int j = 0; j <i; j++) {	//第i组=p的排列组合+q的排列组合 
				for (string p : dp[j])	
					for (string q : dp[i - j - 1]) {
						string str = "(" + p + ")" + q;
						dp[i].push_back(str);
					}
			}
		}
		return dp[n];
	}
}; 
