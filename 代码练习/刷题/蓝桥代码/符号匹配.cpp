#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <stack>  
using namespace std;  
char a[1000], s[1000], b[1000], b1[1000];  //�ַ����� 
stack<char> ss;  
  
int is_op(char c){  //�ж��ǲ������ţ�����1 
    if(  c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')  
        return 1;  
    return 0;  
}  
  
int if_com(char s, char t){  //�ж�һ�������ܷ�ƥ��ɹ�����1 
    if(s == '(' && t == ')')  
        return 1;     
    else if(s == '{' && t == '}')  
        return 1;  
    else if(s == '[' && t == ']')  
        return 1;  
    else if(s == '<' && t == '>')  
        return 1;  
    return 0;  
}  
  
int main(){  
    int k = 0, n, count, i, j;  
    while(1){  
        if(a[0] == '.' && strlen(a) == 1)  
            break;  
          
        scanf("%s", &a);  //ÿ�λ�ȡһ�� ��ջ����� 
        getchar();  //��ȡ�������Ļس��� 
        int len = strlen(a);  //�����ַ����ĳ��� 
        for( i = 0; i < len; ++i){  //����ѭ��������ע�������s������ 
            if(is_op(a[i]))  //������ 
                s[k++] = a[i];  //ȡ�����ŷ���s�� 
            else if((a[i] == '/' && a[i + 1] == '*')){//���������ж��ǲ�����ע��  
                s[k++] = '<';   //��'<'�滻��ע�� 
                ++i;  //i�ȼ�1����ȡֵ 
            }  
            else if((a[i] == '*' && a[i + 1] == '/')){  //���������ж��ǲ�����ע��  
                s[k++] = '>';  
                ++i;  
            }  
        }  
          
    }  
    n = k; // nΪ��������ĳ��� 
    count = 0;  
/*  for( i = 0; i < n; ++i) 
        printf("%c", s[i]); 
    printf("\n\n");*/  
    for(i = 0; i < n; ++i){  
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')  
            ss.push(s[i]);  //����ߵ����ž�ѹ��ջ�� 
        else if(!ss.empty()){ //���� s[i]���������ţ�ssΪ�շ���true�� ss����Ԫ�� 
            if(if_com(ss.top(), s[i]) == 1){ //��Գɹ� 
                ss.pop();  
            }  
            else   //��ջ��Ԫ��ƥ�䲻�ɹ����������ŷ���ջ�� 
                ss.push(s[i]);  
        }  
        else //ջΪ�� 
            ss.push(s[i]);  
    }  
    if(ss.empty()){  
        printf("YES\n");  
    }  
    else {  //ջ��Ϊ�գ����滹��������      
      k = 0;  
        while(!ss.empty()){ //ջ��Ϊ�� 
        b[k++] = ss.top();  
        ss.pop();  
    }  
    n = k;  //n�����ʣ�µ����� 
    for(i = 0; i < n; ++i)  
        b1[n - i - 1] = b[i];  
          
    int tt = n - 1;  
    for(i = 0; i < tt; ++i){  
        for(j = tt; j > i; j--){  
            if(if_com(b1[i], b1[j]) || if_com(b1[j], b1[i])){  
                b1[i] = '@';  
                b1[j] = '@';  
                tt = j - 1;  
            }  
        }  
    }  
    char aa;   
    for(i = 0; i < n; ++i) {  
        if(b1[i] != '@'){  
            aa = b1[i];  
            break;  
        }  
    }  
    if(aa == '(') printf("NO\n(-?\n");  
    if(aa == '[') printf("NO\n[-?\n");  
    if(aa == '{') printf("NO\n{-?\n");  
    if(aa == '<') printf("NO\n/*-?\n");  
    if(aa == ')') printf("NO\n?-)\n");  
    if(aa == ']') printf("NO\n?-]\n");  
    if(aa == '}') printf("NO\n?-}\n");  
    if(aa == '>') printf("NO\n?-*/\n");  
    }  
    return 0;  
}
