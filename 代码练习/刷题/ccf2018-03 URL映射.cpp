//ccf2018-03 URL映射 
/*
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX_N=100+1;
int n,m;	//映射规则条数，待处理的url地址数
map<string,string> mm; 
string p,r;	//输入的规则和对应的名字 
string q;	//要测试的字符串，不包含空格 
string	s;	//输出的结果 
string str;
string a[MAX_N];
int main(){
	cin>>n>>m;
	getchar();	//吸收回车字符 
	for(int i=0;i<n;i++){
		getline(cin,str); 
		int pos=str.find(' ');
		p=str.substr(0,pos);
		r=str.substr(pos+1,str.length());
		mm.insert(pair<string,string>(p,r));
	}
	for(int i=0;i<m;i++){
		getline(cin,str);
		a[i]=str;
	}
	return 0;
}*/
//不会做啊！！！
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 
using namespace std;
typedef long long ll;
const int N=200+10;
struct url{
	int l;			//保存子串的个数 
	bool f;			//判断是否以'/'结尾，是为true，如果以<path>结尾为false 
	string s[N];	//保存被'/'分割开的字符串 
	string ret;		//url的名字 
}a[N],b;	//所有规则存放到a中 ,b为查询的url 
bool pipei(url a,url b){
	if(a.l>b.l||(a.f!=b.f||a.l<b.l)&&(!a.l||a.s[a.l-1]!="<path>")) return false;
	string can[N];
	int cnt=0;
	for(int i=0;i<a.l&&i<b.l;i++){
		if(a.s[i]=="<str>"){
			can[cnt++]=b.s[i];
			continue;
		}
		if(a.s[i]=="<int>"){
			for(int j=0;j<b.s[i].length();j++)
				if(!isdigit(b.s[i][j])) return false;	//检查是否是数字 
			while(b.s[i][0]=='0') b.s[i].erase(0,1);	//去除前导0
			can[cnt++]=b.s[i];
			continue;	
		}
		if(a.s[i]=="<path>"){
			can[cnt]=b.s[i];	//到头了就不需要加1
			for(int j=i+1;j<b.l;j++){
				can[cnt]+='/'+b.s[j];
			} 
			if(b.f) can[cnt]+='/';
			cnt++;
			cout<<a.ret;
			for(int i=0;i<cnt;i++)
				cout<<" "<<can[i];
			cout<<endl;
			return true;
		}
		if(a.s[i]==b.s[i]) continue;
		return false;
	}
	cout<<a.ret;
	for(int i=0;i<cnt;i++){		//参数的个数 
		cout<<" "<<can[i];
	}
	cout<<endl;
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	string str;
	//输入规则和名字 
	for(int i=0;i<n;i++){
		cin>>str;
		string c="";	
		int cnt=0;
		a[i].f=true;
		for(int j=1;j<str.length();j++){	//j从1开始是因为url第一个字符都是'/',跳过这个字符 
			if(str[j]=='/'){
				a[i].s[cnt++]=c;
				c="";
			}
			else c+=str[j];		//c是子串 
		}
		if(c.length()) a[i].s[cnt++]=c,a[i].f=false;
		a[i].l=cnt;	
		cin>>a[i].ret;
	}
	//输入要测试的url
	while(m--){
		cin>>str;
		string c="";
		int cnt=0;
		b.f=true;	//默认为'/'结尾
		for(int i=1;i<str.length();i++){
			if(str[i]=='/'){
				b.s[cnt++]=c;
				c="";
			}
			else c+=str[i];
		} 
		if(c.length()) b.s[cnt++]=c,b.f=false;
		b.l=cnt;
		bool flag=false;	//是否查找到对应规则
		for(int i=0;i<n;i++){
			if(pipei(a[i],b)){
				flag=true;
				break;
			}
		} 
		if(!flag) cout<<404<<endl;
	} 
	return 0;
}
