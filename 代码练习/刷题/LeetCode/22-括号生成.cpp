//22-��������
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

//1.������ +��֦
/*1.��������ű������Ŷ࣬˵����Ч�򷵻�
2.�����������������N���������ⲻ��������
3.����������Ŷ��ﵽ��ָ������������Խ�����ӵ������б���
4.�������������û�����㣬���Լ����µ������ź�������
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

//��̬�滮,p�������ڣ�q�������� 
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {		//��ʼ�����i�����ŵ�������� 
			for (int j = 0; j <i; j++) {	//��i��=p���������+q��������� 
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
