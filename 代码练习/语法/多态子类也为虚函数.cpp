//多态子类也为虚函数 
#include <iostream>
using namespace std;
class A{
public:
	virtual void func(int num=10){
		cout<<"A:"<<num<<endl;
	}
};

class B:public A{
	void func(int num=20){
		cout<<"B:"<<num<<endl;
	}
};
int main(){
	B b;
	A &a=b;
	a.func();
	return 0;
	
}
