//6-最长回文子串 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//1.动态规划 ，状态压缩了 	babad->bab
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        int len=s.length();
        
        string res="";	
		//做了状态压缩
		bool* state=new bool[len];
		state[len-1]=true;
		for(int i=len-2;i>=0;i--){
			for(int j=len-1;j>=i;j--){
				if(i==j)
					state[j]=true;
				else if(s[i]==s[j]){ 
					if(i+1==j) state[j]=true;
					else state[j]=state[j-1];	//state[j]==state[i][j]
				} 
				else
					state[j]=false;
				if(state[j]&&(j-i+1)>res.length()) 
					res=s.substr(i,(j-i+1));
			}
		} 
		return res;
    }
};

//2.从中心扩展 ，注意：字符串的中心可能是多个相同的字符，所以每次处理以连续的相同字符为中心
 class Solution {
public:
    string longestPalindrome(string s) {
		if(s.length()<=1) return s;
		
		string res="";
		int j;
		for(int i=0;i<s.length();i++){
			//向右找到第一个不相等的字符 ,i~j-1为相同字符 
			for(j=i+1;j<s.length()&&s[j]==s[i];j++){
			}
			int len=longestPalindrome(s,i,j-1); 
			if(len>res.length())
				res+=s.substr(i-(len-(j-i))/2,len); 
		}
		return res;
	}
private:
	int longestPalindrome(const string& s,int i,int j){
		int l=i-1,r=j+1,len=s.length();
		int count=j-i+1;
		while(l>=0&&r<len&&s[l--]=s[r++]) count+=2;
		return count;
	}
};
