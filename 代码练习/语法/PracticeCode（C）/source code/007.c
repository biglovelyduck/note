# include <stdio.h> 
int main (void) 
{ 
 int n,i,j,k; 
 int a[3][4]; 
 for (i=0;i<3;i++) 
 for (j=0;j<4;j++) 
 scanf("%d",&a[i][j]); 
 for (i=0;i<3;i++) 
 { 
 for (j=0;j<4;j++) 
 printf("%4d",a[i][j]); 
 printf("\n***********\n"); 
 } 
 for(i=0;i<3;i++) 
{ 
  k=0; 
  for(j=1;j<4;j++) 
  if(a[i][j]>a[i][k]) 
  k=j; 
 n=a[i][0];a[i][0]=a[i][k];a[i][k]=n;     
 } 
 for (i=0;i<3;i++) 
 { 
 for (j=0;j<4;j++) 
 printf("%4d",a[i][j]); 
 printf("\n"); 
 } 
 return 0; 
} 
