#include <stdio.h>
#include <stdlib.h>
/*��������
����123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
��������һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n ��
�����ʽ
��������һ�У�����һ��������n��
�����ʽ
��������С�����˳���������������������ÿ������ռһ�С�
��������
52
�������
899998
989989
998899
���ݹ�ģ��Լ��
����1<=n<=54��*/
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
