#include <iostream>

using namespace std;

class Parent
{
public:
	 void print()
	{
		cout<<"Parent:print() do..."<<endl;
	}
};

class Child : public Parent
{
public:
	 void print()
	{
		cout<<"Child:print() do..."<<endl;
	}
};

/*
1、在编译此函数的时，编译器不可能知道指针 p 究竟指向了什么。
2、编译器没有理由报错。
3、于是，编译器认为最安全的做法是编译到父类的print函数，因为父类和子类肯定都有相同的print函数。
*/

void howToPrint(Parent* p)
{
	p->print();
}

void run00()
{
	Child child;
	Parent* pp = &child;
	Parent& rp = child;

	//child.print();

	//通过指针
	pp->print();
	//通过引用
	rp.print();

	howToPrint(&child);
}
int main()
{
	run00();

	
	Child child;
	Parent *p = NULL;
	p = &child;
	child.print();
	child.Parent::print();
	
	system("pause");
	return 0;
}

