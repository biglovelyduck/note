#include<stdio.h>
int main()
{
/*int n,i;
for(n=100;n<200;n++)
{
	i=2;
	while(i<n)
	{
		if(n%i==0) break;

	i++;
	}
	printf("%d",n);
if(i=n) printf("n=%d是素数",n);	
}*/
int n,i;
scanf("%d",&n);
for(i=2;i<n;i++){
if(n%i==0) break;


}
if(i<n) printf("%d不是素数",n);
else printf("%d是素数",n);
return 0;
}