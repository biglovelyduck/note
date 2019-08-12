//字符串组合
//输入一个字符串，输出该字符串中相邻字符的所有组合。
//举个例子，如果输入abc，它的组合有a、b、c、ab、bc、abc。（注意：输出的组合需要去重） 
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
	int i,j,len;
	string s,s_tmp;
	set<string> out;
	set<string>::iterator it;
	cin>>s;
	len=s.length();
	for(i=1;i<=len;i++){
		for(j=0;j+i-1<len;j++){
			s_tmp=s.substr(j,i);
			out.insert(s_tmp);
		}
		for(it=out.begin();it!=out.end();it++)
			cout<<*it<<" ";
		out.clear();
	}
	return 0;
}
