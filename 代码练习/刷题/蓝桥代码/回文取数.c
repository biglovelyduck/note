/*问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2*/ 
#include <stdio.h>  
#include <string.h>  
  
#define MAX_N 200  
int m,n;  
int a[MAX_N][MAX_N],b[MAX_N][MAX_N];  
int s=0; //用来判定四个角落 
void solve(int i,int j)  
{  
    if(i<m && i>=0 && j<n && j>=0 && b[i][j] == 0)  
    {  
        printf("%d ",a[i][j]);  
        b[i][j] = 1;  
      
    }  
    else  //当i=m或j=n或b[i][j]=1时s++ 
    {  
        s++;   
        return ;  
    }  
    if(s%4 == 0)  //向下走 
    solve(i+1,j);  
    if(s%4 == 1)  //向右走 
    solve(i,j+1);  
    if(s%4 == 2)  //向上走 
    solve(i-1,j);  
    if(s%4 == 3)  //向左走 
    solve(i,j-1);  
    if(s%4 == 0)  
    solve(i+1,j);  
    if(s%4 == 1)  
    solve(i,j+1);  
    if(s%4 == 2)  
    solve(i-1,j);  
    if(s%4 == 3)  
    solve(i,j-1);  
  
    return ;  
}  
  
int main()  
{  
    memset(b,0,sizeof(b));  //将数组b填充值为0 
    scanf("%d%d",&m,&n);  
    int i,j;  
    for(i=0; i<m; i++)  
        for(j=0; j<n; j++)  
            scanf("%d",&a[i][j]);  
    solve(0,0);  
    //puts("");  
    return 0;  
}  
/*C++实现*/
/*#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
int main(){  
   int m,n;  
   cin>>m>>n;  
   int a[m][n];  
   int i,j;  
   for(i=0;i<m;i++){  
    for(j=0;j<n;j++){  
        cin>>a[i][j];  
    }  
   }  
   int sum=m*n;  
   i=-1;j=0;  
   while(sum){  
    //向下走  
    while(a[++i][j]!=-1 && i<m){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    i--;  
     
   //向右走  
    while(a[i][++j]!=-1 && j<n){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    j--;  
    //向上走  
    while(a[--i][j]!=-1 && i>=0){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    i++;  
    //向左走  
    while(a[i][--j]!=-1 && j>=0){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    j++;  
   }  
    return 0;  
}  */
