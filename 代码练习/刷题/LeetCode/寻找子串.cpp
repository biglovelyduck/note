//Ѱ���Ӵ�
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
	int len=str.size();				//�ַ����ĳ��� 
	map<string,int> mp;
	for(int i=0;i<len;i++){			//�Ӵ��Ŀ�ʼ��λ�� 
		for(int j=1;i+j<=len;j++){	//�Ӵ��ĳ��� 
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
