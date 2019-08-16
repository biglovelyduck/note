//内置类型初始化 
#include <iostream>
using namespace std; 
class A{
	
};
class B:public A{
	
};
int *f(int *ret){
	int a[3]={250,2222,3};
	ret=a;
	return ret;
}
int* f1(){
	int *a=new int(3);
	delete a;
	return a;
}
int *f2(){
	int a[3]={21,21,21};
	return a;
}
/* 
int main(){
	int *a=new int;
	int *b=new int();
	cout<<*a<<endl;
	cout<<*b<<endl;
	//int c=*(f()+1);
	//cout<<c<<endl;
	int *r1;
	int r[3]={1,11,111};
	r1=f(r);
	cout<<*r1<<","<<*r<<endl;
	//int* x=f1();
	//cout<<*x<<endl;
	cout<<*f2()<<endl;
//	int i;
//	for(i = 0; ; i--){
//		if(0)
//			cout << "hello" << endl;
//	}
	const char * arr = "123"; 
	char * brr = "123"; 
	const char crr[] = "123"; 
	char drr[] = "123";
	A *aa=new B;	//若B不是public继承，则指针不能隐式转 
}*/
char* f3(){
	char p[]="good";
	return p;
}
char* f4(){
	char p[4]={'a','s','x','\0'};
	return p;
}
int main(){
	char *a=f3();
	printf("%s\n",a);
	printf("%s\n",f4());	
}
