//2019天梯赛 5字符串字母大小写转换 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false) 
int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<s.length()-1;i++){
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=tolower(s[i]);
		else if(s[i]>='a'&&s[i]<='z')
			s[i]=toupper(s[i]);
	}
	for(int i=0;i<s.length()-1;i++)
		cout<<s[i];
	return 0;
} 
