#include <cstdio> 
#include <cstdlib>
namespace NameSpaceA//定义命名空间 
{
	int a = 0;
}

namespace NameSpaceB
{
	int a = 1;

	namespace NameSpaceC//嵌套命名空间 
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

	printf("A的命名空间a = %d\n", a);
	printf("B的命名空间a = %d\n", NameSpaceB::a);

NameSpaceB::NameSpaceC::Teacher t2;
	Teacher t1 = {"aaa", 3};

	printf("t1.name = %s\n", t1.name);
	printf("t1.age = %d\n", t1.age);
	
	printf("t2.name = %s\n", t2.name);
	printf("t2.age = %d\n", t2.age);

	system("pause");//暂停黑窗口 
	return 0;
}

