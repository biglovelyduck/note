#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{//通过常修饰的变量都需要初始化 
const int a=100;//第一个第二个意思一样 代表一个常整形数
int const b=100;

const int *c;//第三个 c是一个指向常整形数的指针(所指向的内存数据不能被修改，但是本身可以修改)
int * const d=NULL;//第四个 d 常指针（指针变量不能被修改，但是它所指向内存空间可以被修改）
const int * const e =NULL;//第五个 e一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）

return 0;
}

int func1(const ); 
//好处： int setTeacher_err( const Teacher *p)
//Const修改形参的时候，在利用形参不能修改指针所向的内存空间


