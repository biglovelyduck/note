/*  
基础练习 字符串对比  
  
问题描述  
　　给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关  
  
系是以下4中情况之一：  
　　1：两个字符串长度不等。比如 Beijing 和 Hebei  
　　2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如   
  
Beijing 和 Beijing  
　　3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完  
  
全一致（也就是说，它并不满足情况2）。比如 beijing 和 BEIjing  
　　4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比  
  
如 Beijing 和 Nanjing  
　　编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号  
  
。  
输入格式  
　　包括两行，每行都是一个字符串  
输出格式  
　　仅有一个数字，表明这两个字符串的关系编号  
样例输入  
BEIjing  
beiJing  
样例输出  
3  
*/  
#include<stdio.h>  
#include<string.h>  
int main()  
{  
    char a[10],b[10],i,n,l=2;  
    gets(a);
	gets(b); //gets获取的字符串直接放到数组里 ，遇到回车结束 
    n=strlen(a);  
    if(strlen(b)!=n)
       l=1;  //strlen取字符串长度 
    else  
    {  
    for(i=0;i<n;i++)  
    if(a[i]==b[i]||a[i]==b[i]+32||a[i]+32==b[i])  
        if(a[i]!=b[i])
		l=3;  
        else 
		;else
		 {l=4;break;}  
    }  
printf("%d",l);  
return 0;  
}  
