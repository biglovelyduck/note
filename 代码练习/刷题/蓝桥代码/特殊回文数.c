#include <stdio.h>
#include <stdlib.h>
/*问题描述
　　123321是一个非常特殊的数，它从左边读和从右边读是一样的。
　　输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
输入格式
　　输入一行，包含一个正整数n。
输出格式
　　按从小到大的顺序输出满足条件的整数，每个整数占一行。
样例输入
52
样例输出
899998
989989
998899
数据规模和约定
　　1<=n<=54。*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
main()  
{  
    int n,a,b,c;  
    scanf("%d",&n);  
  
    for(a=1;a<=9;a++)  
    for(b=0;b<=9;b++)  
    for(c=0;c<=9;c++)  
    {  
        if(n==2*a+2*b+c*2)  
        printf("%d%d%d%d%d%d\n",a,b,c,c,b,a);  
    }   
      return 0;  
}  
