/*��������
��������һ��������n�����n!��ֵ��
��������n!=1*2*3*��*n��
�㷨����
����n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
������a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
�������Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
�����ʽ
�����������һ��������n��n<=1000��
�����ʽ
�������n!��׼ȷֵ��
��������
10
�������
3628800*/ 
/*
#include <stdio.h>  
#include <string.h>  
#define MaxSize 3000+5  
  
void resultProduct(int P[],int num)  
{  
    int i,tp=0,st=0;  
      
    for(i=0;i<MaxSize;i++)  
    {  
        st=tp;  
        tp=(P[i]*num+st)/10;  
        P[i]=(P[i]*num+st)%10;  
    }  
  
    return ;  
}  
  
void printArray(int P[])  
{  
    int i=MaxSize-1;  
      
    while(!P[i])  
    {  
        i--;  
    }  
      
    while(i>=0)  
    {  
        printf("%d",P[i]);  
        i--;  
    }  
      
    printf("\n");  
      
    return ;  
}  
  
main()  
{  
    int A[MaxSize],n;  
    int i;  
      
    //���������Ҹ�λ��ʼ��Ϊ1   
    memset(A,0,MaxSize*sizeof(int));   
    A[0]=1;  
  
    scanf("%d",&n);  
    //��i���γ�������A   
    for(i=2;i<=n;i++)  
    {  
        resultProduct(A,i);  
    }  
      
    printArray(A);  
    printf("\n");      
  
    return 0;  
} 
*/ 
/*  
#include <stdio.h>  
#define N 10000  
int main()  
{  
    int a[N]={1};  
    int k=0,l=1,n;  
    int i,j;  
    scanf("%d",&n);  
    for(i=1;i<=n;i++)  
    {  
        for(j=0;j<l;j++)  
        {  
            a[j]=a[j]*i+k;  
            k=a[j]/10000;  
            a[j]=a[j]%10000;  
        }  
        if(k)  
        {  
            a[j]=k;  
            l++;  
            k=0;  
        }  
    }  
    printf("%d",a[l-1]);  
    for(i=l-2;i>=0;i--)  
        printf("%04d",a[i]);  
    printf("\n");  
    return 0;  
}  
*/  
/*#include<stdio.h>
/*
    �׳˼���ݹ鷨 .

int f(int n);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}
int f(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return n*f(n-1);
	 }
	 */
	# include <stdio.h>  
int main()  
{  
    int a[10000]={0};  
    int i,n,k;  
    int weishu=1;  //��ʾ�����м�λ 
    int carry=0;  
    int temp;  
      
    a[1]=1;  
    scanf("%d", &n);  
      
    for (i=1; i<=n; i++)  //i=1,2,3,4 ,   ���� 
    {  
        for (k=1; k<=weishu; k++)  //kΪλ�����Ӹ�λ��ʮλ����λ 
        {                 
            temp = a[k]*i + carry;  //temp=1,2,6,24        ����λ�Ľ�� 
            a[k] = temp%10;  //a[1]=1,2,6,4
            carry = temp/10;  //carry=0,0,0,2              carryΪ��λ 
        }  
        while (carry)  //while(2
        {  
            a[++weishu] = carry%10;//a[2]=2  
            carry = carry/10;   //carry=0
        }  
    }     
      
    for (i=weishu; i>=1; i--)  
        printf("%d", a[i]);  
              
    return 0;  
}   
