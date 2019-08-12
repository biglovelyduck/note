#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define PI 3.14159265358979323
int main(int argc, char *argv[]) {
	int r; 
	scanf("%d",&r); 
	printf("%.7f",PI*r*r);
	return 0;
}
