
/*��������
������һ��������λ��Ϊ�㣩�������Ҷ�������������һ�������Ǿͽ����֮Ϊ��������
�������磺����һ��10������56����56��65������56��������������õ�121��һ����������

�������磺����10������87��
����STEP1��87+78 = 165 STEP2��165+561 = 726
����STEP3��726+627 = 1353 STEP4��1353+3531 = 4884

�����������һ����ָ������һ��N���Ƶļӷ���������������4���õ�������4884��

����дһ�����򣬸���һ��N��2<=N<=10��N=16��������M������16��������Ϊ0-9��A-F���������پ����������Եõ���������
���������30�����ڣ�����30���������ܵõ����������������Impossible!��
�����ʽ
�������У�N��M
�����ʽ
�����������30�����ڵõ��������������STEP=xx�����������ţ�������xx�ǲ������������һ�С�Impossible!�����������ţ�
��������
9
87
�������
STEP=6*/

#include<iostream>  
#include<cstring>  
using namespace std;  
//ȫ�ֱ��� 
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
    string m;  //mΪ���� ����������������ַ��� 
    cin>>n>>m;  //nΪ���ƣ�mΪ�ַ��� 
    l = m.size();  //lΪ�ַ������� 
    for(i = 0; i < l; i++)  
    {  
          if(m[i] >= 'A' && m[i] <= 'Z')//m[i]Ϊ��д��ĸ,��16����  
          a[i] = m[i] - 'A' + 10;  //a[i]�洢ת�����16���� 
          else  
          a[i] = m[i] - '0';  //a[i]�洢��16���Ƶ��� 
          s[i] = a[i];  //? 
          b[l - i -1] = a[i];//b[]����洢  
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
