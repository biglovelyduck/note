#include<iostream>
using namespace std;//c++的命名空间
class circle
{
public:

	double r;

	double pi = 3.1415926;
	double p; 
	double area = pi*r*r;//错误原因:定义对象时area已经被初始化了。 
	
};

int main()
{
	circle pi;
	cout << "请输入r" << endl;
	cin >> pi.r;

	cout << pi.area << endl;	//乱码
	
	system("pause");
	return 0;
}

