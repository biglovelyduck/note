/*5 字符串字母大小写转换（15 分）
本题要求编写程序，对一个以“#”结束的字符串，将其小写字母全部转换成大写字母，把大写字母全部转换成小写字母，其他字符不变输出。

输入格式：

输入为一个以“#”结束的字符串（不超过30个字符）。

输出格式：

在一行中输出大小写转换后的结果字符串。

输入样例：

Hello World! 123#
输出样例：

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
