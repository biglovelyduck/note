//58-最后一个单词的长度 
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
//1.我的 
class Solution {
public:
    int lengthOfLastWord(string s) {
    	//去掉末尾的空格
		while(s[s.size()-1]==' ') s.pop_back(); 
        if(s.empty()) return 0;
        int index=s.find_last_of(" ");	//cout<<"index:"<<index<<endl;
        return s.size()-1-index;
    }
};

//2.字符串bianli 
class Solution1 {
public:
    int lengthOfLastWord(string s) {
    	int end=s.length()-1;
    	while(end>=0&&s[end]==' ') end--;
    	if(end<0) return 0;
    	int start=end;
    	while(start>=0&&s[start]!=' ') start--;
    	return end-start;
    }
};

//3.stringstream
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string word;
        stringstream ss(s);//字符串输入输出流自动过滤空格
        while(ss>>word){
		
		}//读取到最后一个单词
        return word.size();
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLastWord("a ");	
	return 0;
}
