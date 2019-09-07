//20-ÓÐÐ§µÄÀ¨ºÅ
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
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> sta;
        map<char,char> mp={{'(',')'},{'[',']'},{'{','}'}};
        for(int i=0;i<s.length();i++){
        	if(s[i]=='('||s[i]=='['||s[i]=='{')	sta.push(s[i]);//cout<<"pushed"<<endl;
        	else if(s[i]==')'||s[i]==']'||s[i]=='}'){
        		if(sta.empty()) return false;
        		if(sta.top()-'0'+1==s[i]-'0') sta.pop();
        		else return false;
			}
			else
				return false;
		}
		if(sta.empty())
			return true;
		else return false;
    }
};

int main(){
	Solution s;
	cout<<s.isValid("[]");
	return 0;
}
