#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,n1;
	scanf("%d",&n);
	unsigned int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
	} 
	scanf("%d",&n1);
	for(i=0;i<n;i++){
		if(a[i]==n1){
		printf("%d",i+1);
		break;
		}
		if(i==n-1){
			if(a[n-1]!=n1)
			printf("-1");
		}
	}
	return 0;
}
