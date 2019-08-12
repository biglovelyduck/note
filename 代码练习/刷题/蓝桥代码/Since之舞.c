/*  
������ϰ Sine֮��  
  
��������  
�������FJΪ������ţ�ǿ�������ѧ�����Σ�FJ֪����Ҫѧ�����ſΣ�������һ���õ���  
  
�Ǻ�����������������׼������ţ����һ����Sine֮�衱����Ϸ��Ԣ�����֣������ţ��  
  
�ļ���������  
����������  
����An=sin(1�Csin(2+sin(3�Csin(4+...sin(n))...)  
����Sn=(...(A1+n)A2+n-1)A3+...+2)An+1  
����FJ������ţ�Ǽ���Sn��ֵ���������FJ��ӡ��Sn���������ʽ���Է�����ţ�����⡣  
�����ʽ  
��������һ������N<201��  
�����ʽ  
�����������Ӧ�ı��ʽSn����һ�����з�����������в��ú��ж���Ŀո���С���  
  
������  
��������  
3  
�������  
((sin(1)+3)sin(1�Csin(2))+2)sin(1�Csin(2+sin(3)))+1  
*/ 
/* 
#include <stdio.h>  
  
void printA(int n, int k)  
{  
    if (n == k)  
        printf("sin(%d)", n);  
    else  
    {  
        printf("sin(%d", n);  
        printf(n % 2 == 0 ? "+" : "-");  
        printA(n + 1, k);  
        printf(")");  
    }  
}  
  
void printS(int n, int k)  
{  
    if (n == 1)  
    {  
        printA(1, n);  
        printf("+%d", k - n);  
    }  
    else  
    {  
        printf("(");  
        printS(n - 1, k);  
        printf(")");  
        printA(1, n);  
        printf("+%d", k - n);  
    }  
}  
  
int main()  
{  
    int N;  
    scanf("%d", &N);  
    printS(N, N + 1);  
    printf("\n");  
    return 0;  
}  
*/ 




#include<stdio.h> 
 void An(int n){
     int i;
     for(i=1;i<=n;i++){
         printf("sin(%d",i);
         if(i%2!=0 && i!=n)
             printf("-");
         if(i%2==0 && i!=n)
             printf("+"); 
     }
     for(i=0;i<n;i++)
         printf(")");
 }
 void Sn(int n){
     int i,d;
     d=n;
     for(i=0;i<n-1;i++)
         printf("(");
     for(i=1;i<=n;i++){
         An(i);
         printf("+%d",d);
         if(d!=1)
             printf(")");
         d--;
     }
 }
 int main(){
    int n;
     scanf("%d",&n);
     Sn(n);
     return 0;
 }
