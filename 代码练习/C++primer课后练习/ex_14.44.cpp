#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;
//nomoal function
int add(int i,int j){
	return i+j;
}
//named lamda
auto mod=[](int i,int j){
	return i%j;
};
//functor函数对象,denominator分母,divisor分子 
struct wy_div{
	int operator()(int denominator,int divisor){
		return denominator/divisor;
	}
}; 
//the map
map<string,function<int(int,int)> > binops={
	{"+",add},
	{"-",minus<int>()},
	{"/",wy_div()},
	{"*",[](int i,int j){return i*j;}} ,
	{"%",mod}
}; 
int main(){
	while(true){
		cout<<"\npleasr enter: num operator num :\n"<<endl;
		int n1,n2;
		string s;
		cin>>n1>>s>>n2;
		cout<<binops[s](n1,n2);
	}
	return 0;
}
