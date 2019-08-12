#include <iostream>
using namespace std;
int number=0;
int strToInt(char* string){
	cout<<*string<<endl;
	while(*string!=0){
		number=number*10+*string-'0';
		cout<<*string-'0'<<endl;
		++string;
	}
	return number;
}

int main(){
	cout<<strToInt("12345")<<endl;
	cout<<'\41' ;  //表示八进制 
	return 0;
}
