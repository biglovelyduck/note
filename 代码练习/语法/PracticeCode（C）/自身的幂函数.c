#include<stdio.h>  
#include<math.h>  
  
//������whileѭ��ʵ��   
int main()  
{  
    double x=2.0;  
    while(x<3.0)  
    {  
        x=x+0.00000001;//8��С��λ����ʽ����   
        if(fabs(pow(x,x)-10.0)<0.000001)  
        {  
            //printf("%lf\n",x);//ֱ�����2.506184 �����޷���������   
            printf("%.8lf\n",x);//���8λС��Ȼ��������4��5��   
        }  
    }  
}   