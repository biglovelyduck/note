#include<stdio.h>
int main()
{void swap(int *x,int n);
	int array[3]={1,2,3};
	int *p;
	p=array;
swap(p,3);
	//int *p;
	for(p=array;p<(array+3);p++)
printf("%d\n",*p);



return 0;
}
void swap(int *x,int n)
{
int *i,*j,t,m=(n-1)/2;
i=x,j=x+n-1;
for(;i<=m;i++,j--)
{t=*i,*i=*j,*j=t;}

}