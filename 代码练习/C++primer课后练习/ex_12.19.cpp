//#ifndef _ex_12.19_h_
//#define _ex_12.19_h_

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using namespace std;

class StrBlovPtr;
class StrBlob{
public:
	using size_type=vector<string> size_type;
	friend class StrBlobPtr;
	//友元函数 
	StrBlobPtr begin();
	StrBlobPtr end(); 
	
	StrBlob():data(make_shared_ptr<vector> >()){}
	StrBlob(initializer_list<string> il):data(make_shared<vector> >(il)){}//用不定list初始化vector
	
	size_type size() const { return data->size();} 
	bool empty() const{ return data->empty();}
	
	void push_back(const string &t){
		data->push_back(t);
	}
	void pop_back(){
		check(0,"pop back on empty StrBlob");
		data->pop_back();
	}
	string& front(){
		check(0,"front on empty StrBlob");
		return data->front();
	}
	string& back(){
		check(0,"back on empty StrBlob");
		return data->back();
	}
	const string& front() const{
		check(0,"front on empty StrBlob");
		return data->front();
	}
	const string& back() const{
		check(0,"back on empty StrBlob");
		return data->back();
	}
	
private:
	void check(size_type i,const string &msg){
		if(i>=data->size()) throw out_of_range(msg);
	}
	shared_ptr<vector> > data;	
};

class StrBlobPtr{
public:
	StrBlobPtr():cur(0){}
	StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz){}
	bool operator!=(const StrBlobPtr &p){return p.curr!=curr;} 
	string& deref() const{
		auto p=check(curr,"dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr(){
		check(curr,"increment past end of StrBlob");
		++curr;
		return *this;
	}

private:
	shared_ptr<vector<string> > check(size_t i,const string &msg) const{
		auto ret=wptr.lock();//ret返回shared_ptr 
		if(!ret) throw runtime_error("unbound StrBlobPtr");
		if(i>=ret->size()) throw out_of_range(msg);//ret_>size是vector的长度 
		return ret;
	}
	
	weak_ptr<vector> > wptr;
	size_t curr;
};

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

//#endif
