#include<stdio.h>
int main()
{
	int swap(int point1,int point2);
int a=10,b=100;
int* p1,* p2;
//int temp;
p1=&a,p2=&b;
printf("%5d%5d\n",*p1,*p2);
//int temp;
/*temp=*p1;
*p1=*p2;
*p2=temp;*/
/*p1=&b,p2=&a;
printf("%5d%5d\n",*p1,*p2);*/
printf("%5d%5d",swap(*p1,*p2));
return 0;
}
int swap(int point1,int point2)
{
int a;
a=point1;
point1=point2;
point2=a;

return(point1,point2);
}
