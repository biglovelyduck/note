//58-���һ�����ʵĳ��� 
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
//1.�ҵ� 
class Solution {
public:
    int lengthOfLastWord(string s) {
    	//ȥ��ĩβ�Ŀո�
		while(s[s.size()-1]==' ') s.pop_back(); 
        if(s.empty()) return 0;
        int index=s.find_last_of(" ");	//cout<<"index:"<<index<<endl;
        return s.size()-1-index;
    }
};

//2.�ַ���bianli 
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
        stringstream ss(s);//�ַ�������������Զ����˿ո�
        while(ss>>word){
		
		}//��ȡ�����һ������
        return word.size();
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLastWord("a ");	
	return 0;
}
