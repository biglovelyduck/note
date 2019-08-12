#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
void main1(){
	
	//29
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
	
	//30,31
	istream_iterator<int> in_iter(cin),eof1;//从标准输入读取一个整数序列
	vector<int> vec1;
	while(in_iter!=eof1)
		vec1.push_back(*in_iter++);
	sort(vec1.begin(),vec1.end());
	copy(vec1.cbegin(),vec1.cend(),ostream_iterator<int>(cout," ")); 
	cout<<endl;
	//只打印不重复的元素
	unique_copy(vec1.cbegin(),vec1.cend(),ostream_iterator<int>(cout," ")) ;
	
	//32
	
}

int main(int argc,char **argv){
	if(argc!=4) return -1;
	ifstream ifs(argv[1]);//输入文件名
	ofstream ofs_odd(argv[2]) ,ofs_even(argv[3]);//奇数，偶数
	istream_iterator<int> in(ifs) ,in_eof;//输入流迭代器
	ostream_iterator<int> out_odd(ofs_odd," "),out_even(ofs_even," ");
	for_each(in,in_eof,[&out_odd,&out_even](const int i){
		*(i&0x1?out_odd:out_even)++=i;
	}) ;
	return 0;
}
