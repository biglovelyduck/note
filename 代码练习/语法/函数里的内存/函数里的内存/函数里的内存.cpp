// 函数里的内存.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//内置类型初始化 
#include <iostream>
using namespace std;
int *f(int *ret){
	int a[3] = { 250, 2222, 3 };
	ret = a;
	return ret;
}
int* f1(){
	int *a = new int(3);
	delete a;
	return a;
}
int *f2(){
	int a[3] = { 21, 21, 21 };
	return a;
}
int main(){
	int *a = new int;
	int *b = new int();
	cout << *a << endl;
	cout << *b << endl;
	//int c=*(f()+1);
	//cout<<c<<endl;
	int *r1;
	int r[3] = { 1, 11, 111 };
	r1 = f(r);
	cout << *r1 << "," << *r << endl;
	//int* x = f1();
	//cout << *x << endl;
	cout << *f2() << endl;
}

