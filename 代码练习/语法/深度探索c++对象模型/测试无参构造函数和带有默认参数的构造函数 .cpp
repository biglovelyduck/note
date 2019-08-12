//测试无参构造函数和带有默认参数的构造函数 
#include <iostream>
using namespace std;
class X{
	friend operator>>(ostream&,X&);
public:
	X(int sz=1024){
		ptr=new char[1024];
		cout<<"调用带有默认参数的构造函数"<<endl;
	}
//	X(){
//		cout<<"调用无参构造函数"<<endl; 
//	}
private:
	char* ptr;
	
};
X buf;	//所以说有歧义 
int main(){
	return 0;
}
