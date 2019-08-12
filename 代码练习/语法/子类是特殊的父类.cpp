#include <cstdlib>
#include <iostream>

using namespace std;

/*
子类对象可以当作父类对象使用
	子类对象可以直接赋值给父类对象
	子类对象可以直接初始化父类对象
	父类指针可以直接指向子类对象
	父类引用可以直接引用子类对象
	*/
//子类就是特殊的父类
class Parent03
{
protected:
	const char* name;
public:
	Parent03()
	{
		name = "Parent03";                             
	}

	void print()
	{
		cout<<"Name: "<<name<<endl;
	}
};

class Child03 : public Parent03
{
protected:
	int i;
public:
	Child03(int i)
	{
		this->name = "Child2";
		this->i = i;
	}
};

int main()
{
	Child03 child03(1000);
	//分别定义父类对象 父类指针 父类引用 child
	Parent03 parent = child03;
	Parent03* pp = &child03;
	Parent03& rp = child03;
	
	Parent03 p1=Child03() ;
	Parent03 *p2=&Child03()
	Parent03 &p1=Child03()
	
	parent.print();
	pp->print();
	rp.print();
	
	p1.print();
	p2->print();
	p2.print();
	
	system("pause");
	return 0;
}

