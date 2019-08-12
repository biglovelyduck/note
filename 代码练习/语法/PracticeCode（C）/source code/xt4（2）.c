#include<stdio.h>
int main()
{
    int a[10];
    int b;
    int max=0;

    printf("请输入十个数");
    for(b=0;b<10;b++)
    {
        scanf("%d",&a[b]);
        if(max<a[b])
            max=a[b];
    }
    printf("十个数中最大的数为%d\n",max);
    return 0;
}