#include <stdio.h>  
#include <stdlib.h>
int main()  
{  
    int a =10;  
    int b =20;  
  
    //(a < b ? a : b) = 30; /<span style="color:#FF0000;">/编译错误 c语言三目元算符 返回的是a的值 不是a本身</span>  
    *(a < b ? &a : &b) = 30; //a:30  ,返回的较小值的地址 
    //printf("%d\n",a < b ? &a : &b);
    //printf("%d\n",*(a < b ? &a : &b));
    printf("a:%d\n",a);  
  
    system("pause");  
    return 0;  
}
