#ifndef ex_13.39_h
#define ex_13.39_h
#include <string>
#include <memory>
#include <algorithm> 
using namespace std;
//自定义string类型的vector 
class StrVec{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){
	} 
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);//拷贝元素
	size_t size() const{return first_free-elements;} 
	size_t capacity() const {return cap-elements;}
	string *begin() const{return elements;}
	string *end() const{return first_free;}
	
	//添加的构造函数
	StrVec(initializer_list<string>) ;
	
	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count,const string&);
private:
	void chk_n_alloc(){
		if(size()==capacity()) reallocate();
	}
	//工具函数,被拷贝构造函数，赋值运算符，析构函数所使用 
	pair<string*,string*> alloc_n_copy(const string*,const string*); 
	void free();//销毁并释放内存 
	void reallocate(); //获得更多内存并拷贝已有元素 
	void alloc_n_move(size_t new_cap);
	void range_initialize(const string*,const string*);
private:
	allocator<string> alloc;//分配元素 ,可以分配string的allocator对象 
	string *elements;//指向数组首元素的指针
	string *first_free;//指向数组第一个空闲元素的指针
	string *cap;//指向数尾后位置的指针 
};
//向StrVec添加元素s 
void StrVec::push_back(const string &s){
	chk_n_alloc();//确保有空间容纳新元素
	//consruct(p,args):p必须是一个指向T类型的指针，arg是被传递给p的构造函数，用来在p指向的内存构造一个对象 
	alloc.construct(first_free++,s);//在first_free指向的元素中构造s的副本 
} 
//分配b到e大小的内存并拷贝其内容 
pair<string*,string*> //两个指针分别指向新空间的开始位置和拷贝的尾后的位置 
StrVec::alloc_n_copy(const string *b,const string *e){
	//分配空间保存指定范围中的元素
	auto data=alloc.allocate(e-b);//分配一段原始的未构造的内存，返回指针，保存e-b个string类型的对象 
	//初始化并返回一个pair,有data和uninitialized_copy的返回值构成
	//uninitialized_copy(b,e,data)将b到e间的string拷贝到data ,返回拷贝完的指针 下一位 
	return {data,uninitialized_copy(b,e,data)}; 
}
//释放掉StrVec的内存空间 
void StrVec::free(){
	if(elements){
		/*
		for(auto p=first_free;p!=elements;){//必须从后往前删 
			alloc.destroy(--p);//空间由alloc分配 ,先destroy元素,destroy会运行string的析构函数 
		}
		*/
		//lamda版本
		for_each(elements,first_free,[this](string &rhs){
			alloc.destroy(&rhs);
		});
		//释放自己分配的内存空间
		alloc.deallocate(elements,cap-elements); //elements不能为空 
	}
}
void StrVec::range_initialize(const string *first,const string *last){
	auto newdata=alloc_n_copy(first,last);
	elements=newdata.first;
	first_free=cap=newdata.second;
}
StrVec::StrVec(std::initializer_list<std::string> il)
{
	range_initialize(il.begin(), il.end());
}
//拷贝构造函数 
StrVec::StrVec(const StrVec &rhs){
	auto newdata=alloc_n_copy(rhs.begin(),rhs.end());//返回pair 
	elements=newdata.first;
	first_free=cap=newdata.second; 
} 
StrVec::~StrVec(){
	free();
}
StrVec& StrVec::operator=(const StrVec &rhs){
	auto data=alloc_n_copy(rhs.begin(),rhs.end());
	free();//free掉自己的内存
	elements=data.first;
	first_free=cap=data.second;
	return *this; 
}
//每次重新分配内存容量都加倍 
void StrVec::alloc_n_move(size_t new_cap){ 
	//分配新内存 
	auto newdata=alloc.allocate(new_cap); 
	//将数组从旧内存移到新内存 
	auto dest=newdata;//指向新数组的下一个空闲位置 
	auto elem=elements; //指向就数组的下一个元素 
	for(size_t i=0;i!=size();++i){
		alloc.construct(dest++,std::move(*elem++));//调用move返回结果是string的移动构造函数 
	}
	free(); 
	elements=newdata;
	first_free=dest; 
	cap=elements+new_cap;
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}
void StrVec::reserve(size_t new_cap){
	if(new_cap<=capacity()) return;
	alloc_n_move(new_cap);
}
void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
	if (count > size()) {
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, s);
	}
	else if (count < size()) {
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
}
#endif
