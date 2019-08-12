#include <iostream>
using namespace std;
void func(char **c){
	*c="bss";
}
int main(){
	char *c="ans";
	func(&c);
	cout<<*c<<endl;
	cout<<*(c+1)<<endl;
	return 0;
}
