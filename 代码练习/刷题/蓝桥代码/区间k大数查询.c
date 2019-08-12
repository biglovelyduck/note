/*  
算法训练 区间k大数查询  
  
问题描述  
给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。  
  
输入格式  
第一行包含一个数n，表示序列长度。  
  
第二行包含n个正整数，表示给定的序列。  
  
第三个包含一个正整数m，表示询问个数。  
  
接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。  
  
输出格式  
总共输出m行，每行一个数，表示询问的答案。  
样例输入  
5  
1 2 3 4 5  
2  
1 5 2  
2 3 2  
样例输出  
4  
2  
数据规模与约定  
对于30%的数据，n,m<=100；  
  
对于100%的数据，n,m<=1000；  
  
保证k<=(r-l+1)，序列中的数<=10de6次方。  
*/  
#include <stdio.h>  
#include <stdlib.h>  
  
int Split(int *data,int pre,int rear)  
{  
    int value=data[pre];   
    while(pre<rear)  
    {  
        while(data[rear]>=value && pre<rear) rear--;  //当data[rear]小于value时跳出循环 
        data[pre]=data[rear];  //给data[pre]附小值 
        while(data[pre]<value && pre<rear) pre++;  
        data[rear]=data[pre];  //给data[rear]附大值 
    }  
    data[pre]=value;  //pre为数组的中间位置，data[pre}为最左边自己地定义的关键词 
    return pre;  
}  
  
//快速排序  
void QuickSort(int *data,int pre,int rear,int k)  //k为数组中要输出元素的位置 
{  
    if(pre<=rear)  
    {  
        int mid=Split(data,pre,rear);  
        if(mid==k)  
        {  
            printf("%d\n",data[mid]);  
        }  
        else if(mid>k)  
        {  
            QuickSort(data,pre,mid-1,k);  
        }  
        else  
        {  
            QuickSort(data,mid+1,rear,k);  
        }  
    }  
}  
  
void Copy(int *data,int n,int *temp)  
{  
    int i;  
    for(i=0;i<n;i++)  
    {  
        temp[i]=data[i];  
    }  
}  
  
int main()  
{  
    int i;  
    int n;  
    int m;  
    int *data;  
    scanf("%d",&n);  
    data=(int *)malloc(sizeof(int)*n);  
    for(i=0;i<n;i++)  
    {  
        scanf("%d",&data[i]);  
    }  
    scanf("%d",&m);  
    while(m)  
    {  
        int pre;  
        int rear;  
        int k;  //第几大的数 
        int *temp=(int *)malloc(sizeof(int)*n);  
        scanf("%d%d%d",&pre,&rear,&k);  
        Copy(data,n,temp);  
        QuickSort(temp,pre-1,rear-1,rear-k);  //rear-k为快速排序后在数组中的实际位置 
        m--;  
    }  
    return 0;  
}  
/*  
#include<stdio.h>  
#include<math.h>  
  
main()  
{  
    int m,n,l,r,K,a[1001]={0},b[1001]={0},c[1001]={0};  
    int i=0,j=0,k=0,t=0;  
      
    //输入N个数，将其依次赋值给数组a  
    do  
    {  
        scanf("%d",&n);  
    }  
    while(n>1000);  
      
    for(i=1;i<=n;i++)  
    {  
        scanf("%d",&a[i]);  
        if(a[i]>10*10*10*10*10*10)  
            scanf("%d",&a[i]);  
    }  
      
    //输出M组数，一次得到M组LRK的值  
    do  
    {  
        scanf("%d",&m);  
    }  
    while(m>1000);  
      
    for(t=1;t<=m;t++)  
    {  
        scanf("%d%d%d",&l,&r,&K);  
            if(K>(r-l+1))  
            scanf("%d%d%d",&l,&r,&K);  
          
        //将数组a中第L到第R个数依次赋值给数组b  
        for(i=l,k=0;i<=r;i++)  
        {  
            k++;  
            b[k]=a[i];  
        }  
          
        //对数组b进行从大到小排序  
        for(i=1;i<=k-1;i++)  
        for(j=1;j<=k+1-i;j++)  
        {  
            if(b[j]>=b[j-1])  
            {  
                b[0]=b[j];  
                b[j]=b[j-1];  
                b[j-1]=b[0];  
            }  
        }  
        //将数组b中第K个数K传递给数组c   
        c[t]=b[K];    
    }  
    //输出数组c  
    for(i=1;i<=m;i++)  
    printf("%d\n",c[i]);  
}   
*/  
