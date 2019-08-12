// 栈.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "windows.h"

int main(int argc, char* argv[])
{
    int x;   //要输入入栈的元素
	int choice=0;
    LinkStack s;
    int e;
	for(;;){
		switch(menu_Select()){
		   case 1:
			   initStack(&s);
			   printf("初始化栈完毕!\n");
			   break;
		   case 2:
			   printf("输入入栈元素:\n");
			   scanf("%d",&x);
			   push(&s,x);
			   break;
		   case 3:
			   pop(&s,e);
			   printf("出栈元素:%d\n",e);
			   break;
		   case 4:
			   getTop(&s,e);
			   //printf("栈顶元素:%d\n",e);
			   break;
		   case 5:
			   stackPrint(s);
			   break;
		   case 6:
			   exit(0);
		}
	}

	return 0;
}
