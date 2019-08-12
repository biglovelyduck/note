#include <cstdlib>
#include <iostream>

using namespace std;

class Parent01
{
public:
	Parent01()
	{
		cout<<"Parent01:printf()..do"<<endl; 
	}
public:
	virtual void func()
	{
		cout<<"Parent01:void func()"<<endl;
	}

	virtual void func(int i)
	{
		cout<<"Parent:void func(int i)"<<endl;
	}

	virtual void func(int i, int j)
	{
		cout<<"Parent:void func(int i, int j)"<<endl;
	}
};

class Child01 : public Parent01
{

public:
	
	//此处2个参数，和子类func函数是什么关系
	void func(int i, int j)
	{
		cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
	}

	//此处3个参数的，和子类func函数是什么关系
	void func(int i, int j, int k)
	{
		cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
	}
};

void run01(Parent01* p)
{
	p->func(1, 2);
}

int main()
{
	Parent01 p;

	p.func();
	p.func(1);
	p.func(1, 2);

	Child01 c;
	//c.func(); //问题1
	c.Parent01::func();
	c.func(1, 2);

	run01(&p);
	run01(&c);

	system("pause");
	return 0;
}

//问题1：child对象继承父类对象的func，请问这句话能运行吗？why
//c.func(); //因为名称覆盖，C++编译器不会去父类中寻找0个参数的func函数，只会在子类中找func函数。

//1子类里面的func无法重载父类里面的func 
//2当父类和子类有相同的函数名、变量名出现，发生名称覆盖（子类的函数名，覆盖了父类的函数名。）
//3//c.Parent::func();
//问题2 子类的两个func和父类里的三个func函数是什么关系？

