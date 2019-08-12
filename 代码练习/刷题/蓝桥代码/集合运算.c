
/*问题描述
　　给出两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。
输入格式
　　第一行为一个整数n，表示集合A中的元素个数。
　　第二行有n个互不相同的用空格隔开的整数，表示集合A中的元素。
　　第三行为一个整数m，表示集合B中的元素个数。
　　第四行有m个互不相同的用空格隔开的整数，表示集合B中的元素。
　　集合中的所有元素均为int范围内的整数，n、m<=1000。
输出格式
　　第一行按从小到大的顺序输出A、B交集中的所有元素。
　　第二行按从小到大的顺序输出A、B并集中的所有元素。
　　第三行按从小到大的顺序输出B在A中的余集中的所有元素。
样例输入
5
1 2 3 4 5
5
2 4 6 8 10
样例输出
2 4
1 2 3 4 5 6 8 10
1 3 5
样例输入
4
1 2 3 4
3
5 6 7
样例输出
1 2 3 4 5 6 7
1 2 3 4*/ 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



#define MAXS 1000
int i,j,temp;
//输入函数
void scan(int *colc,int n)
{
    int i;
    for (i = 0; i < n ; i ++)
    {
        scanf("%d",&colc[i]);    
    }    
}
//排序函数
void sort(int *colc,int n)
{
    for (i = 0; i < n-1; i ++)
    {
        for (j = 0; j < n-1-i; j ++)
        if(colc[j]>colc[j+1])
        {
            temp = colc[j];
            colc[j] = colc[j+1];
            colc[j+1] = temp;
        }
    }
}

int main()
{
    int n,m,a=0;
    int colcn[MAXS],colcm[MAXS];
    scanf("%d",&n);    
    scan(colcn,n);
        
    scanf("%d",&m);
    scan(colcm,m);    
    
    sort(colcn,n);
    sort(colcm,m);
    //A、B交集
    i=0,j=0;
    while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])//都已经排好序 
        j++;
        else if(colcn[i] < colcm[j])
        i ++;
        else//他俩相等 
        {
            printf("%d ",colcn[i]);
            i ++;//输出后都同步加 
            j ++;
        }
    }
     printf("\n");
     //A、B并集
     i=0,j=0;
     while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])
        printf("%d ",colcm[j++]);
        else if(colcn[i] < colcm[j])
        printf("%d ",colcn[i++]);
        else
        {
            printf("%d ",colcn[i]);    
            i ++;
            j ++;
        }
    }        
    while (i < n) printf("%d ", colcn[i++]);
    while (j < m) printf("%d ", colcm[j++]);
     printf("\n");
     //B在A中的余集
     i=0,j=0;
     while(i < n && j < m)
    {
        if(colcn[i] > colcm[j])
        j++;
        else if(colcn[i] < colcm[j])
        printf("%d ",colcn[i++]);
        else
        {    
            i ++;
            j ++;
        }
    }
    while (i < n) printf("%d ", colcn[i++]);
     printf("\n");
    return 0;
}
