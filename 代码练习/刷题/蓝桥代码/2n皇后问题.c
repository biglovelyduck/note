/*��������
��������һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з���n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ���
�ܹ��ж����ַŷ���nС�ڵ���8��
�����ʽ
��������ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
����������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�
�����ʽ
�������һ����������ʾ�ܹ��ж����ַŷ���
��������
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
�������
2
��������
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
�������
0*/ 
/*
#include<stdio.h>  
  
int sum=0;  
  
int p(int n,int x,int y,int m[][8],int s)  
{  
    int i,j;  
    for(i=x-1;i>=0;i--)  
    {  
        if(m[i][y]==s)return 0;  
    }  
    for(i=x-1,j=y-1;i>=0&&j>=0;i--,j--)  
    {  
        if(m[i][j]==s)return 0;  
    }  
    for(i=x-1,j=y+1;i>=0&&j<n;i--,j++)  
    {  
        if(m[i][j]==s)return 0;  
    }  
    return 1;  
}  
  
int h(int n,int x,int m[][8],int s)  
{  
    int i;  
    if(x==n)  
    {  
        if(s==2)h(n,0,m,3);  
        else sum++;  
        return 0;  
    }  
    for(i=0;i<n;i++)  
    {  
        if(m[x][i]!=1)continue;  
        if(p(n,x,i,m,s))m[x][i]=s;  
        else continue;  
        h(n,x+1,m,s);  
        m[x][i]=1;  
    }  
    return 0;  
}  
  
int main()  
{  
    int n,m[8][8],i,j;  
      
    scanf("%d",&n);  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            scanf("%d",&m[i][j]);  
        }  
    }  
    h(n,0,m,2);  
    printf("%d",sum);  
  
    return 0;  
} */ 
 /* 
˼·��ö��  Ȼ���⣬��˷  
�ܹ���s=n*n����   ����ÿ���� ������Ϊs/now,������Ϊs%n   
ˮƽ����  ֻ��Ҫ���0��s/now 
��ֱ����  ֻ��Ҫ���0��s%now 
б�߷��� ֻ��Ҫ������Ϻ�����  
�ܵ���s��Ϊһ�ַ��� �ۼ�  
*/  
#include<stdio.h>  
  
#include<string.h>  
  
#include<math.h>  
  
#define MAXSIZE 1000  
  
int bqueen[MAXSIZE];//�ڻʺ�  
  
int wqueen[MAXSIZE];//�׻ʺ�  
  
int chessboard[MAXSIZE][MAXSIZE];//1:�ܷ�  0:���ܷ�    
  
int count =0;  
  
int n;  
  
int place(int k);  
  
int BlackQueen(int k)  
  
{  
  
    int i;  
  
    int j;  
  
    for(i =0; i < k -1; i++)  
  
    {  
  
        int judge = bqueen[i]- bqueen[k -1];  
  
        if(judge ==0|| fabs(k -1- i)== fabs(judge))  
  
            return0;  
  
    }  
  
    if(k == n)  
  
    {  
  
        count++;  
  
        return0;  
  
    }  
  
    for( j =0; j < n; j++)  
  
    {  
  
        if(j != wqueen[k]&& chessboard[k][j])  
  
        {  
  
            bqueen[k]= j;  
  
            BlackQueen(k +1);  
  
        }  
  
         
  
    }  
  
         
  
     
  
}  
  
int WhiteQueen(int k)  
  
{  
  
    int i;  
  
    int j;  
  
    for( i =0; i < k -1; i++)  
  
    {  
  
        int judge = wqueen[i]- wqueen[k -1];  
  
        if(judge ==0|| fabs(k -1- i)== fabs(judge))  
  
            return0;  
  
    }  
  
    if(k == n)  
  
    {  
  
        BlackQueen(0);  
  
        return0;  
  
    }  
  
    for( j =0; j < n; j++)  
  
    {  
  
        if(chessboard[k][j])  
  
        {  
  
            wqueen[k]= j;  
  
            WhiteQueen(k +1);  
  
        }  
  
         
  
    }  
  
         
  
         
  
}  
  
   
  
int main(void)  
  
{   int i;  
  
    int j;  
  
   // freopen("input3.txt","r",stdin);//������ֱ�Ӵ��ļ��ж�ȡ����  
  
    scanf("%d",&n);  
  
    for(i =0; i < n; i++)  
  
        for(j =0; j < n; j++)  
  
        scanf("%d",&chessboard[i][j]);  
  
    WhiteQueen(0);  
  
    printf("%d\n",count);  
  
   
  
    return0;  
  
}  
