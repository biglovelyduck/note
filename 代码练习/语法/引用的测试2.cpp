#include <cstdio>
#include <iostream>
using namespace std;
int getAA1()
{
	int a;
	a = 10;
	return a;
}
int getAA2(int a)
{
	//int a;
	a = 10;
	return a;
}
int main(){
	cout<<"getAA1()返回自己的a的引用:"<<getAA1()<<endl; 
	int a=0;
	cout<<"getAA2(a):"<<getAA2(a)<<endl; //执行完后并不改变a的值 
	cout<<"getAA1()后a的值:"<<a<<endl; 
	return 0;
} 
