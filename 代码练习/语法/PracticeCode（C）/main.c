#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void convto(char *s,int n,int b){//s为指向char型的指针变量，即为数组名 ,s为转换后的数字 
char bit[]={"0123456789ABCDEF"} ;
int len;
if(n==0){         //n为商，结束条件 
	strcpy(s,"");
	return;
}
convto(s,n/b,b);
len=strlen(s);
s[len]=bit[n%b];
s[len+1]='\0'; 
}

int main(int argc, char *argv[]) {
	char s[80];
	int i,base,old;
	printf("请输入十进制数：");
	scanf("%d",&old);
	printf("请输入转换的进制：");
	scanf("%d",&base);
	convto(s,old,base);
	printf("%s\n",s);
	return 0;
}
