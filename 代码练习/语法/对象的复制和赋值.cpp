#include <iostream>
����using namespace std;
����class Test
����{
����public:
����Test();
����~Test();
����Test(const Test& t);
����Test& operator=(const Test& t);
����private:
����int t1;
����};
����Test::Test()
����{
����cout<<�����ù��캯����<<endl;
����}
����Test::~Test()
����{
����cout<<����������������<<endl;
����}
����Test::Test(const Test& t)
����{
����cout<<�����ø��ƹ��캯����<<endl;
����}
����Test& Test::operator =(const Test& t)
����{
����cout<<�����ø�ֵ���캯����<<endl;
����t1 = t.t1;
����return *this;
����}
����void main()
����{
����Test t1;
����Test t2 = t1;
����Test t3;
����t3 = t1;
����}
