#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	cout<<"hh"<<endl;
	for(int i=0;i<0;i++){
		cout<<10<<endl;
	}
	cout<<"sss"<<endl;
	char s[]="cao|ni|ma";
	//if(m=strtok(s," ")) cout<<"NULL"<<endl;
	char *m=strtok(s,"|");
	printf("%s\n",m);
	cout<<m;
	//cout<<strtok(m," ");
	return 0;
} 
