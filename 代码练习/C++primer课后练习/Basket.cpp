#ifndef BASKET_H
#define BASKET_H
#include <iostream>
#include "quote.h"
using namespace std;
class Basket{
public:
	//使用默认的构造函数和控制成员
	void add_item(const shared_ptr<Quote> &sale){
		items.insert(sale);
	}
	double total_receipy(ostream &) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs){
		return lhs->isbn()<rhs->isbn();
	} 
	
	multiset<shared_ptr<Quote>,delctype(compare) *> items{compare};
};
#endif 
