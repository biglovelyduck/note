//2018天梯赛兰州理工大学校内选拔赛 符号配对
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
	vector<string> v;
	stack<char> st;
	getline(cin,s);
	v.push_back(s);
	while(s[0]!='.'){
		getline(cin,s);
		v.push_back(s);
	}
	bool find=false;
	char charactor;		//缺少的字符 
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]=='('||v[i][j]=='['||v[i][j]=='{')	st.push(v[i][j]);
			if(v[i][j]=='/'&&v[i][j+1]=='*'){
				 st.push('<');
				 j+=2;
			}
			if(v[i][j]==')'||v[i][j]==']'||v[i][j]=='}'||v[i][j]=='*'&&v[i][j+1]=='/'){
				if(!st.empty()){		//左 
					char c=st.top();st.pop();
					if(c=='('&&v[i][j]==')'||
						c=='['&&v[i][j]==']'||
						c=='{'&&v[i][j]=='}'||
						c=='<'&&v[i][j]=='*'&&v[i][j+1]=='/'){
						
					}
					else{
						find=true;	//找到不匹配了
						if(c=='(') charactor=')';
						if(c=='{') charactor='}';
						if(c=='[') charactor=']';
						if(c=='<') charactor='>'; 
						break;
					}
				}
				else{	//右 
					find=true;
					charactor=v[i][j];
					if(v[i][j]==')') charactor='(';
					if(v[i][j]=='}') charactor='{';
					if(v[i][j]==']') charactor='[';
					if(v[i][j]=='*'&&v[i][j+1]=='/') charactor='<'; 
					break;
				}
			}
		}
		if(find) break;
	}
	if(!find) cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl;
		if(charactor=='('||charactor=='{'||charactor=='['||charactor=='<'){
			if(charactor=='<') cout<<"?-*/"<<endl;
			else{
				char ch;
				if(charactor=='(') ch=')';
				if(charactor=='{') ch='}';
				if(charactor=='[') ch=']';
				cout<<"?-"<<ch<<endl;
			}
		}
		else{
			if(charactor=='>') cout<<"/*-?"<<endl;
			else{
				char ch;
				if(charactor==')') ch='(';
				if(charactor=='}') ch='{';
				if(charactor==']') ch='[';
				cout<<ch<<"-?"<<endl;
			}
		}
	}
	return 0;
}
