/*问题描述
　　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
　　例如：
　　A =
　　1 2
　　3 4
　　A的2次幂
　　7 10
　　15 22
输入格式
　　第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
　　接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
输出格式
　　输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开
样例输入
2 2
1 2
3 4
样例输出
7 10
15 22*/
#include <stdio.h>  
#include <string.h>  
#define N 100  
int A[N][N],t[N][N],r[N][N];  
int main()  
{  
    int n,m,i,j,k;  
    scanf("%d%d",&n,&m);  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
            scanf("%d",&A[i][j]);  
    for(i=0;i<n;i++)   
         r[i][i]=1;//单位矩阵，如同数的乘法中的1  
    while(m--)  
    {  
        memset(t,0,sizeof(t));  
        for(i=0;i<n;i++)  
            for(j=0;j<n;j++)  
                for(k=0;k<n;k++)  
                    t[i][j]+=r[i][k]*A[k][j];  //积矩阵 
        for(i=0;i<n;i++)  
            for(j=0;j<n;j++)  
                 r[i][j]=t[i][j];  //单位矩阵变为自身的幂乘积 
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n-1;j++)  
            printf("%d ",r[i][j]);      
        printf("%d\n",r[i][j]);      
    }  
    return 0;  
}  
