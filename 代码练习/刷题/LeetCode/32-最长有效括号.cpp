//32-最长有效括号
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
//没写出来 
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<char> stack; 
        int max=0,number=0;
        for(int i=0;i<s.size();i++){
        	if(s[i]=='('&&i+1<s.size()&&s[i+1]=='('){
				number=0;
        		stack.push('(');
			}
			else if(s[i]=='(')
				stack.push('(');
        	else{
        		//不是左括号就要先取出栈顶的元素配对一下
				if(stack.empty()||stack.top()==')'){
					number=0;
					continue;
				}
				else{
					stack.pop();
					number++;
					if(max<number) max=number;
					cout<<"当前字符:"<<s[i]<<"配对,num:"<<number<<endl;
				}
			}
		}
		return max*2;
    }
}; 

//两次遍历
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0;
        int mark = 0;
        for (int i = 0; i < s.size(); ++i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(i - left + 1, res);
                } else {
                    left = i + 1;
                }
            }
        }
        mark = 0;
        int right = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(right - i + 1, res);
                } else {
                    right = i - 1;
                }
            }
        }
        return res;
    }
}; 

//暴力 ,超时 
/*判断每个子串是否有效
例子:
"((())"

(( --> 无效
(( --> 无效
() --> 有效，长度为 2
)) --> 无效
((()--> 无效
(())--> 有效，长度为 4
最长长度为 4
*/
//总串可能是不合法的，子串 
class Solution2{
public:
	int longestValidParentheses(string s){
		int maxlen=0;
		for(int i=0;i<s.size();i++){
			for(int j=i+2;j<=s.length();j+=2){
				if(isValid(s.substr(i,j-i)))
					maxlen=max(maxlen,j-i);
			}
		} 
		return maxlen;
	}
	bool isValid(string s){	
		stack<int> stack;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				stack.push(s[i]);	
			}else if(!stack.empty()&&stack.top()=='('){
				stack.pop(); 
			}
			else return false;
		}
		return stack.empty();
	}
};

//动态规划
class Solution3{
public:
	int longestValidParentheses(string s){
		int maxans=0;
		int dp[s.size()];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<s.length();i++){
			if(s[i]==')'){
				if(s[i-1]=='(')
					dp[i]=(i>=2?dp[i-2]:0)+2;
				else if(i-dp[i-1]>0&&s[i-1-dp[i-1]]=='(')
					dp[i]= dp[i-1] +((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+2;
				maxans=max(maxans,dp[i]);
			}
		}
		return maxans;
	}
}; 

//栈
class Solution4{
public:
	int longestValidParenthess(string s){
		int maxans=0;
		stack<int> stack;
		stack.push(-1);
		for(int i=0;i<s.length();i++){
			if(s[i]=='(') stack.push(s[i]);
			else{
				stack.pop();
				if(stack.empty())
					stack.push(i);
				else
					maxans=max(maxans,i-stack.top());
			}
		}
		return maxans;
	}
}; 

//左右括号的计数器 
class Solution5{
public:
	int longestValidParentheses(string s){
		int left=0,right=0,maxlen=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(') left++;
			else right++;
			if(left==right) maxlen=max(maxlen,2*right);
			else if(right>=left) left=right=0;
		}
		left=right=0;
        for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='(') left++;
			else right++;
			if(left==right) maxlen=max(maxlen,2*left);
			else if(left>=right) left=right=0;
		}
		return maxlen;		 
	}
};
int main(){
	Solution5 s;
	cout<<s.longestValidParentheses("(()");
}
