//�ַ������
//����һ���ַ�����������ַ����������ַ���������ϡ�
//�ٸ����ӣ��������abc�����������a��b��c��ab��bc��abc����ע�⣺����������Ҫȥ�أ� 
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
