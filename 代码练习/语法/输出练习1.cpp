/*1 编程实现以下数据输入/输出：
    (1)以左对齐方式输出整数,域宽为12。
    (2)以八进制、十进制、十六进制输入/输出整数。
    (3)实现浮点数的指数格式和定点格式的输入/输出,并指定精度。
    (4)把字符串读入字符型数组变量中,从键盘输入,要求输入串的空格也全部读入,以回车符结束。
    (5)将以上要求用流成员函数和操作符各做一遍。*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	long a=234;
	double b=2345.67890;
	char c[100];
	cout.fill('*');
	cout.flags(ios_base::left);//左对齐方式 
	cout.width(12);
	cout<<a<<endl;
	cout.fill('*');
	cout.flags(ios::right);//右对齐方式 
	cout.width(12);
	cout<<a<<endl;
	cout.flags(ios::hex);
	cout<<234<<'\t';
	cout.flags(ios::dec);
	cout<<234<<'\t';
	cout.flags(ios::oct);
	cout<<234<<endl;
	cout.flags(ios::scientific);
	cout<<b<<'\t';
	cout.flags(ios::fixed);
	cout<<b<<endl;
	cin.get(c,99);
	cout<<c<<endl;
	return 0;
}
//操作符实现

int main01(){
	long a=234;
	double b=2345.67890;
	char c[100];
	cout<<setfill('*');
	cout<<left<<setw(12)<<a<<endl;
	cout<<right<<setw(12)<<a<<endl;
	cout<<hex<<a<<'\t'<<dec<<a<<'\t'<<oct<<a<<endl;
	cout<<scientific<<b<<'\t'<<fixed<<b<<endl;
	return 0;
}

