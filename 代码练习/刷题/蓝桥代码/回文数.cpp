
/*问题描述
　　若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。
　　例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。

　　又如：对于10进制数87：
　　STEP1：87+78 = 165 STEP2：165+561 = 726
　　STEP3：726+627 = 1353 STEP4：1353+3531 = 4884

　　在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

　　写一个程序，给定一个N（2<=N<=10或N=16）进制数M（其中16进制数字为0-9与A-F），求最少经过几步可以得到回文数。
　　如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”
输入格式
　　两行，N与M
输出格式
　　如果能在30步以内得到回文数，输出“STEP=xx”（不含引号），其中xx是步数；否则输出一行”Impossible!”（不含引号）
样例输入
9
87
样例输出
STEP=6*/

#include<iostream>  
#include<cstring>  
using namespace std;  
//全局变量 
int a[10000],b[10000],s[10001];  

bool huiwen(int s[], int l)  
{  
     int i,k;  
     k = (l - 1)/2;  
     for(i = 0; i <= k; i++)  
     {  
           if(s[i] != s[l - i -1])  
           break;  
           }  
     if(i == k+1)  
     return 1;  
     else  
     return 0;  
     }  
       
void inverse(int s[], int l)  
{  
     int i;  
     memset(a, 0, sizeof(a));  
     memset(b, 0, sizeof(b));  
     for(i = 0; i < l; i++)  
     {  
           a[i] = s[i];  
           b[l - i -1] = a[i];  
           }  
     }  
  
int main()  
{  
    int n,l,i,count = 0;  
    string m;  //m为数组 ，用来保存输入的字符串 
    cin>>n>>m;  //n为进制，m为字符串 
    l = m.size();  //l为字符串长度 
    for(i = 0; i < l; i++)  
    {  
          if(m[i] >= 'A' && m[i] <= 'Z')//m[i]为大写字母,即16进制  
          a[i] = m[i] - 'A' + 10;  //a[i]存储转换后的16进制 
          else  
          a[i] = m[i] - '0';  //a[i]存储非16进制的数 
          s[i] = a[i];  //? 
          b[l - i -1] = a[i];//b[]反向存储  
          }  
      
    while(!huiwen(s, l) && count <= 30)  
    {  
      count++;  
      memset(s, 0, sizeof(s));  
      for(i = 0; i < l; i++)  
      {  
            s[i] += a[i] + b[i];  
            s[i+1] += s[i]/n;  
            s[i] = s[i]%n;  
            }  
      if(s[l] != 0)  
      l = l + 1;  
      inverse(s, l);  
                     }  
    if(count <= 30)  
    cout<<"STEP="<<count<<endl;  
    else  
    cout<<"Impossible!"<<endl;  
      
    return 0;  
    }  
