// ջ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "windows.h"

int main(int argc, char* argv[])
{
    int x;   //Ҫ������ջ��Ԫ��
	int choice=0;
    LinkStack s;
    int e;
	for(;;){
		switch(menu_Select()){
		   case 1:
			   initStack(&s);
			   printf("��ʼ��ջ���!\n");
			   break;
		   case 2:
			   printf("������ջԪ��:\n");
			   scanf("%d",&x);
			   push(&s,x);
			   break;
		   case 3:
			   pop(&s,e);
			   printf("��ջԪ��:%d\n",e);
			   break;
		   case 4:
			   getTop(&s,e);
			   //printf("ջ��Ԫ��:%d\n",e);
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
