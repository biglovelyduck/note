//智能指针的内存泄露
#include <memory>
#include <iostream>
using namespace std;
class Child;
class Parent{
private:
	shared_ptr<Child> childPtr;
public:
	void setChild(shared_ptr<Child> child){
		this->childPtr=child;
	}
	void doSomething(){
		if(this->childPtr.use_count()){
			
		}
	}
	~Parent(){
		cout<<"parent delete."<<endl;
	}
};
class Child{
private:
	shared_ptr<Parent> parentPtr;
public:
	void setParent(shared_ptr<Parent> parent){
		this->parentPtr=parent;
	}
	void doSomething(){
		if(this->parentPtr.use_count()){
			
		}
	}
	~Child(){
		cout<<"child delete."<<endl;
	}
};
int main(){
	weak_ptr<Parent> pp;
	weak_ptr<Child> cc; 
	{
		shared_ptr<Parent> p(new Parent);
		shared_ptr<Child> c(new Child);
		p->setChild(c);
		c->setParent(p);
		pp=p;
		cc=c;
		cout<<"Parent的引用指针个数："<<pp.use_count()<<endl; 
		cout<<"Child的引用指针个数："<<cc.use_count()<<endl; 
	}	//正常来说到这一步两个智能指针对象会被析构，引用计数-1结果为1！所以Parent和Child对象并没有被析构 
	cout<<"Parent的引用指针个数："<<pp.use_count()<<endl; 
	cout<<"Child的引用指针个数："<<cc.use_count()<<endl; 
} 

 
