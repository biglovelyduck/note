// stdafx.cpp : source file that includes just the standard includes
//	栈.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "windows.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
/*链栈的初始化*/
void initStack(LinkStack *s){
   //构造一个空栈
	s->top=NULL;
}

//判断栈是否为空,是空返回真
bool stackEmpty(LinkStack &s){/*"&"代表引用，如果对栈进行查找，求长度等不该变栈的操作用"&",如果进行删除，插入等操作改变了原来的栈就不需要加"&";
                              相当于取了一个别名，属于C++的引用，因为你对s进行了改变，而且希望这个改变仍然在函数返回后存在；参数传递过程是把实参的引用
	                          传给形参*/
return (s.top==NULL);
}

//取栈顶元素
void getTop(LinkStack *s,StackDataType e){//若栈不空则用e返回栈顶元素的值，会返回OK；否则返回ERROR
	if(!s->top){
		printf("空链栈!");
	}
	else {
	e=s->top->data;
	printf("栈顶元素为：%d\n",e);
	}
}

//入栈
void push(LinkStack *s,StackDataType e){
//插入元素为e的新的栈顶元
    stackNode *q=(stackNode*)malloc(sizeof(stackNode));     /*malloc:分配成功：则返回指向被分配内存空间的指针,指向一段可用内存的起始地址,不然，返回空指针NULL。 
	                                                      关于：void *,表示未确定类型的指针。C，C++规定，void *类型可以强转为任何其他类型的的指针。*/
    q->data=e;  
	q->next=s->top;                                      //插入的元素会成为栈顶元素
	s->top=q;                                            //让top指向新创建的节点，新节点的next引用指向原来的栈顶元素
}

//出栈
void pop(LinkStack *s,StackDataType e){
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	stackNode *q=s->top;
	if(s->top==NULL){
      printf("空栈\n");
	}
	e=q->data;
	printf("栈顶元素：%d\n",e);
	s->top=q->next;//指向下一个下面的节点
	free(q);//销毁这个节点的空间
}

void stackPrint(LinkStack &s){
   stackNode *p;
   int e,i=1;
   p=s.top;
   if(p==NULL){
     printf("栈为空!\n");
   }
   while(p!=NULL){
     e=p->data;
	 p=p->next;
     printf("第%d个元素的值为:%d\n",i,e);
	 i++;
   }
}

int menu_Select(){
int a;
printf("\n*_*按任意键清屏并返回主菜单！*_*\n");
getch();                              //从控制台获取输入的字符
system("cls");
printf("********************************MENU************************************\n");
printf("1............................建立空栈\n");
printf("2............................入栈\n");
printf("3............................出栈\n");
printf("4............................取栈顶元素\n");
printf("5............................输出栈\n");
printf("6............................退出\n");
printf("************************************************************************\n");

do{
printf("请输入你的选择：(1~6):");
scanf("%d",&a);
}
while(a<1||a>7);

return a;
}
