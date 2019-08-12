#include<stdio.h>
int main(){
	int array[3]={1,2,3};
	int *p,i;
	p=array;
	for(i=0;i<3;p++)
printf("%d",*p);
return 0;


}