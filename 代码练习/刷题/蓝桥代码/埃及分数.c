#include <stdio.h>
#include <stdlib.h>

/*
B除以A的整数部分为C，余数为D 
B=A*C+D
B/A=C+D/C<C+1
A/B>1/C+1
设E=C+1
A/B-1/E=(A*E-B)/B*E 
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//8/11， 
int main(int argc, char *argv[]) {
	int a;
	int b;
	scanf("%d/%d",&a,&b);
	f(a,b); 
	return 0;
}
/*将分数分解为埃及分数序列*/
void f(int a,int b){//8,11
	int c;//用来存储分解的分母 
	while(1){
		if(b%a!=0){//分子除以分母还有余数 
		    c=b/a+1;//c=2,5
			printf("1/%d+",c);
			a=a*c-b;//a=5,3
			b=b*c;//b=22,110
			if(a==3){//分子等于余数 
				printf("1/%d+1/%d\n",b/2,b);
				break;
			}	
		}
		//1/2
		else {//分子除以分母没有余数
			c=b/a;//c=2
			a=1;
			printf("%d/%d",a,c);
			break;
		}
	}
}
