//2019天梯赛模拟题集  L1-8 Left-pad
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
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
int main(){
	int n;
	cin>>n;
	char c;
	cin>>c;
	getchar();
	string s;
	getline(cin,s);
	if(s.size()<n){
		int num=n-s.size();
		string str="";
		while(num--)
			str+=c;
		str+=s;
		cout<<str;
	}
	else{
		int index=s.size()-n;
		for(int i=index;i<s.size();i++)
			cout<<s[i];
	}
	return 0;
}
