#include<stdio.h>
#define PAI 3.14159265358979323
void main(){

	int a;
	double r,s;
	scanf("%d",&a);
	r=a;
	s=PAI*r*r;
	printf("%.7lf",s);
}