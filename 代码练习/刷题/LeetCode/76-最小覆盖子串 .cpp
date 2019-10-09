//76-��С�����Ӵ� 
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
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int start=0,minlen=INT_MAX;
        int left=0,right=0;
        
        unordered_map<char,int> window;
        unordered_map<char,int> needs;			 
        for(auto c:t) needs[c]++;			//t�ַ����ϵ���ĸ�浽�ù�ϣ���� 
     
	 	int match=0;
		while(right<s.size()){				//�������ڱ���s 
			char c1=s[right];
			if(needs.count(c1)){
				window[c1]++;
				if(window[c1]==needs[c1]) match++;	//����ĸƥ����� 
			}
			right++;
			while(match==needs.size()){		//������ĸ��ƥ����� 
				if(right-left<minlen){
					start=left;
					minlen=right-left;
				}
				char c2=s[left];
				if(needs.count(c2)){
					window[c2]--;
					if(window[c2]<needs[c2]) match--;
				}
				left++;			//ɾ��ǰ�������ַ� 
			}
		}  
		return minlen == INT_MAX ?"" : s.substr(start, minlen);
    }
};
