//71-��·�� 
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
#include <regex>
using namespace std;
//1.ջ���ַ����ָ� 
class Solution {
public:
	vector<string> split(const string &str, const char pattern)
	{
	    vector<string> res;
	    stringstream input(str);   
	    string temp;
	    while(getline(input, temp, pattern))
	        res.push_back(temp);
	    return res;
	}
	
    string simplifyPath(string path) {
		vector<string> s=split(path,'/'); 	//��ʱ������"·��"��""��"."��".."���������
		vector<string> sta;					//ջ 
		for(int i=0;i<s.size();i++){
			if(!sta.empty()&&s[i]=="..") sta.pop_back();
			else if(s[i]!=""&&s[i]!="."&&s[i]!="..") sta.push_back(s[i]);	//��·�� 
		}
		if(sta.empty()) return "/";
		string res;
		for(auto str:sta) res+="/"+str;
		return res;
    }
};
