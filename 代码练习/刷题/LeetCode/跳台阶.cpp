#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;
static int j,c,result;
int fun(int j,int c,int result){	
	c+=j;
	if(c<10){
		result=fun(1,c,result);
		result=fun(2,c,result);
	}
	if(c==10) result++;
	return result;
}
int func(int n){
	if(n==0) return 0; 
	if(n==1) return 1;
	if(n==2) return 2;
	return func(n-1)+func(n-2);
}
int main(){
	cout<<fun(j,c,result);
	//cout<<result<<endl;
	cout<<func(10)<<endl;
	return 0;
}
