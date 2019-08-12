#include <iostream>
#include <memory>
using namespace std;
void func_lvalue(string &lhs,string &rhs){
	lhs="Wang\n";
	rhs="Alan\n";
}
void func_rvalue(int &&lhs,int rhs){
	//allocate enough space
	std::allocater<int> alloc;//分配器 
	int* data(alloc.allocate(3));//3个int大小的内存
	
	alloc.construct(data,lhs);
	alloc.construct(data+1,0);
	alloc.construct(data+2,rhs);
	
	for(auto p=data;p!=data+3,++p){
		cout<<*p<<endl;
	} 
	
	//destroy and deallocation
	for(auto p=data+3;p!=data;){
		alloc.destroy(--p);
	}
	alloc.deallocate(data,3);
}

template<typename F,typename T1,typename T2>
void flip(F f,T1 &&t1,T2 &&t2){
	f(std::forword<T2>(t2),forword<T1>(t1));
}

int main(){
	//! test for lvalue reference
    /*
    std::string s1, s2;
    flip(func_lvalue, s1, s2);
    std::cout << s1 << s2;
    */

    //! test for rvalue reference
    flip(func_rvalue, 99,88);
	return 0;
}
