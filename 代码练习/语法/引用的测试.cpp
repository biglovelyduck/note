#include <cstdio>
#include <cstdlib> 
struct Teacer {
	//int &a;������ռ�õĿռ��С��ָ����ͬ��64λϵͳ��ռ��8���ֽ� 
	int &b;
};
int main()
{
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	system("pause");
	return 0;
}

