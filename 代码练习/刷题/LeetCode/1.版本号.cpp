//1.°æ±¾ºÅ 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
	int m;
	cin>>m;
	while(m--){
		int flag=0;
		string a,b;
		cin>>a>>b;
//		cout<<a<<b<<endl;
		int i=0,j=0;
		while(i<a.length()&&j<b.length()){
			while(a[i]==b[j])
				i++,j++;
			if(a[i]-'0'<b[j]-'0'){
				flag=1;
				break; 
			} 
			else if(a[i]-'0'>b[j]-'0'){
				flag=0;
				break;
			}
			i++,j++;
		}
		if(a.length()<b.length()){
			while(j<b.length()){
				if(b[j]!='.'&&(b[j]-'0'>0)){
					flag=1;
					break;	
				} 
				j++;
			}
			if(j==b.length()) flag=0;
		}
		if(a.length()>b.length()){
			while(i<a.length()){
				if(a[i]!='.'&&(a[i]-'0'>0))	break;
			}
			i++;
			if(i==a.length()) flag=0;
		}
		if(flag) cout<<"true";
		else cout<<"false";
	}
}
