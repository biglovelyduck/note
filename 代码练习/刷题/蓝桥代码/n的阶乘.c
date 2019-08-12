/*问题描述
　　输入一个正整数n，输出n!的值。
　　其中n!=1*2*3*…*n。
算法描述
　　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
　　将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
　　首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
　　输入包含一个正整数n，n<=1000。
输出格式
　　输出n!的准确值。
样例输入
10
样例输出
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
      
    //数组清零且个位初始化为1   
    memset(A,0,MaxSize*sizeof(int));   
    A[0]=1;  
  
    scanf("%d",&n);  
    //用i依次乘以数组A   
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
    阶乘计算递归法 .

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
    int weishu=1;  //表示数字有几位 
    int carry=0;  
    int temp;  
      
    a[1]=1;  
    scanf("%d", &n);  
      
    for (i=1; i<=n; i++)  //i=1,2,3,4 ,   乘数 
    {  
        for (k=1; k<=weishu; k++)  //k为位数，从个位到十位到百位 
        {                 
            temp = a[k]*i + carry;  //temp=1,2,6,24        各个位的结果 
            a[k] = temp%10;  //a[1]=1,2,6,4
            carry = temp/10;  //carry=0,0,0,2              carry为进位 
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
