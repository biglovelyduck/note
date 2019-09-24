//49-×ÖÄ¸ÒìÎ»´Ê·Ö×é
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
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0) return {};
        map<string,vector<string> > mp;
        for(int i=0;i<strs.size();i++){
        	string s=strs[i];
        	sort(strs[i].begin(),strs[i].end());
        	mp[strs[i]].push_back(s);
		}
		vector<vector<string> > v;
		for(map<string,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
			v.push_back(it->second);
		return v;
    }
}; 
