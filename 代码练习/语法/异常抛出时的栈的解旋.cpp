#include <iostream>
using namespace std; 
class MyException {};

class Test
{
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
		cout << "Test 构造函数执行" << "a:" << a << " b: " << b << endl;
	}
	void printT()
	{
		cout << "a:" << a << " b: " << b << endl;
	}
	~Test()
	{
		cout << "Test 析构函数执行" << "a:" << a << " b: " << b << endl;
	}
private:
	int a;
	int b;
};

void myFunc() throw (MyException)
{
	Test t1;
	Test t2(1,1);

	cout << "定义了两个栈变量,异常抛出后测试栈变量的如何被析构" << endl;

	throw MyException();
}

int  main()
{
	//异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上的构造的所有对象，
	//都会被自动析构。析构的顺序与构造的顺序相反。
	//这一过程称为栈的解旋(unwinding)
	try  
	{
		myFunc();
	}
	//catch(MyException &e) //这里不能访问异常对象
	catch(MyException ) //这里不能访问异常对象
	{
		cout << "接收到MyException类型异常" << endl;
	}
	catch(...)
	{
		cout << "未知类型异常" << endl;
	}
	
	system("pause");
	return 0;
}

