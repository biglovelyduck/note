#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
using namespace std;
class Quote{
	friend bool operator!=(const Quote &lhs,const Quote &rhs);
public:
	Quote(){
		cout<<"Ĭ�Ϲ��캯��\n";
	} 
	Quote(const string &b,double p):bookNo(b),price(p){
		cout<<"û��Ĭ��ֵ�Ĵ����������Ĺ��캯��\n";
	}
	Quote(const Quote &q):bookNo(q.bookNo),price(q.price){
		cout<<"�������캯��\n";
	}
	Quote(Quote&& q) noexcept :bookNo(move(q.bookNo)),price(move(q.price)) {
		cout<<"�ƶ����캯��\n";
	}
	Quote& operator=(const Quote &rhs){
		if(*this!=rhs){
			bookNo=rhs.bookNo;
			price=rhs.price;
		}
		cout<<"������ֵ�����\n";
	}
	Quote& operator=(Quote &&rhs) noexcept{
		if(*this!=rhs){
			bookNo=move(rhs.bookNo);
			price=move(rhs.price);
		}
		cout<<"�ƶ���ֵ�����"
	}
	string isbn() const{
		return bookNo;
	}
	virtual double net_price(size_t n) const{
		return n*price;
	}
	virtual void debug() const;
	virtual ~Quote(){
		cout<<"����������~Quote()\n";
	}
private:
	string bookNo;
protected:
	double price=10.0;//Ĭ��ֵ 
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
