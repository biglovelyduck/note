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
1���ڱ���˺�����ʱ��������������֪��ָ�� p ����ָ����ʲô��
2��������û�����ɱ���
3�����ǣ���������Ϊ�ȫ�������Ǳ��뵽�����print��������Ϊ���������϶�������ͬ��print������
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

	//ͨ��ָ��
	pp->print();
	//ͨ������
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

