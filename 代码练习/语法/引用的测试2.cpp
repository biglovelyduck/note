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
	cout<<"getAA1()�����Լ���a������:"<<getAA1()<<endl; 
	int a=0;
	cout<<"getAA2(a):"<<getAA2(a)<<endl; //ִ����󲢲��ı�a��ֵ 
	cout<<"getAA1()��a��ֵ:"<<a<<endl; 
	return 0;
} 
