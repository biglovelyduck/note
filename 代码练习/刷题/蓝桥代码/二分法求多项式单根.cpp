/*9 二分法求多项式单根（20 分）
二分法求函数根的原理为：如果连续函数f(x)在区间[a,b]的两个端点取值异号，即f(a)f(b)<0，则它在这个区间内至少存在1个根r，即f(r)=0。

二分法的步骤为：

检查区间长度，如果小于给定阈值，则停止，输出区间中点(a+b)/2；否则
如果f(a)f(b)<0，则计算中点的值f((a+b)/2)；
如果f((a+b)/2)正好为0，则(a+b)/2就是要求的根；否则
如果f((a+b)/2)与f(a)同号，则说明根在区间[(a+b)/2,b]，令a=(a+b)/2，重复循环；
如果f((a+b)/2)与f(b)同号，则说明根在区间[a,(a+b)/2]，令b=(a+b)/2，重复循环。
本题目要求编写程序，计算给定3阶多项式f(x)=a
?3
?? x
?3
?? +a
?2
?? x
?2
?? +a
?1
?? x+a
?0
?? 在给定区间[a,b]内的根。

输入格式：

输入在第1行中顺序给出多项式的4个系数a
?3
?? 、a
?2
?? 、a
?1
?? 、a
?0
?? ，在第2行中顺序给出区间端点a和b。题目保证多项式在给定区间内存在唯一单根。

输出格式：

在一行中输出该多项式在该区间内的根，精确到小数点后2位。

输入样例：

3 -1 -3 1
-0.5 0.5
输出样例：

0.33*/


/*#include <iostream>

using namespace std;

    float a3,a2,a1,a0;

float f(float a,float b){

	if((a3*a*a*a+a2*a*a+a1*a+a0)*(a3*b*b*b+a2*b*b+a1*b+a0)>=0) {
		return (a+b)/2.0;
	}
	else{
		float c=(a+b)/2.0;
		if((a3*c*c*c+a2*c*c+a1*c+a0)==0) return (a+b)/2.0;
		else{
		if((a3*a*a*a+a2*a*a+a1*a+a0)*(a3*c*c*c+a2*c*c+a1*c+a0)>=0) f(c,b);
	    if((a3*b*b*b+a2*b*b+a1*b+a0)*(a3*c*c*c+a2*c*c+a1*c+a0)>=0) f(a,c);	
	 }
	}
}

int main(int argc, char** argv) {
	float a,b;
    cin>>a3>>a2>>a1>>a0;
    cin>>a>>b;
    printf("%.2f",f(a,b));
	return 0;
}*/
 1 #include<stdio.h>
 2 #include<stdlib.h>
 3 #include<math.h>
 4 double f(double x, double a3, double a2, double a1, double a0);
 5 int main()
 6 {
 7     double  a3, a2, a1, a0;
 8     double a, b, x;
 9     scanf("%lf%lf%lf%lf%lf%lf", &a3, &a2, &a1, &a0, &a, &b);
10     x = (b + a) / 2;
11     if(f(a, a3, a2, a1, a0) == 0)
12         x = a;
13     else if(f(b, a3, a2, a1, a0) == 0)
14         x = b;
15     else
16     {
17         while(b - a >= 0.01)
18         {
19             if(f(x, a3, a2, a1, a0) == 0)
20                 break;
21             else if(f(x, a3, a2, a1, a0) * f(a, a3, a2, a1, a0) > 0)
22                 a = x;
23             else if(f(x, a3, a2, a1, a0) * f(b, a3, a2, a1, a0) > 0)
24                 b = x;
25             if(f(a, a3, a2, a1, a0) * f(b, a3, a2, a1, a0) < 0)
26                 x = (b + a) / 2;
27         }
28     }
29     printf("%.2f\n", x);
30     return 0;
31 }
32 
33 double f(double x, double a3, double a2, double a1, double a0)
34 {
35     return a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0;
36 }
