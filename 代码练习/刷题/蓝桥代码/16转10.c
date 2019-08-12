#include <stdio.h>
#include <string.h>  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[9];
	int i;
	unsigned int n=1,add=0;
	scanf("%s",a);
	for(i=strlen(a)-1;i>=0;i--){
		if(a[i]<='9')
		{
			add+=(a[i]-'0')*n;
		}
		else
		{
			add+=(a[i]-'A'+10)*n; 
		}
		n*=16;
		}
		printf("%d",add);
	return 0;
}
