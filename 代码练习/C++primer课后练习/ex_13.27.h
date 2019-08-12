#ifndef _EX_13.27_H_
#define _EX_13.27_H_

#include <string>
using namespace std;
class HasPtr{
public :
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &hp):ps(hs.ps),i(hp.i),use(hp.use){++*use};
	HasPtr& operator=(const HasPtr &rhs){
		++*rhs.use;
		if(--*use==0){
			delete ps;
			delete use;
		}
		ps=rhs.ps;
		i=rhs.i;
		use=rhs.use;
		return *this;
	}
	~HasPtr(){
		if(--*use==0){
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	int i;
	size_t use;
};

#endif
