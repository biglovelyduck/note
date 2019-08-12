#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	//copy
	string s="aaaaa";
	char buf[129]={0}; 
	s.copy(buf,3,0);
	cout<<buf<<endl;
	cout<<strlen(buf)<<endl;
	cout<<sizeof(buf)<<endl;

	//find
	cout<<"___________________________"<<endl;
	string s1="wbm 111 wbm 222 wbm 333 wbm 444 wbm 555";
	int offindex=s1.find("wbm",0);
	cout<<offindex<<endl;
	while(offindex!=string::npos){
		cout<<"offindex:"<<offindex<<endl;
		offindex=offindex+1;
		offindex=s1.find("wbm",offindex);
	}
	
	//replace
	offindex=s1.find("wbm",0);
	while(offindex!=string::npos){
		//cout<<"offindex:"<<offindex<<endl;
		s1.replace(offindex,3,"WBM");
		offindex=offindex+1;
		offindex=s1.find("wbm",offindex);
	}
	cout<<s1<<endl;
	
	//区间删除
	s="hello1 hello2 hello3";
	//int index=s1.find('l',0);
	string::iterator it=find(s.begin(),s.end(),'l');
	s.erase(it);
	cout<<s<<endl;
	//插入 
	s="BBB";
	s.insert(0,"AAA");
	s.insert(s.length(),"CCC");
	cout<<s<<endl;
	
	//小算法
	s="aaabbb";
	transform(s.begin(),s.end(),s.begin(),::toupper);
	cout<<s<<endl;
	transform(s.begin(),s.end(),s.begin(),::tolower);
	cout<<s<<endl; 
	return 0;
}
