//第k个排列 
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
//1.递归回溯 ，超时 
class Solution {
public:
	void all_permutation(string s,int start,vector<string> &v){
		if(start==s.size()-1){
			 v.push_back(s);
			 return;
		}
		for(int i=start;i<s.size();i++){
			swap(s[i],s[start]);
			all_permutation(s,start+1,v);
			swap(s[i],s[start]);
		}
	}
	
    string getPermutation(int n, int k) {
        vector<string> v;
        string s="";
        for(int i=1;i<=n;i++) s+=to_string(i);
		all_permutation(s,0,v);
		//for(auto i:v) cout<<i<<endl;
		sort(v.begin(),v.end());
		return v[k-1];
    }
};

int main(){
	Solution s;
	cout<<s.getPermutation(3,5);
	return 0;
}
