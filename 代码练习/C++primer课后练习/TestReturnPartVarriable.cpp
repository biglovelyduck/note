#include <iostream>
#include <string>
using namespace std;
//返回引用不可以，返回值可以 
const string  return_partVariable(){
	string a="sssss";
	return a;
}
int main(){
	string s=return_partVariable();
	cout<<s<<endl;
	return 0;
}
