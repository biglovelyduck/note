/*预定义的函数对象支持加、减、乘、除、求余和取反。调用的操作符是与type相关联的实例
加法：plus<Types>
plus<string> stringAdd;
sres = stringAdd(sva1,sva2);
减法：minus<Types>
乘法：multiplies<Types>
除法divides<Tpye>
求余：modulus<Tpye>
取反：negate<Type>
negate<int> intNegate;
ires = intNegate(ires);
Ires= UnaryFunc(negate<int>(),Ival1);

*/


//算数函数对象 
#include <functional> 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//1使用预定义函数对象：
//类模板plus<> 的实现了： 不同类型的数据进行加法运算
int main()
{
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y); //等价于 x + y 
	cout << z << endl;

	plus<string> stringAdd;
	string myc = stringAdd("aaa", "bbb");
	cout << myc << endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzzz");

	//缺省情况下，sort()用底层元素类型的小于操作符以升序排列容器的元素。
	//为了降序，可以传递预定义的类模板greater,它调用底层元素类型的大于操作符：
	cout << "sort()函数排序" << endl;;
	sort(v1.begin(), v1.end(), greater<string>() ); //从大到小
	for (vector<string>::iterator it=v1.begin(); it!=v1.end(); it++ )
	{
		cout << *it << endl;
	}
	return 0;
}

