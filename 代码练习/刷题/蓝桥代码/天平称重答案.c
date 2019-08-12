/*#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//递归解法 
																									
//把s中的符号取反（+变-，-变＋）
/*char* reve(char* s){//返回s的反串，首字符为‘-’ 
    int i;
	int n=strlen(s);
	for( i=0;i<n;i++){
		if(s[i]=='-')
		s[i]='+';
		else if(s[i]=='+')
		s[i]='-';
	}
	char *p=(char *)malloc(n+2);
	memset(p,0,n+2);//初始化数组p全为0
	p[0]='-';
	strcat(p,s);//将p与s的字符串连接起来存放到p中
	
	return p; 
} 

char* f(int x){
	char* p=(char*)malloc(1024);//开辟空间大小为1024个字节 ,用来保存结果串 
	memset(p,0,1024);
	
	int a=1;
	while(a<x) a*=3	;//a=1,3,9,27,81
	
	if(a==x){
		_itoa(a,p,10);//将整数a以10进制的方式保存在字符数组p中，atoi(p)表示将p的字符串转换为数字 
		return p; 
	} 
	if(x<=a/2) {//4:3+1
		int m=x-a/3;
		char* p1=f(m);//剩余的子串
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
