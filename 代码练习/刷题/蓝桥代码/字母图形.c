/*  
������ϰ ��ĸͼ��  
  
��������  
������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�  
  
ABCDEFG  
  
BABCDEF  
  
CBABCDE  
  
DCBABCD  
  
EDCBABC  
  
����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ�  
  
�����ʽ  
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������  
�����ʽ  
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�  
��������  
5 7  
�������  
ABCDEFG  
BABCDEF  
CBABCDE  
DCBABCD  
EDCBABC  
���ݹ�ģ��Լ��  
1 <= n, m <= 26��  
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
  
//���  
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
  
//ʵ����ĸͼ��  
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
