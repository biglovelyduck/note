#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[30];
	gets(a); 
	int oddNumber_sum=0;
	int evenNumber_sum=0;
	int i;
	for(i=strlen(a)-1;i>=0;i=i-2)
	    oddNumber_sum+=(a[i]-'0');
	//printf("%d",oddNumber_sum);
	for(i=strlen(a)-2;i>=0;i=i-2){
	    if((a[i]-'0')*2>=10) 
	        evenNumber_sum+=((a[i]-'0')*2-9);
	    else 
	        evenNumber_sum+=(a[i]-'0')*2;
	}
	if((oddNumber_sum+evenNumber_sum)%10==0)
	    puts("³É¹¦");
	else puts("Ê§°Ü"); 
	printf("%d",evenNumber_sum);
	return 0;
}
