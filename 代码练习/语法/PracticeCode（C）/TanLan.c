#include <stdio.h>
#include <stdlib.h>
#define MAXN 9
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int parvalue[MAXN]={10000,5000,1000,500,200,100,50,20,10};//最低为一毛钱 
int num[MAXN]={0};
int exchange(int n){
	int i;
	for(i=0;i<MAXN;i++){
		if(n>parvalue[i]) break;} //找到比n小的最大面额 ，for循环结束  
	while(n>0&&i<MAXN){//i在前面已经定义，取上面跳出循环后的值 
		if(n>=parvalue[i]){
		    n-=parvalue[i];
		    num[i]++;
		}
		else if(n<10&&n>=5){//少于1毛钱并且大于5分钱 
			num[MAXN-1]++;//一毛钱的数量加一  
			break;
		}
		else{
			i++;//当大面值不行时，使用下一位的小面值 
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	 int i;
	 float m;
	 printf("请输入需要找零的钱：");
	 scanf("%f",&m);
	 exchange((int)m*100);
	 printf("\n%.2f零钱的组成为：\n",m);
	  for(i=0;i<MAXN;i++){
	  	if(num[i]>0) 
	  	printf("%6.2f:%d张\n",(float)parvalue[i]/100.0,num[i]);
	  }
	return 0;
}
