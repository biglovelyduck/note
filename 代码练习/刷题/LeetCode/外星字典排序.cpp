//外星字典排序 
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
string str;
bool comp(char a,char b){
	int index_a=0,index_b=0;
	for(int i=0;i<str.length();i++){
		if(str[i]==a) index_a=i;
		if(str[i]==b) index_b=i;
	}
	return index_a<index_b;		//谁的下标小谁的优先级就高 
}
bool comp1(string a,string b){
	int index_a=0,index_b=0;
	if(a[0]==b[0]) return comp1(a.substr(1),b.substr(1));
	for(int i=0;i<str.size();i++){
		if(str[i]==a[0]) index_a=i;
		if(str[i]==b[0]) index_b=i;
	}
	return index_a<index_b;
}
int main(){	
	getline(cin,str);
	int m;
	cin>>m;
	getchar();
	vector<string> v;
	while(m--){
		string s;
		getline(cin,s);
		v.push_back(s);
	}
	sort(v.begin(),v.end(),comp1);
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) cout<<v[i];
		else cout<<v[i]<<endl;
	}		
	return 0;
}
