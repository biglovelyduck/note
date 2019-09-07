//5067. ͳ��ֻ����һ��ĸ���Ӵ�
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
class Solution {
public:
	//�ж��Ƿ��ǵ�һ�Ӵ� 
	bool isTrue(string& s){
		if(s.size()==1) return true;
		for(int i=0;i<s.length();i++)
			if(i>0&&s[i]!=s[i-1]) return false;
		return true;
	}
    int countLetters(string S) {
        if(S.empty()) return 0;
        int count=0;
        map<string,int> mp; 
        for(int i=0;i<S.length();i++){
        	for(int j=i+1;j<=S.length();j++){
        		string sub=S.substr(i,j-i);
        		//��һ������������Ӵ� 
        		if(isTrue(sub)){
        			mp[sub]++;
				}
			}
		}
		map<string,int>::iterator it=mp.begin();
		for(it;it!=mp.end();it++){
			count+=it->second;
		}
		return count;
    }
};

int main(){
	Solution s;
	cout<<s.countLetters("aaaba");
	return 0;
}
