/*����ƽ����ʱ������ϣ���þ������ٵ�������ϳƳ������ܶ��������
���ֻ��5�����룬�����ֱ���1��3��9��27��81
�����ǿ�����ϳƳ�1��121֮��������������������������������������У���

����ĿҪ����ʵ�֣����û�����������������������Ϸ�����
���磺
�û����룺
5
���������
9-3-1
�û����룺
19
���������
27-9+1

Ҫ����������������Ǵ�����ǰС���ں�
���Լ����û�����������ַ��Ϸ�Χ1~121��*/ 

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
