/*问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问
总共有多少种放法？n小于等于8。
输入格式
　　输入的第一行为一个整数n，表示棋盘的大小。
　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
输出格式
　　输出一个整数，表示总共有多少种放法。
样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2
样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
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
思路：枚举  然后检测，回朔  
总共有s=n*n个点   对于每个点 横坐标为s/now,纵坐标为s%n   
水平方向  只需要检查0到s/now 
竖直方向  只需要检查0到s%now 
斜线方向 只需要检查左上和右上  
能到达s就为一种方案 累加  
*/  
#include<stdio.h>  
  
#include<string.h>  
  
#include<math.h>  
  
#define MAXSIZE 1000  
  
int bqueen[MAXSIZE];//黑皇后  
  
int wqueen[MAXSIZE];//白皇后  
  
int chessboard[MAXSIZE][MAXSIZE];//1:能放  0:不能放    
  
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
  
   // freopen("input3.txt","r",stdin);//这是我直接从文件中读取数据  
  
    scanf("%d",&n);  
  
    for(i =0; i < n; i++)  
  
        for(j =0; j < n; j++)  
  
        scanf("%d",&chessboard[i][j]);  
  
    WhiteQueen(0);  
  
    printf("%d\n",count);  
  
   
  
    return0;  
  
}  
