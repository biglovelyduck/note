//17-�绰�������ĸ���
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
	map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
						{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
	vector<string> res;
	void DFS(string cur,string next_digits){
		if(next_digits.size()==0)
			res.push_back(cur);
		else{
			char digit=next_digits[0];	//��ȡ��ǰ��Ҫ���������
			string letters=mp[digit];	//��ȡ���ֶ�Ӧ���ַ���
			for(int i=0;i<letters.size();i++){	//�����ַ������ÿһ���ַ� 
				string letter=letters.substr(i,1);//���ַ��ӵ�������� 
				DFS(cur+letter,next_digits.substr(1)); 
			} 
		}
	}
	vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        else
            DFS("",digits);
        return res;
    }
}; 

int main(){
	Solution s;
	//s.letterCombinations("23");
	return 0;
}
