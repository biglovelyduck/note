#include <stdio.h>
#define MAXN 7//����ÿһע��Ʊ��λ��
#define NUM 29//������ɲ�Ʊ������
int num[NUM];
int lottery[MAXN];//lottery:��Ʊ
void combine(int n,int m){//n=29,m=7
  int i,j;
  for(i=n;i>=m;i--){//i=29,i>=7
      lottery[m-1]=num[i-1];//lottery[6]=num[29]
	  if(m>1){
	     combine(i-1,m-1);//i-1=28,m-1=6
	  }
	  else{//��m=1,���һע��Ʊ����
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