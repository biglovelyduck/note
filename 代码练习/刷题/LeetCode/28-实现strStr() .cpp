//28-实现strStr() 
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
//没写出来 
class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.empty()) return 0;
    	if(haystack.empty()) return -1;
        int i=0,j=0;
        while(i<haystack.size()&&j<needle.size()){
        	if(haystack[i]==needle[j])
    			cout<<needle[j]<<endl,i++,j++;
    		else
			{
				if(haystack[i]==needle[0]) i++,j=1;
				else i++,j=0;
			}
		}
		if(j==needle.size()&&i<=haystack.size()) return i-needle.size();
		cout<<"?"<<endl;
		return -1;
    }
};
//1.库函数
class Solution{
public:
	int strStr(string haystack,string needle){
		if(needle.empty()) return 0;
		int pos=haystack.find(needle);
		return pos;
	}
}; 
//2.BF暴力
class Solution{
public:
	int strStr(string haystack,string needle){
		if(needle.empty()) return 0;
		int i=0,j=0;
		while(haystack[i]!='\0'&&needle[j]!='\0'){
			if(haystack[i]==needle[j]) i++,j++;
			else i=i-j+1,j=0;
		}
		if(needle[j]=='\0') return i-j;
		return -1;
	}
}; 
//3.KMP
class Solution {
public:
    vector<int> getnext(string str)
        {
            int len=str.size();
            vector<int> next;
            next.push_back(-1);//next数组初值为-1
            int j=0,k=-1;
            while(j<len-1)
            {
                if(k==-1||str[j]==str[k])//str[j]后缀 str[k]前缀
                {
                    j++;
                    k++;
                    next.push_back(k);
                }
                else
                {
                    k=next[k];
                }
            }
            return next;
        }
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        int i=0;//源串
        int j=0;//子串
        int len1=haystack.size();
        int len2=needle.size();
        vector<int> next;
        next=getnext(needle);
        while((i<len1)&&(j<len2))
        {
            if((j==-1)||(haystack[i]==needle[j]))
            {
                i++;
                j++;
            }
            else
            {
                j=next[j];//获取下一次匹配的位置
            }
        }
        if(j==len2)
            return i-j;
        
        return -1;
    }
};

int main(){
	Solution s;
	cout<<s.strStr("mississippi","issip");
	return 0;
}
