#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
int main(){
	ifstream ifs("./book.txt");
	istream_iterator<string> in(ifs),eof;//输入流迭代器绑定文件ifs,将输入流通过迭代器打印 
	vector<string> vec;
	copy(in,eof,back_inserter(vec));
	//输出
	copy(vec.cbegin(),vec.cend(),ostream_iterator<string>(cout," ")); 
	cout<<endl;
	for(auto i:vec){
		cout<<i;
	}
	cout<<endl;
	cout<<vec[0]<<" "<<vec[1];
	return 0;
}
