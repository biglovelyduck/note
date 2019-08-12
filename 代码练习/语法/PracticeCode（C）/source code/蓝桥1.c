#include<stdio.h>
int main()
{
int A,B,C,sum1,sum2,sum3;
for(A=0;A<500;++A){
	for(B=0;B<500;++B){
		for(C=0;C<500;++C){
		sum1=3*A+7*B+C;
		sum2=4*A+10*B+C;
		if(sum1==315&&sum2==420){
			sum3=A+B+C;
		printf("%d\n",sum3);
		}
		
		
		}
	}
} 
return 0;
}