//14-�����ǰ׺ 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;
//1.�ҵ�����Ӵ��������ĳ���Ϊ��׼�����е��ַ����ĵ�һ���ַ���ʼ�Ա� 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string ans="";
        int len=strs.size();
        if(len==0) return ans; 
        string min=strs[0];
		for(int i=1;i<len;i++)
			if(strs[i].size()<min.size()) min=strs[i];
		for(int j=0;j<min.size();j++){
			for(int m=0;m<len;m++){
				if(min[j]!=strs[m][j]){
					return ans;
				}
			}
			ans+=min[j];
		}
		return ans;
    }
};
