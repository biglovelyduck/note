/*用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
如果只有5个砝码，重量分别是1，3，9，27，81
则它们可以组合称出1到121之间任意整数重量（砝码允许放在左右两个盘中）。

本题目要求编程实现：对用户给定的重量，给出砝码组合方案。
例如：
用户输入：
5
程序输出：
9-3-1
用户输入：
19
程序输出：
27-9+1

要求程序输出的组合总是大数在前小数在后。
可以假设用户的输入的数字符合范围1~121。*/ 

/*
1:1
2:1+1
3:3
4:3+1
5:9-3-1*/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*void g(int n);

void f(int x){
	int a=1;
	while(a<x) a*=3;
	if(a==x) {
	printf("%d",a);
	return;
	}
	if(x<=a/2) {
	printf("%d+",a/3);
	f(x-a/3);
	return;
	}
	if(x>a/2) {
	printf("%d-",a);
	g(a-x);
	return;
    }
    return;
}

void g(int x){
	int a=1;
	while(a<x) a*=3;
	if(a==x) {
	printf("%d",a);
	return;
	}
	if(x<=a/2) {
	printf("%d-",a/3);
	f(x-a/3);
	return;
	}
	if(x>a/2) {
	printf("%d-",a);
	f(a-x);
	return;
    }
    return;
}*/

char s[100];
int index=0;

char* f(int x){
	int a=1;
	while(a<x) a*=3;
	if(a==x) {
	    s[index++]=a+'0'; 
 	    return s;
	}
	if(x<=a/2){
		s[index++]=a/3+'0';
		s[index++]='+';
		f(x-a/3);
	}
	if(x>a/2) {
		s[index++]=a;
		s[index++]='-';
		f(a-x);
	}
	return s;
}

int main(int argc, char *argv[]) {
	int n;
	for(n=1;n<=100;n++){
	printf("\n");
	}
	return 0;
}
