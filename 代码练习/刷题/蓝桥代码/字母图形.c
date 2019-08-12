/*  
基础练习 字母图形  
  
问题描述  
利用字母可以组成一些美丽的图形，下面给出了一个例子：  
  
ABCDEFG  
  
BABCDEF  
  
CBABCDE  
  
DCBABCD  
  
EDCBABC  
  
这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。  
  
输入格式  
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。  
输出格式  
输出n行，每个m个字符，为你的图形。  
样例输入  
5 7  
样例输出  
ABCDEFG  
BABCDEF  
CBABCDE  
DCBABCD  
EDCBABC  
数据规模与约定  
1 <= n, m <= 26。  
*/  
#include <stdio.h>  
#include <math.h>  
  
main()  
{  
    int n,m,j,k;  
    scanf("%d %d",&n,&m);  
    if(n>=1&&m<=26)  
    for(j=0;j<n;j++)  
    {  
        for(k=0;k<m;k++)  
        printf("%c",65+abs(j-k));  
        printf("\n");  
    }  
    return 0;  
}  
/*  
#include <stdio.h>  
#include <stdlib.h>  
#define MAXSIZE 26  
  
//输出  
void Print(char matrix[MAXSIZE][MAXSIZE],int n,int m)  
{  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            printf("%c",matrix[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
//实现字母图形  
void Drawing(int n,int m)  
{  
    int i,j;  
    int point=0;  
    char str;  
    char matrix[MAXSIZE][MAXSIZE];  
    for(i=0;i<n;i++)  
    {  
        str='A';  
        for(j=i;j<m;j++)  
        {  
            matrix[i][j]=str++;  
        }  
        str='A';  
        for(j=i-1;j>=0;j--)  
        {  
            matrix[i][j]=++str;  
        }  
    }  
    Print(matrix,n,m);  
}  
int main()  
{  
    int n,m;  
    scanf("%d%d",&n,&m);  
    Drawing(n,m);  
    return 0;  
}  
*/  
