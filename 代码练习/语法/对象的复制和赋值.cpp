#include <iostream>
　　using namespace std;
　　class Test
　　{
　　public:
　　Test();
　　~Test();
　　Test(const Test& t);
　　Test& operator=(const Test& t);
　　private:
　　int t1;
　　};
　　Test::Test()
　　{
　　cout<<”调用构造函数”<<endl;
　　}
　　Test::~Test()
　　{
　　cout<<”调用析构函数”<<endl;
　　}
　　Test::Test(const Test& t)
　　{
　　cout<<”调用复制构造函数”<<endl;
　　}
　　Test& Test::operator =(const Test& t)
　　{
　　cout<<”调用赋值构造函数”<<endl;
　　t1 = t.t1;
　　return *this;
　　}
　　void main()
　　{
　　Test t1;
　　Test t2 = t1;
　　Test t3;
　　t3 = t1;
　　}
