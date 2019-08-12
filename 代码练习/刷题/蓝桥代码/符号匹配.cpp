#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <stack>  
using namespace std;  
char a[1000], s[1000], b[1000], b1[1000];  //字符数组 
stack<char> ss;  
  
int is_op(char c){  //判断是不是括号，返回1 
    if(  c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')  
        return 1;  
    return 0;  
}  
  
int if_com(char s, char t){  //判断一堆括号能否匹配成功返回1 
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
          
        scanf("%s", &a);  //每次获取一行 清空缓存区 
        getchar();  //获取缓冲区的回车键 
        int len = strlen(a);  //输入字符串的长度 
        for( i = 0; i < len; ++i){  //整个循环将括号注解放入了s数组中 
            if(is_op(a[i]))  //是括号 
                s[k++] = a[i];  //取出括号放入s中 
            else if((a[i] == '/' && a[i + 1] == '*')){//不是括号判断是不是左注解  
                s[k++] = '<';   //用'<'替换左注解 
                ++i;  //i先加1，再取值 
            }  
            else if((a[i] == '*' && a[i + 1] == '/')){  //不是括号判断是不是右注解  
                s[k++] = '>';  
                ++i;  
            }  
        }  
          
    }  
    n = k; // n为括号数组的长度 
    count = 0;  
/*  for( i = 0; i < n; ++i) 
        printf("%c", s[i]); 
    printf("\n\n");*/  
    for(i = 0; i < n; ++i){  
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')  
            ss.push(s[i]);  //是左边的括号就压入栈中 
        else if(!ss.empty()){ //或者 s[i]不是左括号（ss为空返回true） ss中有元素 
            if(if_com(ss.top(), s[i]) == 1){ //配对成功 
                ss.pop();  
            }  
            else   //与栈顶元素匹配不成功，将右括号放入栈中 
                ss.push(s[i]);  
        }  
        else //栈为空 
            ss.push(s[i]);  
    }  
    if(ss.empty()){  
        printf("YES\n");  
    }  
    else {  //栈不为空，里面还有左括号      
      k = 0;  
        while(!ss.empty()){ //栈不为空 
        b[k++] = ss.top();  
        ss.pop();  
    }  
    n = k;  //n保存的剩下的括号 
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
