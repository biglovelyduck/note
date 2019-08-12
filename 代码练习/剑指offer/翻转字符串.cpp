//·­×ª×Ö·û´®
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;
class Solution{
public:
	vector<string> split(const string& str,const string &pattern){
		char *strc=new char[strlen(str.c_str())+1];
		strcpy(strc,str.c_str());
		vector<string> v;
		char* tmpStr=strtok(strc,pattern.c_str());
		while(tmpStr!=NULL){
			v.push_back(string(tmpStr));
			tmpStr=strtok(NULL,pattern.c_str());
		}
		delete[] strc;
		return v;
	}
	string rev(string &s){
		reverse(s.begin(),s.end());
		vector<string> v=split(s," ");
		string rs="";
		for(int i=0;i<v.size();i++){
			reverse(v[i].begin(),v[i].end());	
			rs+=v[i];
		}
		return rs;	
	}
}; 
 
