//自增做参数 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
void func(char str[2]){		//和数组大小参数2没影响 
	cout<<*str<<endl;
	printf("%s\n",str);
}
int main(){
	char* str="HelloWorld";
	func(++str);
	cout<<*str<<endl;
	cout<<sizeof(++str)<<endl;	//求的是指针的大小，并且str没有++ 
	cout<<strlen(str++)<<endl; 
}
