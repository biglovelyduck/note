//ccf2018-03 URLӳ�� 
/*
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX_N=100+1;
int n,m;	//ӳ������������������url��ַ��
map<string,string> mm; 
string p,r;	//����Ĺ���Ͷ�Ӧ������ 
string q;	//Ҫ���Ե��ַ������������ո� 
string	s;	//����Ľ�� 
string str;
string a[MAX_N];
int main(){
	cin>>n>>m;
	getchar();	//���ջس��ַ� 
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
//��������������
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 
using namespace std;
typedef long long ll;
const int N=200+10;
struct url{
	int l;			//�����Ӵ��ĸ��� 
	bool f;			//�ж��Ƿ���'/'��β����Ϊtrue�������<path>��βΪfalse 
	string s[N];	//���汻'/'�ָ���ַ��� 
	string ret;		//url������ 
}a[N],b;	//���й����ŵ�a�� ,bΪ��ѯ��url 
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
				if(!isdigit(b.s[i][j])) return false;	//����Ƿ������� 
			while(b.s[i][0]=='0') b.s[i].erase(0,1);	//ȥ��ǰ��0
			can[cnt++]=b.s[i];
			continue;	
		}
		if(a.s[i]=="<path>"){
			can[cnt]=b.s[i];	//��ͷ�˾Ͳ���Ҫ��1
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
	for(int i=0;i<cnt;i++){		//�����ĸ��� 
		cout<<" "<<can[i];
	}
	cout<<endl;
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	string str;
	//������������ 
	for(int i=0;i<n;i++){
		cin>>str;
		string c="";	
		int cnt=0;
		a[i].f=true;
		for(int j=1;j<str.length();j++){	//j��1��ʼ����Ϊurl��һ���ַ�����'/',��������ַ� 
			if(str[j]=='/'){
				a[i].s[cnt++]=c;
				c="";
			}
			else c+=str[j];		//c���Ӵ� 
		}
		if(c.length()) a[i].s[cnt++]=c,a[i].f=false;
		a[i].l=cnt;	
		cin>>a[i].ret;
	}
	//����Ҫ���Ե�url
	while(m--){
		cin>>str;
		string c="";
		int cnt=0;
		b.f=true;	//Ĭ��Ϊ'/'��β
		for(int i=1;i<str.length();i++){
			if(str[i]=='/'){
				b.s[cnt++]=c;
				c="";
			}
			else c+=str[i];
		} 
		if(c.length()) b.s[cnt++]=c,b.f=false;
		b.l=cnt;
		bool flag=false;	//�Ƿ���ҵ���Ӧ����
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
