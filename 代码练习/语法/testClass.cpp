#include <iostream>
#include <string.h>
using namespace std;
class A{
public:
	string name="A";
	A(){
		cout<<"A�Ĺ��캯����"<<name<<endl;
		test();
	}
	virtual void test(){
		cout<<"A��test����:";
		cout<<name<<endl;
	}
};

class B{
public:
	string name="B";
	B(){
		
		cout<<"B�Ĺ��캯��:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"B��test����:"<<name<<endl;
	} 
};

class C:public A,public B{	//��д�̳з�ʽĬ��Ϊprotected 
public:
	string name="C";
	C(){
		
		cout<<"C�Ĺ��캯��:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"C��test����:"<<name<<endl;
	} 
};

class D:public A{	//��д�̳з�ʽĬ��Ϊprotected 
public:
	string name="D";
	D(){
		
		cout<<"D�Ĺ��캯��:"<<name<<endl; 
		test();
	}
	void test(){
		cout<<"D��test����:"<<name<<endl;
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
