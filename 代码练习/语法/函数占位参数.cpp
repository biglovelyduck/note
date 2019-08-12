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
	//如果默认参数和占位参数在一起，都能调用起来
	cout<<func2(1, 2)<<endl;
	cout<<func2(1, 2, 3)<<endl;
	system("pause");
}

