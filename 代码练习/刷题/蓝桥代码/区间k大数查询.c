/*  
�㷨ѵ�� ����k������ѯ  
  
��������  
����һ�����У�ÿ��ѯ�������е�l��������r�����е�K��������ĸ���  
  
�����ʽ  
��һ�а���һ����n����ʾ���г��ȡ�  
  
�ڶ��а���n������������ʾ���������С�  
  
����������һ��������m����ʾѯ�ʸ�����  
  
������m�У�ÿ��������l,r,K����ʾѯ�����д������ҵ�l��������r�����У��Ӵ���С��K��������ĸ�������Ԫ�ش�1��ʼ��š�  
  
�����ʽ  
�ܹ����m�У�ÿ��һ��������ʾѯ�ʵĴ𰸡�  
��������  
5  
1 2 3 4 5  
2  
1 5 2  
2 3 2  
�������  
4  
2  
���ݹ�ģ��Լ��  
����30%�����ݣ�n,m<=100��  
  
����100%�����ݣ�n,m<=1000��  
  
��֤k<=(r-l+1)�������е���<=10de6�η���  
*/  
#include <stdio.h>  
#include <stdlib.h>  
  
int Split(int *data,int pre,int rear)  
{  
    int value=data[pre];   
    while(pre<rear)  
    {  
        while(data[rear]>=value && pre<rear) rear--;  //��data[rear]С��valueʱ����ѭ�� 
        data[pre]=data[rear];  //��data[pre]��Сֵ 
        while(data[pre]<value && pre<rear) pre++;  
        data[rear]=data[pre];  //��data[rear]����ֵ 
    }  
    data[pre]=value;  //preΪ������м�λ�ã�data[pre}Ϊ������Լ��ض���Ĺؼ��� 
    return pre;  
}  
  
//��������  
void QuickSort(int *data,int pre,int rear,int k)  //kΪ������Ҫ���Ԫ�ص�λ�� 
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
        int k;  //�ڼ������ 
        int *temp=(int *)malloc(sizeof(int)*n);  
        scanf("%d%d%d",&pre,&rear,&k);  
        Copy(data,n,temp);  
        QuickSort(temp,pre-1,rear-1,rear-k);  //rear-kΪ����������������е�ʵ��λ�� 
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
      
    //����N�������������θ�ֵ������a  
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
      
    //���M������һ�εõ�M��LRK��ֵ  
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
          
        //������a�е�L����R�������θ�ֵ������b  
        for(i=l,k=0;i<=r;i++)  
        {  
            k++;  
            b[k]=a[i];  
        }  
          
        //������b���дӴ�С����  
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
        //������b�е�K����K���ݸ�����c   
        c[t]=b[K];    
    }  
    //�������c  
    for(i=1;i<=m;i++)  
    printf("%d\n",c[i]);  
}   
*/  
