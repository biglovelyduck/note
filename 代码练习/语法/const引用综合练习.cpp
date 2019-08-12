#include <cstdio>
#include <cstdlib> 
int& j()
{
	static int a = 0;
	return a;
}

int& g()
{
	int a = 0;
	return a;
}

int main()
{
	int a = g();
	int& b = g();
	j() = 10;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("j() = %d\n", j());
	printf("g() = %d\n", g());
	system("pause");
	return 0;
}

