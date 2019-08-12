#include<stdio.h>
int main()
{
int men,women,child;
for(men=0;men<=45;men++)
for(women=0;women<=45;women++)
for(child=0;child<=45;child++)
if((men*3+women*2+child*0.5==45)&&(men+women+child==45))
printf("men=%d women=%d child=%d",men,women,child);
return 0;
}