#include <stdio.h>
#include <stdlib.h>
void dectobin(int n); 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) { 
  
        int x=0;  
        scanf("%d",&x);//只能正数  
    dectobin(x);  
    printf("\n");  
        return 0;  
}  
  
void dectobin(int n)  
{  
    if(n/2>0)/*有商不等于0*/  
    {  
        dectobin(n/2);  
        printf("%d",n%2);  
    }  
    else  
    {  
        printf("%d",n);  
    }  
}
