#include<stdio.h>
int main()
{int c,m,e,i;
double
i=1;
while(i<=5)
{
printf("输入第%d个学生的成绩"，i);
scanf("%d%d%d",&c,&m,&e);
ave=(c+m+e)/3.0;
printf("第%d个学生的成绩,c:%d,m:%d,e:%d,ave:%f\n",c,m,e,ave);
i++;
}
return 0;
}