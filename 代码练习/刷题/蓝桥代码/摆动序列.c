/*��������
�������һ������������������ʣ����Ǿͽ�����Ϊ�ڶ����У�
����1. �����е����������ǲ�����k����������
����2. ��������������������
����3. �����е�����������ȣ�
����4. �����i �C 1�����ȵ�i �C 2���������i�����ȵ�i �C 2����С�������i �C 1�����ȵ�i �C 2����С�����i�����ȵ�i �C 2������
�������磬��k = 3ʱ�������漸�����������У�
����1 2
����1 3
����2 1
����2 1 3
����2 3
����2 3 1
����3 1
����3 2
����һ����8�֣�����k���������������Ҫ������еĸ�����
�����ʽ
�������������һ������k����k<=20��
�����ʽ
�������һ����������ʾ����Ҫ������и�����
��������
3
�������
8*/ 
#include <stdio.h>
#include <math.h>
 
int main()
{
        int k;
        double kuye = 2;
        scanf_s("%d", &k);
        printf_s("%d\n", (int)(pow(kuye,k) - k - 1) * 2);
        //pow�����Ǽ���kuye��k����
        return 0;
}
/*
C++����ʵ�֣� 
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
    while(cin>>n)  //����n 
    {  
    sum=0;  
    memset(a,0,sizeof(a));//��ʼ��a������c����  
    memset(c,0,sizeof(c));    
    dfs(1);  
    cout<<sum<<endl;  
    }  
    return 0;  
}  */ 
