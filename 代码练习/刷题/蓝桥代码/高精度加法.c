/*问题描述
　　输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
算法描述
　　由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
　　定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
　　计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，
即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。
　　最后将C输出即可。
输入格式
　　输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
输出格式
　　输出一行，表示a + b的值。
样例输入
20100122201001221234567890
2010012220100122
样例输出
20100122203011233454668012*/ 
/*
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
void f(char a[],char b[])  
{  
    int w=200,i,j,la,lb;  
    la=strlen(a);lb=strlen(b);  
    char c[200];  
    for(i=la;i<w;i++)a[i]=48;  
    for(i=lb;i<w;i++)b[i]=48;  
    a[w-1]=0;b[w-1]=0;  
    for(i=0;i<la;i++)c[i]=a[i];  
    for(i=0;i<w-1-la;i++)a[i]=48;j=0;  
    for(i=w-1-la;i<w-1;i++){a[i]=c[j];j++;}  
  
    for(i=0;i<lb;i++)c[i]=b[i];  
    for(i=0;i<w-1-lb;i++)b[i]=48;j=0;  
    for(i=w-1-lb;i<w-1;i++){b[i]=c[j];j++;}  
  
    for(i=w;i>=0;i--)  
    {  
        j=a[i]+b[i]-96;  
        if(j>9)a[i-1]=a[i-1]+j/10;  
        c[i]=j%10+48;  
    }  
    c[w-1]=0;  
    for(i=0;i<w;i++)if(c[i]!='0')break;  
    for(;i<w-1;i++)printf("%c",c[i]);printf("\n");  
}  
  
int main()  
{  
    char a[200],b[200];gets(a);gets(b);  
    f(a,b);  
return 0;  
}  
*/










 #include<stdio.h>
 #include<string.h>
 int main()
 {
     char a[200],b[200];//定义字符串数组
     int c[500]; 
     scanf("%s%s",a,b);//输入字符串数组
     int i,j,k=0,r=0;
     int lena,lenb;
     lena = strlen(a);
     lenb = strlen(b);
     for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--){ //跳出循环的条件：两数组其中一个完了 
         int p=(a[i]-'0')+(b[j]-'0')+r;  //每一位的结果  
         r=p/10;//进位  
         c[k++]=p%10;//余数加到数组中  ，如果p<10直接放进去，否则p>10放余数 
     }
     while(i>=0){   //如果b中的数加完了  
         int p=(a[i]-'0')+r;  
         r=p/10;  
         c[k++]=p%10;  
         i--;  
     }  
     while(j>=0){    //如果a中的数加完了  
         int p=(b[j]-'0')+r;  
         r=p/10;  
         c[k++]=p%10;  
        j--;  
     }  
     if(r){//判断最高位有没有进位
         c[k++]=r;  
     }  
     for( i=k-1;i>=0;i--){//输出结果 
        printf("%d",c[i]);
     }
     return 0;
 }
  
