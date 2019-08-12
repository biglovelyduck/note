#include <cstdio>
#include <cstdlib> 
struct Teacer {
	//int &a;引用所占用的空间大小与指针相同。64位系统下占用8个字节 
	int &b;
};
int main()
{
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	system("pause");
	return 0;
}

