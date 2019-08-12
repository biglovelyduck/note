#include<stdio.h>  
#include<math.h>  
  
//以下是while循环实现   
int main()  
{  
    double x=2.0;  
    while(x<3.0)  
    {  
        x=x+0.00000001;//8个小数位的形式递增   
        if(fabs(pow(x,x)-10.0)<0.000001)  
        {  
            //printf("%lf\n",x);//直接输出2.506184 ，就无法四舍五入   
            printf("%.8lf\n",x);//输出8位小数然后我们再4舍5入   
        }  
    }  
}   