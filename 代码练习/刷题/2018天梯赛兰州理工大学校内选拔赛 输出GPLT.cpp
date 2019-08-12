//2018天梯赛兰州理工大学校内选拔赛 输出GPLT
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
	map<char,int> m;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(toupper(s[i])=='G') m['G']++;
		if(toupper(s[i])=='P') m['P']++;
		if(toupper(s[i])=='L') m['L']++;
		if(toupper(s[i])=='T') m['T']++;
	}
	while(m['G']!=0||m['P']!=0||m['L']!=0||m['T']!=0){
		if(m['G']!=0){
			cout<<'G';
			m['G']--;
		}
		if(m['P']!=0){
			cout<<'P';
			m['P']--;
		}
		if(m['L']!=0){
			cout<<'L';
			m['L']--;
		}
		if(m['T']!=0){
			cout<<'T';
			m['T']--;
		}
	}
	return 0;
}
