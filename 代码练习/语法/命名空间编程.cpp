#include <cstdio> 
#include <cstdlib>
namespace NameSpaceA//���������ռ� 
{
	int a = 0;
}

namespace NameSpaceB
{
	int a = 1;

	namespace NameSpaceC//Ƕ�������ռ� 
	{
		struct Teacher
		{
			char name[10];
			int age;
		};
	}
}

int main()
{
	using namespace NameSpaceA;
	using NameSpaceB::NameSpaceC::Teacher;

	printf("A�������ռ�a = %d\n", a);
	printf("B�������ռ�a = %d\n", NameSpaceB::a);

NameSpaceB::NameSpaceC::Teacher t2;
	Teacher t1 = {"aaa", 3};

	printf("t1.name = %s\n", t1.name);
	printf("t1.age = %d\n", t1.age);
	
	printf("t2.name = %s\n", t2.name);
	printf("t2.age = %d\n", t2.age);

	system("pause");//��ͣ�ڴ��� 
	return 0;
}

