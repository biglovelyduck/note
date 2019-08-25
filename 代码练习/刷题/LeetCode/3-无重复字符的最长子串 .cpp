//3-无重复字符的最长子串 
#include <bits/stdc++.h>
#include <set>
#include <string>
#include <map>
using namespace std;
//超时 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.length()==0) return 0;
        int n=s.length();
        int ans=1;
        for(int i=0;i<n;i++){
        	for(int j=i+1;j<n;j++){
        		if(allUnique(s,i,j))	ans=max(ans,j-i+1);
			}
		}
		return ans;
    }
    bool allUnique(string &s,int start,int end){
		set<char> ss;
		for(int i=start;i<=end;i++){
			if(ss.count(s[i])) return false;
			ss.insert(s[i]);
		}
		return true;
	}
};
//滑动窗口 
class Solution1{
public:
	int lengthOfLongestSubstring(string s){
		//if(s.length()==0) return 0;
		int n=s.length();
		set<char> ss;
		int ans=0,i=0,j=0;
		while(i<n&&j<n){
			if(!ss.count(s[j])){
				ss.insert(s[j++]);
				ans=max(ans,j-i);
			}
			else{
				ss.erase(s[i++]);
			}
		}
		return ans;
	}
}; 

//滑动窗口优化:当我们找到重复的字符时，我们可以立即跳过该窗口。
class Solution2{
public:
	int lengthOfLongestSubstring(string s){
		int n=s.length(),ans=0;
		map<char,int> m;
		for(int j=0,i=0;j<n;j++){
			if(m.count(s[j])>0)
				i=max(m[s[j]],i);
			ans=max(ans,j-i+1);
			m.insert(pair<char,int>(s[j],j+1));
		}
		return ans;	
	}
}; 
