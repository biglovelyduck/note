/*9 ���ַ������ʽ������20 �֣�
���ַ���������ԭ��Ϊ�������������f(x)������[a,b]�������˵�ȡֵ��ţ���f(a)f(b)<0��������������������ٴ���1����r����f(r)=0��

���ַ��Ĳ���Ϊ��

������䳤�ȣ����С�ڸ�����ֵ����ֹͣ����������е�(a+b)/2������
���f(a)f(b)<0��������е��ֵf((a+b)/2)��
���f((a+b)/2)����Ϊ0����(a+b)/2����Ҫ��ĸ�������
���f((a+b)/2)��f(a)ͬ�ţ���˵����������[(a+b)/2,b]����a=(a+b)/2���ظ�ѭ����
���f((a+b)/2)��f(b)ͬ�ţ���˵����������[a,(a+b)/2]����b=(a+b)/2���ظ�ѭ����
����ĿҪ���д���򣬼������3�׶���ʽf(x)=a
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
?? �ڸ�������[a,b]�ڵĸ���

�����ʽ��

�����ڵ�1����˳���������ʽ��4��ϵ��a
?3
?? ��a
?2
?? ��a
?1
?? ��a
?0
?? ���ڵ�2����˳���������˵�a��b����Ŀ��֤����ʽ�ڸ��������ڴ���Ψһ������

�����ʽ��

��һ��������ö���ʽ�ڸ������ڵĸ�����ȷ��С�����2λ��

����������

3 -1 -3 1
-0.5 0.5
���������

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
