#include <stdio.h>  
#include <stdlib.h>
int main()  
{  
    int a =10;  
    int b =20;  
  
    //(a < b ? a : b) = 30; /<span style="color:#FF0000;">/������� c������ĿԪ��� ���ص���a��ֵ ����a����</span>  
    *(a < b ? &a : &b) = 30; //a:30  ,���صĽ�Сֵ�ĵ�ַ 
    //printf("%d\n",a < b ? &a : &b);
    //printf("%d\n",*(a < b ? &a : &b));
    printf("a:%d\n",a);  
  
    system("pause");  
    return 0;  
}
