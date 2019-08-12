#include <stdio.h>
int x,y,z;
void f(int *a,int b){
	*a=2;
	b=2;
	z=b;
}
int main()
{
	x=y=1;
	f(&x,y);
	printf("%d\n%d\n%d",x,y,z);
	return 0;
}
