//5068. 前后拼接
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
	string first(string &s){
		if(s.empty()) return NULL;
		if(s.size()==1) return s; 
		return s.substr(0,s.find_first_of(' '));
	}
	string last(string &s){
		if(s.empty()) return NULL;
		if(s.size()==1) return s; 
		return s.substr(s.find_last_of(' ')+1);
	}
	//返回第一个单词之后的字符串 
	string returnLess(string &s){
		if(s.empty()) return NULL;
		return s.substr(s.find_first_of(' '));
	}
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        if(phrases.empty()) return {};
        set<string> s;
        vector<string> v;
        for(int i=0;i<phrases.size();i++){
        	for(int j=0;j<phrases.size();j++){
        		if(i==j) continue;
        		if(last(phrases[i])==first(phrases[j])){	//尾首呼应 
        			if(phrases[i].size()==1) s.insert(phrases[i]);
        			else s.insert(phrases[i]+returnLess(phrases[j]));
				}
			}
		}
		for(auto i:s)
			v.push_back(i);
		return v;	
    }
};

int main(){
	Solution s;
	vector<string> phrases={"mission statement",
                "a quick bite to eat",
                "a chip off the old block",
                "chocolate bar",
                "mission impossible",
                "a man on a mission",
                "block party",
                "eat my words",
                "bar of soap"};
    vector<string> p1={"a","b","a"};
    vector<string> p2={"writing code","code rocks"}; 
	vector<string> v= s.beforeAndAfterPuzzles(p2);
	for(auto i:v){
		cout<<i<<endl;
	}
	return 0;
}
