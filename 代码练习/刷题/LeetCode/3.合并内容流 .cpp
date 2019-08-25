//3.合并内容流 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	string s1,s2;
	if(s1=="") cout<<s2;
	else if(s2=="") cout<<s1;
	for(int i=0;i<a.size();i++){
		if(a[i]!=' ') s1+=a[i]; 
	}
	for(int i=0;i<b.size();i++){
		if(b[i]!=' ') s2+=b[i];
	}
	//cout<<s1<<s2<<endl;
	if(s1.length()<s2.length()){
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	//cout<<s1<<s2<<endl;
	string s;
	int i=0,j=0;
	for(i=0;i<s1.length();){
		if((i+4)%4==0&&i!=0){
			//cout<<"i:"<<i<<endl;
			s+=s2[j++];
			s+=s1[i];
			i++;	
		} 
		else{
			s+=s1[i++];
		}
		

//		for(;i<s1.length();i++)
//			s+=s1[i];
//		for(;j<s2.length();j++)
//			s+=s2[j];
//		break;
		
		//cout<<"i:"<<i<<endl;
	}
	for(;j<s2.length();j++)
		s+=s2[j];
	//cout<<s<<endl;
	for(int i=0;i<s.length();i++){
		if(i==s.length()-1) cout<<s[i];
		else cout<<s[i]<<" ";
	}
	return 0;
}
