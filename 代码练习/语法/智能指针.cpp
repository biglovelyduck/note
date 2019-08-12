class Test
{
public:
	Test()
	{
		this->a = 10;
	}
	void printT()
	{
		cout<<a<<endl;
	}

private:
	int a;
};

class MyTestPointer
{
public:
public:
	MyTestPointer()
	{
		p = NULL;
	}
	MyTestPointer(Test* p)
	{
		this->p = p;
	}
	~MyTestPointer()
	{
		delete p;
	}
	Test* operator->()
	{
		return p;
	}
	Test& operator*()
	{
		return *p;
	}
	
protected:
	Test *p;
};

void main01_classp()
{
	Test *p = new Test;
	p->printT();
	delete p;

	MyTestPointer myp = new Test; //构造函数
	myp->printT(); //重载操作符 ->

};


class MyIntPointer
{
public:
public:
	MyIntPointer()
	{
		p = NULL;
	}
	MyIntPointer(int* p)
	{
		this->p = p;
	}
	~MyIntPointer()
	{
		delete p;
	}
	int* operator->()
	{
		return p;
	}
	int& operator*()
	{
		return *p;
	}

protected:
	int *p;
};

void main02_intp()
{
	int *p = new int(100);
	cout<<*p<<endl;
	delete p;

	MyIntPointer myp = new int(200);
	cout<<*myp<<endl; //重载*操作符
};

