//28-ʵ��strStr() 
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
//ûд���� 
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
//1.�⺯��
class Solution{
public:
	int strStr(string haystack,string needle){
		if(needle.empty()) return 0;
		int pos=haystack.find(needle);
		return pos;
	}
}; 
//2.BF����
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
            next.push_back(-1);//next�����ֵΪ-1
            int j=0,k=-1;
            while(j<len-1)
            {
                if(k==-1||str[j]==str[k])//str[j]��׺ str[k]ǰ׺
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
        
        int i=0;//Դ��
        int j=0;//�Ӵ�
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
                j=next[j];//��ȡ��һ��ƥ���λ��
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
