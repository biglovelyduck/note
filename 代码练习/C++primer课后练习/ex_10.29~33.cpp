#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
int main(){
	ifstream ifs("./book.txt");
	istream_iterator<string> in(ifs),eof;//���������������ļ�ifs,��������ͨ����������ӡ 
	vector<string> vec;
	copy(in,eof,back_inserter(vec));
	//���
	copy(vec.cbegin(),vec.cend(),ostream_iterator<string>(cout," ")); 
	cout<<endl;
	for(auto i:vec){
		cout<<i;
	}
	cout<<endl;
	cout<<vec[0]<<" "<<vec[1];
	return 0;
}
