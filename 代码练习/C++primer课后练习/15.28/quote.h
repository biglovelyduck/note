#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
using namespace std;
class Quote{
	friend bool operator!=(const Quote &lhs,const Quote &rhs);
public:
	Quote(){
		cout<<"默认构造函数\n";
	} 
	Quote(const string &b,double p):bookNo(b),price(p){
		cout<<"没有默认值的带两个参数的构造函数\n";
	}
	Quote(const Quote &q):bookNo(q.bookNo),price(q.price){
		cout<<"拷贝构造函数\n";
	}
	Quote(Quote&& q) noexcept :bookNo(move(q.bookNo)),price(move(q.price)) {
		cout<<"移动构造函数\n";
	}
	Quote& operator=(const Quote &rhs){
		if(*this!=rhs){
			bookNo=rhs.bookNo;
			price=rhs.price;
		}
		cout<<"拷贝赋值运算符\n";
	}
	Quote& operator=(Quote &&rhs) noexcept{
		if(*this!=rhs){
			bookNo=move(rhs.bookNo);
			price=move(rhs.price);
		}
		cout<<"移动赋值运算符"
	}
	string isbn() const{
		return bookNo;
	}
	virtual double net_price(size_t n) const{
		return n*price;
	}
	virtual void debug() const;
	virtual ~Quote(){
		cout<<"虚析构函数~Quote()\n";
	}
private:
	string bookNo;
protected:
	double price=10.0;//默认值 
}; 

bool inline
operator !=(const Quote &lhs,const Quote &rhs){
	return lhs.bookNo!=rhs.bookNo&&lhs.price!=rhs.price;
}

void Quote::debug() const{
	cout<<"bookNo= "<<this->bookNo<<" "
		<<"price= "<<this->price<<" \n";
}

#endif
