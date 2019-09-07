//32-���Ч����
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
//ûд���� 
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
        		//���������ž�Ҫ��ȡ��ջ����Ԫ�����һ��
				if(stack.empty()||stack.top()==')'){
					number=0;
					continue;
				}
				else{
					stack.pop();
					number++;
					if(max<number) max=number;
					cout<<"��ǰ�ַ�:"<<s[i]<<"���,num:"<<number<<endl;
				}
			}
		}
		return max*2;
    }
}; 

//���α���
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

//���� ,��ʱ 
/*�ж�ÿ���Ӵ��Ƿ���Ч
����:
"((())"

(( --> ��Ч
(( --> ��Ч
() --> ��Ч������Ϊ 2
)) --> ��Ч
((()--> ��Ч
(())--> ��Ч������Ϊ 4
�����Ϊ 4
*/
//�ܴ������ǲ��Ϸ��ģ��Ӵ� 
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

//��̬�滮
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

//ջ
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

//�������ŵļ����� 
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
