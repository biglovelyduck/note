//9-������ʽƥ��
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std; 

//1.�ݹ� 
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length()>1&&p[1]=='*')
        	return isMatch(s,p.substr(2))||
			(!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p));
		else return !s.empty() && (s[0]==p[0]||p[0]=='.') &&
                    isMatch(s.substr(1),p.substr(1));
    }
};

//2.��̬�滮
class Solution{
public:
bool isMatch(string s, string p) {
		if(p.empty()) return s.empty();
        int len1 = s.length(),len2 = p.length();
        
        bool **state = new bool*[len1 + 1];
        for(int i = 0;i <= len1;i++)
            state[i] = new bool[len2 + 1];
        
        //��һ�У�p = ""
        state[0][0] = true;
        for(int i = 1;i <= len1;i++)    state[i][0] = false;
        
        //��һ�У�s = ""
        state[0][1] = false;
        for(int j = 2;j <= len2;j++)    
			state[0][j] = (p[j - 1] == '*') ? (state[0][j - 2]) : false;
		//state[i][j]��ʾs[0~i-1]�ܷ��p[0~j-1]ƥ���� 
		for(int i = 1;i <= len1;i++)
            for(int j = 1;j <= len2;j++){
                if(p[j - 1] == '*')		//��ʱp[j-2]����ʹ��Ҳ���Բ�ʹ�� 
                	//��ʹ�ã�state[i][j] = state[i][j - 2]
					//ʹ�ã�state[i][j] = ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && state[i - 1][j]) 
                    state[i][j] = state[i][j - 2] || ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && state[i - 1][j]);
                else if(p[j - 1] == '.')
                    state[i][j] = state[i - 1][j - 1];
                else
                    state[i][j] = (p[j - 1] == s[i - 1]) && state[i - 1][j - 1];
            }
        
        return state[len1][len2]; 
	}
}; 
