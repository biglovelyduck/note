#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void convto(char *s,int n,int b){//sΪָ��char�͵�ָ���������Ϊ������ ,sΪת��������� 
char bit[]={"0123456789ABCDEF"} ;
int len;
if(n==0){         //nΪ�̣��������� 
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
	printf("������ʮ��������");
	scanf("%d",&old);
	printf("������ת���Ľ��ƣ�");
	scanf("%d",&base);
	convto(s,old,base);
	printf("%s\n",s);
	return 0;
}
