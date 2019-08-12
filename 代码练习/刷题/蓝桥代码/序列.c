#include<stdio.h>/*说标准输入输出头文件*/
#include<stdlib.h>/*常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()*/
int main(int argc,char *argv[]){
	long long n;
	scanf("%I64d",&n);
	printf("%I64d",(1+n)*n/2);
	return 0;
}
