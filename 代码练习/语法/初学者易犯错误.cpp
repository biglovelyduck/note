#include<iostream>
using namespace std;//c++�������ռ�
class circle
{
public:

	double r;

	double pi = 3.1415926;
	double p; 
	double area = pi*r*r;//����ԭ��:�������ʱarea�Ѿ�����ʼ���ˡ� 
	
};

int main()
{
	circle pi;
	cout << "������r" << endl;
	cin >> pi.r;

	cout << pi.area << endl;	//����
	
	system("pause");
	return 0;
}

