#include <memory>
#include <iostream>
#include <algorithm>
using namespace std;
class String{
public:
	String():String(""){
	}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();
	
	const char *c_str() const{return elements;}//String转char
	size_t size() const{return end-elements;}
	size_t length() const {return end-elements-1;} 
	
private:
	pair<char*,char*> alloc_n_copy(const char*,const char*);
	void range_initializer(const char*,const char*);
	void free();
	
	char *elements;
	char *end;
	allocator<char> alloc;
};

pair<char*,char*>
String::alloc_n_copy(const char *b,const char *e){
	auto str=alloc.allocate(e-b);
	return {str,uninitialized_copy(b,e,str)};
}
void String::range_initializer(const char *first, const char *last)
{
	auto newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	end = newstr.second;
}
String::String(const char *s){
	char *s1=const_cast<char*>(s);//const强转为非const
	while(*s1){
		++s1;
	}
	range_initializer(s,++s1); 
}
String::String(const String& rhs)
{
	range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}
void String::free()
{
	if (elements) {
		std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}	
}

String::~String()
{
	free();
}

String& String::operator = (const String &rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
	return *this;
}
