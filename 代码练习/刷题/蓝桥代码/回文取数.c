/*��������
��������ȡ�������ؾ���ı�ȡ��������ǰ������������ȡ���Ѿ�ȡ��������ת90�ȡ�һ��ʼλ�ھ������Ͻǣ��������¡�
�����ʽ
���������һ��������������200��������m, n����ʾ������к��С�������m��ÿ��n����������ʾ�������
�����ʽ
�������ֻ��һ�У���mn������Ϊ����������ȡ���õ��Ľ������֮����һ���ո�ָ�����ĩ��Ҫ�ж���Ŀո�
��������
3 3
1 2 3
4 5 6
7 8 9
�������
1 4 7 8 9 6 3 2 5
��������
3 2
1 2
3 4
5 6
�������
1 3 5 6 4 2*/ 
#include <stdio.h>  
#include <string.h>  
  
#define MAX_N 200  
int m,n;  
int a[MAX_N][MAX_N],b[MAX_N][MAX_N];  
int s=0; //�����ж��ĸ����� 
void solve(int i,int j)  
{  
    if(i<m && i>=0 && j<n && j>=0 && b[i][j] == 0)  
    {  
        printf("%d ",a[i][j]);  
        b[i][j] = 1;  
      
    }  
    else  //��i=m��j=n��b[i][j]=1ʱs++ 
    {  
        s++;   
        return ;  
    }  
    if(s%4 == 0)  //������ 
    solve(i+1,j);  
    if(s%4 == 1)  //������ 
    solve(i,j+1);  
    if(s%4 == 2)  //������ 
    solve(i-1,j);  
    if(s%4 == 3)  //������ 
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
    memset(b,0,sizeof(b));  //������b���ֵΪ0 
    scanf("%d%d",&m,&n);  
    int i,j;  
    for(i=0; i<m; i++)  
        for(j=0; j<n; j++)  
            scanf("%d",&a[i][j]);  
    solve(0,0);  
    //puts("");  
    return 0;  
}  
/*C++ʵ��*/
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
    //������  
    while(a[++i][j]!=-1 && i<m){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    i--;  
     
   //������  
    while(a[i][++j]!=-1 && j<n){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    j--;  
    //������  
    while(a[--i][j]!=-1 && i>=0){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    i++;  
    //������  
    while(a[i][--j]!=-1 && j>=0){  
        cout<<a[i][j]<<" ";  
        a[i][j]=-1;  
        sum--;  
    }  
    j++;  
   }  
    return 0;  
}  */
