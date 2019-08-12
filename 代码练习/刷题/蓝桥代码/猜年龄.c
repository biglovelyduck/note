#include <stdio.h>
#include <stdlib.h>
#define N 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	char a1[N],b1[N]; 
	for(i=0;i<100;i++) {
		int a=i*i*i;
		int b=a*i;
		
		//itoa(num_int, str_int, 10);  //把整数num_int转成字符串str_int
		//数字+‘0’ 转换为字符
//● itoa()：将整型值转换为字符串。
//● ltoa()：将长整型值转换为字符串。
//● ultoa()：将无符号长整型值转换为字符串。
//● gcvt()：将浮点型数转换为字符串，取四舍五入。
//● ecvt()：将双精度浮点型值转换为字符串，转换结果中不包含十进制小数点。
//● fcvt()：指定位数为转换精度，其余同ecvt()。 

//● atof()：将字符串转换为双精度浮点型值。
//● atoi()：将字符串转换为整型值。
//● atol()：将字符串转换为长整型值。
//● strtod()：将字符串转换为双精度浮点型值，并报告不能被转换的所有剩余数字。
//● strtol()：将字符串转换为长整值，并报告不能被转换的所有剩余数字。
//● strtoul()：将字符串转换为无符号长整型值，并报告不能被转换的所有剩余数字。
        //数字字符-'0 '为数字 
        itoa(a,a1,10);
        itoa(b,b1,10);
        if(strlen(a1)==4&&strlen(b1)==6) 
        printf("%d= %d%d\n",i,a,b);
	}
	return 0;
}
