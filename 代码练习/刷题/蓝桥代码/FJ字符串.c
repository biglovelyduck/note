/*  
基础练习 FJ的字符串  
  
问题描述  
　　FJ在沙盘上写了这样一些字符串：  
　　A1 = “A”  
　　A2 = “ABA”  
　　A3 = “ABACABA”  
　　A4 = “ABACABADABACABA”  
　　… …  
　　你能找出其中的规律并写所有的数列AN吗？  
输入格式  
　　仅有一个数：N ≤ 26。  
输出格式  
　　请输出相应的字符串AN，以一个换行符结束。输出中不得含有多余的空格或换行、  
  
回车符。  
样例输入  
3  
样例输出  
ABACABA  
*/  
#include<stdio.h>  
void f(int a)  
{  
    if(a==0)printf("%c",'A');  
    else   
    {  
        f(a-1);  
        printf("%c",a+'A');  
        f(a-1);  
    }  
}  
int main()  
{  
    int a;
	scanf("%d",&a);
	f(a-1);
	printf("\n");  
    return 0;  
}  
