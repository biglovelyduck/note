//30-31
#include <string>
#include <iostream>
using namespace std;
class HasPtr {
public:
    friend void swap(HasPtr&,HasPtr&);
    friend bool operator<(const HasPtr &lhs,const HasPtr &rhs);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    /*
    HasPtr& operator=(const HasPtr &hp) {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    */
    HasPtr& operator=(HasPtr tmp){
    	this->swap(tmp);
    	return *this;
	}
    ~HasPtr() {
        delete ps;
    } 
    
    void swap(HasPtr &rhs){
    	using std::swap;
    	swap(ps,rhs.ps);
    	swap(i,rhs.i);
    	std::cout << "call swap(HasPtr &rhs)" << std::endl;
	}
    
    void show() { std::cout << *ps << std::endl; }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs,HasPtr,&rhs){
	lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs,const HasPtr &rhs){
	return *lhs.ps<*rhs.ps;//点号优先级大于星号 
}
/*
inline void swap(HasPtr &lhs,HasPtr &rhs){
	using std::swap;
	swap(lhs.ps,rhs.ps);
	swap(lhs.i,rhs.i);
	cout<<"call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}
*/
