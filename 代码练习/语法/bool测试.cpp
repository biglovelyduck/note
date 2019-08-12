#include <cstdio>
#include <cstdlib>
int main(int argc, char *argv[])
{//当b为0时就是false 
	int a;
	bool b = true;
	printf("b = %d, sizeof(b) = %d\n", b, sizeof(b));

	b = 4;
	a = b;
	printf("a=b=4:\n") ;
	printf("a = %d, b = %d\n", a, b);

	b = -1;
	a = b;
	printf("a=b=-1:\n");
	printf("a = %d, b = %d\n", a, b);
	
	b = -4;
	a = b;
	printf("a=b=-4:\n");
	printf("a = %d, b = %d\n", a, b);

	a = 10;
	b = a;
	printf("b=a=10:\n");
	printf("a = %d, b = %d\n", a, b);

	b = 0;
	printf("b=0:\n");
	printf("b = %d\n", b);

	system("pause");
	return 0;
}

