//72-编辑距离
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
//1.自底向上 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length(),len2=word2.length();
        int dp[len1+1][len2+1];		
        dp[0][0]=0;
        for(int j=1;j<=len2;j++) dp[0][j]=dp[0][j-1]+1;		//插入操作
		for(int i=1;i<=len1;i++) dp[i][0]=dp[i-1][0]+1;		//删除操作
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++) 
				if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];	//替换操作
				else dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1; 
				
		return dp[len1][len2];
    }
};

//2.自顶向下
class Solution1{
public:
	int minDistance(string word1,string word2){
		if(word1.empty()||word2.empty()) return word2.length()+word1.length();;
		if(word1[0]==word2[0]) return minDistance(word1.substr(1),word2.substr(2));
		else{
			int inserted=1+minDistance(word1,word2.substr(1));
			int deleted=1+minDistance(word1.substr(1),word2);
			int replace=1+minDistance(word1.substr(1),word2.substr(1));
			return min(min(inserted,deleted),replace);	
		}
	}
}; 
