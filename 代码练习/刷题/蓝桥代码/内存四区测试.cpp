#include<cstdio>
#include <iostream>
using namespace std;
void test(int a[128]){
	int size=sizeof(a);
	cout<<size<<endl;
} 
int main(){
	int a[128]={0};
	test(a);
	return 0;
} 
