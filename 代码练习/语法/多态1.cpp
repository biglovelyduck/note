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
	
	//�˴�2��������������func������ʲô��ϵ
	void func(int i, int j)
	{
		cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
	}

	//�˴�3�������ģ�������func������ʲô��ϵ
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
	//c.func(); //����1
	c.Parent01::func();
	c.func(1, 2);

	run01(&p);
	run01(&c);

	system("pause");
	return 0;
}

//����1��child����̳и�������func��������仰��������why
//c.func(); //��Ϊ���Ƹ��ǣ�C++����������ȥ������Ѱ��0��������func������ֻ������������func������

//1���������func�޷����ظ��������func 
//2���������������ͬ�ĺ����������������֣��������Ƹ��ǣ�����ĺ������������˸���ĺ���������
//3//c.Parent::func();
//����2 ���������func�͸����������func������ʲô��ϵ��

