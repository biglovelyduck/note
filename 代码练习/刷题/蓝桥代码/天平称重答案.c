/*#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�ݹ�ⷨ 
																									
//��s�еķ���ȡ����+��-��-�䣫��
/*char* reve(char* s){//����s�ķ��������ַ�Ϊ��-�� 
    int i;
	int n=strlen(s);
	for( i=0;i<n;i++){
		if(s[i]=='-')
		s[i]='+';
		else if(s[i]=='+')
		s[i]='-';
	}
	char *p=(char *)malloc(n+2);
	memset(p,0,n+2);//��ʼ������pȫΪ0
	p[0]='-';
	strcat(p,s);//��p��s���ַ�������������ŵ�p��
	
	return p; 
} 

char* f(int x){
	char* p=(char*)malloc(1024);//���ٿռ��СΪ1024���ֽ� ,������������ 
	memset(p,0,1024);
	
	int a=1;
	while(a<x) a*=3	;//a=1,3,9,27,81
	
	if(a==x){
		_itoa(a,p,10);//������a��10���Ƶķ�ʽ�������ַ�����p�У�atoi(p)��ʾ��p���ַ���ת��Ϊ���� 
		return p; 
	} 
	if(x<=a/2) {//4:3+1
		int m=x-a/3;
		char* p1=f(m);//ʣ����Ӵ�
		_itoa(a/3,p,10); 
		strcat(p,'+');
		return strcat(p,p1); 
	}//5:9-3-1
	char* h=reve(f(a-x));//x=5,a=9,f(4)=3+1,reve(f(4))=-3-1
	_itoa(a,p,10);
	strcat(p,h);
	return p;
	}

int main(int argc, char *argv[]) {
	int i;
	for(i=1;i<100;i++){
		char* p=f(i);
		printf("%d:%s\n",i,p);
	}
	return 0;
}*/
