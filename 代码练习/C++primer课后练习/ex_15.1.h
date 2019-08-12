#ifndef QUOTE_H
#define QUOTE_H
#include <string>
using std::string;
class Quote{
public:
	Quote()=default;
	Quote(string &b,double p):bookNo(b),price(p){};
	string isbn() const {return bookNo;}
	
	virtual net_price(size_t n) const {return n*price;}
	virtual ~Quote()=default;
private:
	string bookNo;
protected:
	double  price=0.0;
};
#endif
