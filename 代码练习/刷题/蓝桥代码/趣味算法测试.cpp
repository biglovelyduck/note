#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int str2num(string s);
void main(){
cout<<str2num("123");
}
int str2num(string s){
	int num;
	stringstream ss(s);
	ss>>num;
	return num;
}