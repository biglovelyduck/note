//shared_ptr
#include <iostream>
#include <string>
#include <memory>
using namespace std;

shared_ptr<string> p;

shared_ptr<string> factory(const char* p){
    return make_shared<string>(p);
}

void use_factory(){
    p = factory("use_factory"); 
    //cout<<*p<<endl;
} 
shared_ptr<string> return_share_ptr()
{ 
	cout<<*p<<endl;
	shared_ptr<string> p=factory("helloworld"); 
    //cout<<*p<<endl; 
	return p;
}


int main() 
{ 
	std::shared_ptr<int> sp1=std::make_shared<int>(11);
	std::shared_ptr<int> sp2=sp1;
	char *pp="caonima";
	use_factory(); 
	p = return_share_ptr(); 
	cout<<*p<<endl;
	cout<<p.use_count()<<endl<<*pp<<endl<<sp2.use_count()<<endl;;
}

