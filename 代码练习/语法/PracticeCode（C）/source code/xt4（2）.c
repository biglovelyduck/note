#include<stdio.h>
int main()
{
    int a[10];
    int b;
    int max=0;

    printf("������ʮ����");
    for(b=0;b<10;b++)
    {
        scanf("%d",&a[b]);
        if(max<a[b])
            max=a[b];
    }
    printf("ʮ������������Ϊ%d\n",max);
    return 0;
}