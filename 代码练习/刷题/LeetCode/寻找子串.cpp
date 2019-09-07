//寻找子串
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
int main(){
	string str;
	getline(cin,str);
	int len=str.size();				//字符串的长度 
	map<string,int> mp;
	for(int i=0;i<len;i++){			//子串的开始的位置 
		for(int j=1;i+j<=len;j++){	//子串的长度 
			string sub=str.substr(i,j);		cout<<"sub:"<<sub<<endl; 
			if(mp.count(sub)) mp[sub]++;
			else mp.insert(pair<string,int>(sub,1));
		}
	}
	map<string,int>::iterator it;
	int max=0;
	for(it=mp.begin();it!=mp.end();it++){
		if(max<it->second) max=it->second;
	}
	cout<<max;
	return 0;
}
