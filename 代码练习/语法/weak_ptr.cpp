#include <iostream>
#include <string>
#include <memory>
using namespace std;
class B;
class A
{
public:
	shared_ptr<B> pb_;
	//weak_ptr<B> pb_;
	~A()
	{
		cout<<"A delete\n";
	}
};
class B
{
public:
	shared_ptr<A> pa_;
	//weak_ptr<A> pa_;
	~B()
	{
		cout<<"B delete\n";
	}
};
void fun()
{
	shared_ptr<B> pb(new B());
	shared_ptr<A> pa(new A());
	pb->pa_ = pa;
	pa->pb_ = pb;
	cout<<pb.use_count()<<endl;
	cout<<pa.use_count()<<endl;
}
int fun(long x)
{
	x=abs(x);
	int _count = 0;
	while(x)
{
	if(x % 10 == 1)
	++_count;
	x /= 10;
}
return _count;
}
int main()
{
	long num=-100;
	cout << fun(-111) << endl;
	cout<<num<<endl;
	fun();
	return 0;
}
