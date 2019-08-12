#ifndef ex_13.39_h
#define ex_13.39_h
#include <string>
#include <memory>
#include <algorithm> 
using namespace std;
//�Զ���string���͵�vector 
class StrVec{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){
	} 
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);//����Ԫ��
	size_t size() const{return first_free-elements;} 
	size_t capacity() const {return cap-elements;}
	string *begin() const{return elements;}
	string *end() const{return first_free;}
	
	//��ӵĹ��캯��
	StrVec(initializer_list<string>) ;
	
	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count,const string&);
private:
	void chk_n_alloc(){
		if(size()==capacity()) reallocate();
	}
	//���ߺ���,���������캯������ֵ�����������������ʹ�� 
	pair<string*,string*> alloc_n_copy(const string*,const string*); 
	void free();//���ٲ��ͷ��ڴ� 
	void reallocate(); //��ø����ڴ沢��������Ԫ�� 
	void alloc_n_move(size_t new_cap);
	void range_initialize(const string*,const string*);
private:
	allocator<string> alloc;//����Ԫ�� ,���Է���string��allocator���� 
	string *elements;//ָ��������Ԫ�ص�ָ��
	string *first_free;//ָ�������һ������Ԫ�ص�ָ��
	string *cap;//ָ����β��λ�õ�ָ�� 
};
//��StrVec���Ԫ��s 
void StrVec::push_back(const string &s){
	chk_n_alloc();//ȷ���пռ�������Ԫ��
	//consruct(p,args):p������һ��ָ��T���͵�ָ�룬arg�Ǳ����ݸ�p�Ĺ��캯����������pָ����ڴ湹��һ������ 
	alloc.construct(first_free++,s);//��first_freeָ���Ԫ���й���s�ĸ��� 
} 
//����b��e��С���ڴ沢���������� 
pair<string*,string*> //����ָ��ֱ�ָ���¿ռ�Ŀ�ʼλ�úͿ�����β���λ�� 
StrVec::alloc_n_copy(const string *b,const string *e){
	//����ռ䱣��ָ����Χ�е�Ԫ��
	auto data=alloc.allocate(e-b);//����һ��ԭʼ��δ������ڴ棬����ָ�룬����e-b��string���͵Ķ��� 
	//��ʼ��������һ��pair,��data��uninitialized_copy�ķ���ֵ����
	//uninitialized_copy(b,e,data)��b��e���string������data ,���ؿ������ָ�� ��һλ 
	return {data,uninitialized_copy(b,e,data)}; 
}
//�ͷŵ�StrVec���ڴ�ռ� 
void StrVec::free(){
	if(elements){
		/*
		for(auto p=first_free;p!=elements;){//����Ӻ���ǰɾ 
			alloc.destroy(--p);//�ռ���alloc���� ,��destroyԪ��,destroy������string���������� 
		}
		*/
		//lamda�汾
		for_each(elements,first_free,[this](string &rhs){
			alloc.destroy(&rhs);
		});
		//�ͷ��Լ�������ڴ�ռ�
		alloc.deallocate(elements,cap-elements); //elements����Ϊ�� 
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
//�������캯�� 
StrVec::StrVec(const StrVec &rhs){
	auto newdata=alloc_n_copy(rhs.begin(),rhs.end());//����pair 
	elements=newdata.first;
	first_free=cap=newdata.second; 
} 
StrVec::~StrVec(){
	free();
}
StrVec& StrVec::operator=(const StrVec &rhs){
	auto data=alloc_n_copy(rhs.begin(),rhs.end());
	free();//free���Լ����ڴ�
	elements=data.first;
	first_free=cap=data.second;
	return *this; 
}
//ÿ�����·����ڴ��������ӱ� 
void StrVec::alloc_n_move(size_t new_cap){ 
	//�������ڴ� 
	auto newdata=alloc.allocate(new_cap); 
	//������Ӿ��ڴ��Ƶ����ڴ� 
	auto dest=newdata;//ָ�����������һ������λ�� 
	auto elem=elements; //ָ����������һ��Ԫ�� 
	for(size_t i=0;i!=size();++i){
		alloc.construct(dest++,std::move(*elem++));//����move���ؽ����string���ƶ����캯�� 
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
