#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
int main(){
	using std::placeholders::_1;//占位符
	vector<int> ivec{1,11,111,1111,11111};
	//参数传递给_1 
	//_1和1024是greater参数 
	//greater<int>(l,r) return l<r;是函数调用运算符，对象名+()直接调用。 
	int count=count_if(ivec.cbegin(),ivec.cend(),bind(std::greater<int>(),_1,1024));
	cout<<count<<endl;
	
	vector<string> svec{"pooh","pooh","pezy","pooh"};
	//find_if返回第一个不等于pooh的数组迭代器 
	auto found=find_if(svec.begin(),svec.end(),bind(not_equal_to<string>(),_1,"pooh"));
	cout<<*found<<endl;
	
	transform(ivec.begin(),ivec.end(),ivec.begin(),bind(multiplies<int>(),_1,2)); 
	for (int i : ivec) std::cout << i << " ";
    std::cout << std::endl;
	return 0;
}
