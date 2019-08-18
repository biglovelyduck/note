//Ðéº¯Êý±í
#include <iostream>
using namespace std;
class A{
public:
	virtual void fun1(){
		
	}
	//virtual void fun2();
	//int a;
};
class B:public A{
	int b;	
}; 
int main(){
	A a;
	B b;
	A *aa=&b;
	B *bb=&b;
	cout<<sizeof(*aa)<<endl;
	cout<<sizeof(*bb)<<endl;
	return 0;
}
 
