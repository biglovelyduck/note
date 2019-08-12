/*古罗马帝国开创了辉煌的人类文明，但他们的数字表示法的确有些繁琐，尤其在表示大数的时候，现在看起来简直不能忍受，所以在现代很少使用了。
之所以这样，不是因为发明表示法的人的智力的问题，而是因为一个宗教的原因，当时的宗教禁止在数字中出现0的概念！
罗马数字的表示主要依赖以下几个基本符号：

I --> 1
V --> 5
X --> 10
L --> 50
C --> 100
D --> 500
M --> 1000

这里，我们只介绍一下1000以内的数字的表示法。
单个符号重复多少次，就表示多少倍。最多重复3次。
比如：CCC表示300  XX表示20，但150并不用LLL表示，这个规则仅适用于I X C M。

如果相邻级别的大单位在右，小单位在左，表示大单位中扣除小单位。
比如：IX表示9  IV表示4  XL表示40 
49 = XLIX
    
更多的示例参见下表，你找到规律了吗？    
I = 1 
II = 2
III = 3
IV = 4
V = 5
VI = 6
VII = 7
VIII = 8
IX = 9 
X = 10
XI = 11
XII = 12
XIII = 13
XIV = 14
XV = 15
XVI = 16
XVII = 17
XVIII = 18
XIX = 19
XX = 20
XXI = 21
XXII = 22
XXIX = 29
XXX = 30
XXXIV = 34
XXXV = 35
XXXIX = 39
XL = 40
L = 50
LI = 51
LV = 55
LX = 60
LXV = 65
LXXX = 80
XC = 90
XCIII = 93
XCV = 95
XCVIII = 98
XCIX = 99
C = 100
CC = 200
CCC = 300
CD = 400
D = 500
DC = 600
DCC = 700
DCCC = 800
CM = 900
CMXCIX = 999

本题目的要求是：请编写程序，由用户输入若干个罗马数字串，程序输出对应的十进制表示。

输入格式是：第一行是整数n,表示接下来有n个罗马数字(n<100)。
以后每行一个罗马数字。罗马数字大小不超过999。
要求程序输出n行，就是罗马数字对应的十进制数据。

例如，用户输入：
3
LXXX
XCIII
DCCII

则程序应该输出：
80
93
702*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*函数原型：extern char *strchr(char *str,char character)
参数说明：str为一个字符串的指针，character为一个待查找字符。
        
所在库名：#include <string.h>
  
函数功能：从字符串str中寻找字符character第一次出现的位置。
  
返回说明：返回指向第一次出现字符character位置的指针，如果没找到则返回NULL。

其它说明：还有一种格式char *strchr( const char *string, int c )，这里字符串是以int型给出的。*/
int main(int argc, char *argv[]) {
	int n;
	int i,j;
	int sum[1000];
	scanf("%d",&n);	
	getchar();
	int num=0;
	char a[100][100];
	char b[1000];
	gets(b);
	for(i=0;i<strlen(b);i++){
		//printf("%c",b[i]);
		if(b[i]=='I') sum+=1;
		if(b[i]=='V') sum+=5;
		if(b[i]=='X') sum+=10;
		if(b[i]=='L') sum+=50;
		if(b[i]=='C') sum+=100;
		if(b[i]=='D') sum+=500;
		if(b[i]=='M') sum+=1000;
	}
	printf("%d",sum);
	
	/*while(n--){
	    gets(a[num++]);
		//scanf("%s",a[num++]);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<strlen(a[i]);j++){
			
			//char *c=strchr(a[i],a[i][j]);
			//int p=c-a[i];//获取j对应的字符位置 
			if(a[i][j]=='I') sum[i]+=1; 
			if(a[i][j]=='V') sum[i]+=5;
			if(a[i][j]=='X') sum[i]+=10;
			if(a[i][j]=='L') sum[i]+=50;
			if(a[i][j]=='C') sum[i]+=100;
			if(a[i][j]=='D') sum[i]+=500;
			if(a[i][j]=='M') sum[i]+=1000;
			
			//补偿
			if(strstr(a[i],"IV")) sum[i]-=2;
			if(strstr(a[i],"IX")) sum[i]-=2;
			if(strstr(a[i],"XL")) sum[i]-=20;
			if(strstr(a[i],"XC")) sum[i]-=20; 
			if(strstr(a[i],"CD")) sum[i]-=200;
			if(strstr(a[i],"CM")) sum[i]-=200;
		}
	}
	for(i=0;i<num;i++){
		
			//puts(a[i]);
			printf("%d",sum[i]);
			printf("\n");
		
	}*/ 
	return 0;
}
