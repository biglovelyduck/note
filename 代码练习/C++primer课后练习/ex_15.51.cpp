#include <iostream>
using namespace std;
class Foo{
};
template<typename T>
ostream& print(ostream &os,const T &t){
	return os<<t;
}
template<typename T,typename... Args>
ostream& print(ostream &os,const T &t,const Args&... rest){
	os<<t<<",";
	return print(os,rest...);
}
int main(){
	print(cout,1,2);
	print(std::cout, 1,2,3,4,"sss");
	return 0;
}
