#include <stdio.h>
#define MAXN 7//设置每一注彩票的位数
#define NUM 29//设置组成彩票的数字
int num[NUM];
int lottery[MAXN];//lottery:彩票
void combine(int n,int m){//n=29,m=7
  int i,j;
  for(i=n;i>=m;i--){//i=29,i>=7
      lottery[m-1]=num[i-1];//lottery[6]=num[29]
	  if(m>1){
	     combine(i-1,m-1);//i-1=28,m-1=6
	  }
	  else{//若m=1,输出一注彩票号码
		  for(j=MAXN-1;j>=0;j--){
		      printf("%3d",lottery[j]);

		  }
		  getch();
		  printf("\n");
	  }

  }

}

void main(){
	int i,j;
	for(i=0;i<NUM;i++){
	    
		num[i]=i+1;
	}

	for(j=0;j<MAXN;j++){

		lottery[j]=0;
	
	}

	combine(NUM,MAXN);

	getch();

}