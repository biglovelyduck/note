#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void g(int a,int b);

int main(int argc, char *argv[]) {
	g(1,10); 
	return 0;
}
void g(int a,int b){
	//if(a<b)
	//g(a,b-1);
	if(a==b) ;
	else g(a,b-1);
	printf("%d\n",b);
}
