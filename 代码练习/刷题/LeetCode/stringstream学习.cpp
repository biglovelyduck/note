//stringstreamѧϰ
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
int main(){
	int m;
	cin>>m;
	getchar();
	while(m--){
		string s;
		getline(cin,s);
		stringstream ss;
		ss.str(s);
		int sum=0;
		while(1){
			int a;
			ss>>a;
			if(ss.fail()) break;
			sum+=a;
		}
		cout<<sum<<endl;
	}
} 
