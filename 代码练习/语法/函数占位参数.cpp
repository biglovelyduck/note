#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int func2(int a, int b, int = 0)
{
	return a + b;
}
int main()
{
	//���Ĭ�ϲ�����ռλ������һ�𣬶��ܵ�������
	cout<<func2(1, 2)<<endl;
	cout<<func2(1, 2, 3)<<endl;
	system("pause");
}

