#include <iostream>
#include <string>
#include <map>
#include <functional>
#include "ex_15.1.h"
using namespace std;
double print_total(ostream &os,const Quote &item,size_t n);
int main(){
	return 0;
}
double print_total(ostream &os,const Quote &item,size_t n){
	double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
