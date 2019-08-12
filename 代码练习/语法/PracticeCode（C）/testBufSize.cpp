#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std; 
int main(){
	char buf[2*1024]={0};
	cout<<sizeof(buf)<<endl;
	ifstream file("H://ÎÄ¼þTest//c1.txt");
	while(!file.eof()){
		file.getline(buf,1024);
		cout<<buf<<endl;
	} 
	return 0;
} 
