#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>
using namespace std;
class StrBlob{
public:
	using size_type=vector<string>::size_type;
	//默认构造函数，初始化data为空 
	StrBlob():data(make_shared<vector<string> >()){
		
	}
	//initializer_list:通常作为可变形参的函数的参数，支持模板，类型相同。元素永远是常量值 
	StrBlob(initializer_list<string> il):data(make_shared<vector<string> >(il)){
		
	} 
	size_type size() const{
		return data->size();
	}
	bool empty() const{
		return data->empty();
	}
	void push_back(const string &t){
		data->push_back(t);
	}
	void pop_back(){
		check(0,"pop back on empty StrBlob.");
		data->pop_back();
	}
	string& front(){
		check(0,"front on empty StrBlob.");
		return data->front();
	}
	string& back(){
		check(0,"back on empty StrBlob.");
		return data->back();
	}
	const string& front() const{
		check(0,"front on empty StrBlob.");
		return data->front();
	}
	const string& back() const{
		check(0,"back on empty StrBlob.");
		return data->back();
	}
private:
	void check(size_type i,const string &msg) const{
		if(i>=data->size())
			throw out_of_range(msg);
	}
	shared_ptr<vector<string> > data;//指向vector<stirng>的共享指针 
};
int main(){
	const StrBlob csb{"hello","world","happy"};
	StrBlob sb{"hello","world","shabi"};
	std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;
	return 0;
}
