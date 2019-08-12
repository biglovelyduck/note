#include <iostream>
#include <string.h>
using namespace std;
class A{
public:
	string name="A";
	A(){
		cout<<"A的构造函数："<<name<<endl;
		test();
	}
	virtual void test(){
		cout<<"A的test方法:";
		cout<<name<<endl;
	}
};

class B{
public:
	string name="B";
	B(){
		
		cout<<"B的构造函数:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"B的test方法:"<<name<<endl;
	} 
};

class C:public A,public B{	//不写继承方式默认为protected 
public:
	string name="C";
	C(){
		
		cout<<"C的构造函数:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"C的test方法:"<<name<<endl;
	} 
};

class D:public A{	//不写继承方式默认为protected 
public:
	string name="D";
	D(){
		
		cout<<"D的构造函数:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"D的test方法:"<<name<<endl;
	} 
};

int main(){
	//A* b=new B();
	//C c;
	//A* c=new C();
	//c.B::test();	
	//c.A::test();
	D d;
	A *a=&d;
	a->test();
	A &aa=d;
	aa.test();
}
