#include <cstdio>
#include <iostream>
#include <cstdlib> 
int  g1(int *p)
{
	*p = 100;
	return *p;
}

int&  g2(int *p) //
{
	*p = 100;
	return *p;
}



//当我们使用引用语法的时候 ，我们不去关心编译器引用是怎么做的
//当我们分析乱码这种现象的时候，我们才去考虑c++编译器是怎么做的。。。。
int main()
{
	int a1 = 10;
	a1 = g1(&a1);

	int a2 = g1(&a1); //用引用去接受函数的返回值，是不是乱码，关键是看返回的内存空间是不是被编译器回收了。。。。
	printf("a1:%d \n", a1);
	printf("a2:%d \n", a2);
	
	a1 = g2(&a1);

	int &a3 = g2(&a1); //用引用去接受函数的返回值，是不是乱码，关键是看返回的内存空间是不是被编译器回收了。。。。
	printf("a1:%d \n", a1);
	printf("a3:%d \n", a3);

	system("pause");
	return 0;
}

