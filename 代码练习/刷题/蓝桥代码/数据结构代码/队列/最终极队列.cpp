// 最终极队列.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"   //预编译运行环境 
#include <stdio.h>    //预编译输入输出 
#include <stdlib.h>   //标准库头文件，常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()等等。
#include <conio.h>    //用来声明控制台输入输出所需函数的头文件如果你要用到像getch() cprintf() cputs() kbhit()之类的函数，那就需要这个头文件了 
#define MSIZE 30      //定义队列的长度

int main(int argc, char *argv[]) {
	int x;//要入队的元素
	Queue Q;
	int choice=0;

	int e;//要出队的元素
	for(;;){
		switch(menuSelect()){
		case 1: 
			initQueue(&Q);
			printf("初始化队列完毕！\n");
			break;
		case 2: 
		    printf("输入入队元素：\n");		
		    scanf("%d",&x);
		    enQueue(&Q,x);
		    printf("入队完成！\n");
		    break;
		case 3: 
			deleteQueue(&Q,&e);
			printf("出队完成！\n");
			break;
		case 4:
			queuePrint(Q);
			printf("打印队列完成！\n");
			break;
		case 5:
			exit(0);//0表示正常退出
		}
	}
	return 0;
}
