#include <stdio.h>
#include <stdlib.h>
#define MAXN 9
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int parvalue[MAXN]={10000,5000,1000,500,200,100,50,20,10};//���ΪһëǮ 
int num[MAXN]={0};
int exchange(int n){
	int i;
	for(i=0;i<MAXN;i++){
		if(n>parvalue[i]) break;} //�ҵ���nС�������� ��forѭ������  
	while(n>0&&i<MAXN){//i��ǰ���Ѿ����壬ȡ��������ѭ�����ֵ 
		if(n>=parvalue[i]){
		    n-=parvalue[i];
		    num[i]++;
		}
		else if(n<10&&n>=5){//����1ëǮ���Ҵ���5��Ǯ 
			num[MAXN-1]++;//һëǮ��������һ  
			break;
		}
		else{
			i++;//������ֵ����ʱ��ʹ����һλ��С��ֵ 
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	 int i;
	 float m;
	 printf("��������Ҫ�����Ǯ��");
	 scanf("%f",&m);
	 exchange((int)m*100);
	 printf("\n%.2f��Ǯ�����Ϊ��\n",m);
	  for(i=0;i<MAXN;i++){
	  	if(num[i]>0) 
	  	printf("%6.2f:%d��\n",(float)parvalue[i]/100.0,num[i]);
	  }
	return 0;
}
