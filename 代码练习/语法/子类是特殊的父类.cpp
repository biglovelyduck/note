#include <cstdlib>
#include <iostream>

using namespace std;

/*
���������Ե����������ʹ��
	����������ֱ�Ӹ�ֵ���������
	����������ֱ�ӳ�ʼ���������
	����ָ�����ֱ��ָ���������
	�������ÿ���ֱ�������������
	*/
//�����������ĸ���
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
	//�ֱ��常����� ����ָ�� �������� child
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

