/*5 �ַ�����ĸ��Сдת����15 �֣�
����Ҫ���д���򣬶�һ���ԡ�#���������ַ���������Сд��ĸȫ��ת���ɴ�д��ĸ���Ѵ�д��ĸȫ��ת����Сд��ĸ�������ַ����������

�����ʽ��

����Ϊһ���ԡ�#���������ַ�����������30���ַ�����

�����ʽ��

��һ���������Сдת����Ľ���ַ�����

����������

Hello World! 123#
���������

hELLO wORLD! 123*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[30];
	int i;
	gets(a);
	for(i=0;i<strlen(a)&&a[i]!='#';i++){
		if(a[i]>=65&&a[i]<=90) printf("%c",a[i]+32);
		else if(a[i]>=97&&a[i]<=122) printf("%c",a[i]-32);
		else printf("%c",a[i]);
	}
	return 0;
}
