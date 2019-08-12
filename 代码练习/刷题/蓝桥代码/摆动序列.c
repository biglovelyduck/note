/*问题描述
　　如果一个序列满足下面的性质，我们就将它称为摆动序列：
　　1. 序列中的所有数都是不大于k的正整数；
　　2. 序列中至少有两个数。
　　3. 序列中的数两两不相等；
　　4. 如果第i – 1个数比第i – 2个数大，则第i个数比第i – 2个数小；如果第i – 1个数比第i – 2个数小，则第i个数比第i – 2个数大。
　　比如，当k = 3时，有下面几个这样的序列：
　　1 2
　　1 3
　　2 1
　　2 1 3
　　2 3
　　2 3 1
　　3 1
　　3 2
　　一共有8种，给定k，请求出满足上面要求的序列的个数。
输入格式
　　输入包含了一个整数k。（k<=20）
输出格式
　　输出一个整数，表示满足要求的序列个数。
样例输入
3
样例输出
8*/ 
#include <stdio.h>
#include <math.h>
 
int main()
{
        int k;
        double kuye = 2;
        scanf_s("%d", &k);
        printf_s("%d\n", (int)(pow(kuye,k) - k - 1) * 2);
        //pow函数是计算kuye的k次幂
        return 0;
}
/*
C++代码实现： 
#include<iostream>  
#include<cstring>  
using namespace std;  
int a[110],c[110],sum=0,n;  
int fun(int x,int s)  
{  
    if(s==1||s==2)  
    return 1;  
    if(c[s-1]>c[s-2]&&x<c[s-2])  
    return 1;  
    if(c[s-1]<c[s-2]&&x>c[s-2])  
    return 1;  
    return 0;  
}  
void dfs(int cur)  
{  
    int i;  
    if(cur>n)  
    return;  
for(i=1;i<=n;i++)  
    {  
        if(!a[i]&&fun(i,cur))  
        {  
            a[i]=1;  
            c[cur]=i;  
            if(cur>=2)  
            sum++;  
            dfs(cur+1);  
            a[i]=0;  
        }  
    }  
}  
int main()  
{  
    c[1]=0;  
    while(cin>>n)  //输入n 
    {  
    sum=0;  
    memset(a,0,sizeof(a));//初始化a【】，c【】  
    memset(c,0,sizeof(c));    
    dfs(1);  
    cout<<sum<<endl;  
    }  
    return 0;  
}  */ 
