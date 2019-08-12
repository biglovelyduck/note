#include "stdaf.h"    //预编译运行环境 
#include <stdio.h>    //预编译输入输出 
#include <stdlib.h>   //标准库头文件，常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()等等。
#include <conio.h>    //用来声明控制台输入输出所需函数的头文件如果你要用到像getch() cprintf() cputs() kbhit()之类的函数，那就需要这个头文件了 
#define MSIZE 30      //定义队列的长度 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{      //自定义数据类型，目的一般有两个，一个是给变量一个易记且意义明确的新名字，另一个是简化一些比较复杂的类型声明。 
	int data[MSIZE];
	int front;
	int rear;
}Queue;  //队列 

void initQueue(Queue *Q){//构造一个空队列Q 
	Q->front=Q->rear=0;
} 

void EnQueue(Queue *Q,int e){//入队 ，e为要入队的元素 
	if(Q->rear+1%MSIZE==Q->front){//若rear为1，则rear+1取余数为2！ 
		printf("队列已满！");
	} 
	else{
		Q->data[Q->rear]=e;
		Q->rear=(Q->rear+1)%MSIZE;
	}
} 

void deleteQueue(Queue *Q,int *e)
{
	if(Q->front==Q->rear){
		pritf("队列为空！\n")
		return;
	}
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MSIZE;
	printf("出队元素：%d\n"，*e)
}

void QueuePrint(Queue *Q){
	int i,j,p,e;
	j=(Q.rear-Q.front+MSIZE)%MSIZE;  //j为队列的长度 
	p=Q.front;  //p为数组下标，起始为front 
	if(Q.rear==Q.front) printf("队列为空！\n");
	else if(Q.rear+1%MSIZE==Q.front){
		printf("队列已满！\n")
	}
	else if(Q.rear+1%MSIZE!=Q.front){
		printf("队列未满！\n")
	}
	for(i=1;i<=j;i++){
	    e=Q.data[p]; 
	    p=(p+1)%MSIZE;
	    printf("第%d个元素的值为：%d\n",i,e);
	} 
}

int menu_select(){//返回你的选择 
int a;
getch(); //从控制台读取一个字符,返回值：读取的字符 
system("cls");//完成清屏//system("time /t") ;//显示时间system("dir"); //列目录
printf("\n*_*按任意键清屏并返回主菜单！*_*\n");	
printf("*********************MUNE*************************\n");
printf("1.................建立空队列\n");
printf("2.................入队列\n");
printf("3.................出队列\n");
printf("4.................输出队列\n");
printf("1.................退出\n");
printf("**************************************************\n");
do{
	printf("请输入你的选择（1~5）\n");
	scanf("%d",&a);
}
while(a<1||a>5);//输入1~5的数会跳出该循环 
return a;
}//系统菜单 

int main(int argc, char *argv[]) {
	return 0;
}
