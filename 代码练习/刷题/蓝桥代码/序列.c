#include<stdio.h>/*˵��׼�������ͷ�ļ�*/
#include<stdlib.h>/*���õĺ�����malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()*/
int main(int argc,char *argv[]){
	long long n;
	scanf("%I64d",&n);
	printf("%I64d",(1+n)*n/2);
	return 0;
}
