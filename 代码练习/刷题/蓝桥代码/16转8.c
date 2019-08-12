/*#include <stdio.h>
#include <stdlib.h>
#define N 100001

void getTrans(char num[][N]);
/*基础练习 十六进制转八进制  
  
问题描述  
　　给定n个十六进制正整数，输出它们对应的八进制数。  
输入格式  
　　输入的第一行为一个正整数n （1<=n<=10）。  
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。  
输出格式  
　　输出n行，每行为输入对应的八进制正整数。  
注意  
　　输入的十六进制数不会有前导0，比如012A。  
　　输出的八进制数也不能有前导0。  
样例输入  
2  
39  
123ABC  
样例输出  
71  
4435274  
提示  
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。 */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	/*int n;
	
int main(int argc, char *argv[]) {
	int i,j;
	char a[11][N];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	/*getTrans(a);*/
/*
	for(i=0;i<n;i++){
		for(j=0;j<strlen(a[i]);j++){
		printf("%s\t\t",a[i][j]);
	}
	}
	return 0;
}
void getTrans(char num[][N]){
	int i,j,m=1;
	int b[11];
	for(i=0;i<n;i++){
		for(j=strlen(num[i])-1;j>=0;j--){
		if(num[i][j]<'9'){
			b[i]+=(num[i][j]-'0')*m;
		}
		else{
			b[i]+=(num[i][j]-'A'+10)*m;
		}
		m*=16;
		}
		m=1;
	}
	for(i=0;i<n;i++){
		printf("%d\t",b[i]);
	}
}*/
#include<stdio.h>
#include<string.h>  
int main()  
{  
    int n,i,j,k,a,cur,ok,m,l;  
    char s[10][100001],d16[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},out[140000]={},z[13]={};  
    scanf("%d",&n);                        
    for(j=0;j<n;j++)  
        scanf("%s",s[j]);  
    for(j=0;j<n;j++)  
        {  
            k=0;ok=1;m=0;                            /*初始化标记数据*/   
            l=strlen(s[j]);                           /* 初始化标记数据*/   
            a=3-l%3;                                   /*初始化标记数据*/   
            if(a==3)    ok=0;                    /*十六进制数长度刚好为3的倍数时转二进制不需补0，ok标记其是否为3的倍数0是1不是*/   
            for(i=0;i<l;i++)                       /*逐位读取十六进制数进行转换*/   
            {  
                if(65<=s[j][i])                            
                    s[j][i]-=7;  
                if(ok)                                     /*十六进制数位数不足转二进制时补0占位*/   
                    if(a==1){  
                        strcat(z,"0000");k=k+4;ok=0;  
                    }else if(a==2){  
                        strcat(z,"00000000");k=k+8;ok=0;  
                    }  
                z[k++]=d16[s[j][i]-48][0];                  /*一位十六进制转四位二进制*/   
                z[k++]=d16[s[j][i]-48][1];  
                z[k++]=d16[s[j][i]-48][2];  
                z[k++]=d16[s[j][i]-48][3];  
                if(k==12)                                    /*每转三位十六进制数将其转为四位八进制数*/   
                {  
                    for(cur=0;cur<12;m++)  
                        out[m]=((z[cur++]-48)*4+(z[cur++]-48)*2+(z[cur++]-48)*1)+48;  
                    z[0]='\0';k=0;                               /*z[0]='\0'初始化字符串结束符位置避免溢出*/   
                }  
            }                                        
            for(;k<3;k++)                                  /*输出时忽略前导0*/   
                if(out[k]!=48)  break;  
            for(;k<m;k++)  
                printf("%c",out[k]);  
            putchar('\n');  
        }  
    return 0;  
 } 