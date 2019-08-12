// stdafx.cpp : source file that includes just the standard includes
//	ջ.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "windows.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
/*��ջ�ĳ�ʼ��*/
void initStack(LinkStack *s){
   //����һ����ջ
	s->top=NULL;
}

//�ж�ջ�Ƿ�Ϊ��,�ǿշ�����
bool stackEmpty(LinkStack &s){/*"&"�������ã������ջ���в��ң��󳤶ȵȲ��ñ�ջ�Ĳ�����"&",�������ɾ��������Ȳ����ı���ԭ����ջ�Ͳ���Ҫ��"&";
                              �൱��ȡ��һ������������C++�����ã���Ϊ���s�����˸ı䣬����ϣ������ı���Ȼ�ں������غ���ڣ��������ݹ����ǰ�ʵ�ε�����
	                          �����β�*/
return (s.top==NULL);
}

//ȡջ��Ԫ��
void getTop(LinkStack *s,StackDataType e){//��ջ��������e����ջ��Ԫ�ص�ֵ���᷵��OK�����򷵻�ERROR
	if(!s->top){
		printf("����ջ!");
	}
	else {
	e=s->top->data;
	printf("ջ��Ԫ��Ϊ��%d\n",e);
	}
}

//��ջ
void push(LinkStack *s,StackDataType e){
//����Ԫ��Ϊe���µ�ջ��Ԫ
    stackNode *q=(stackNode*)malloc(sizeof(stackNode));     /*malloc:����ɹ����򷵻�ָ�򱻷����ڴ�ռ��ָ��,ָ��һ�ο����ڴ����ʼ��ַ,��Ȼ�����ؿ�ָ��NULL�� 
	                                                      ���ڣ�void *,��ʾδȷ�����͵�ָ�롣C��C++�涨��void *���Ϳ���ǿתΪ�κ��������͵ĵ�ָ�롣*/
    q->data=e;  
	q->next=s->top;                                      //�����Ԫ�ػ��Ϊջ��Ԫ��
	s->top=q;                                            //��topָ���´����Ľڵ㣬�½ڵ��next����ָ��ԭ����ջ��Ԫ��
}

//��ջ
void pop(LinkStack *s,StackDataType e){
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	stackNode *q=s->top;
	if(s->top==NULL){
      printf("��ջ\n");
	}
	e=q->data;
	printf("ջ��Ԫ�أ�%d\n",e);
	s->top=q->next;//ָ����һ������Ľڵ�
	free(q);//��������ڵ�Ŀռ�
}

void stackPrint(LinkStack &s){
   stackNode *p;
   int e,i=1;
   p=s.top;
   if(p==NULL){
     printf("ջΪ��!\n");
   }
   while(p!=NULL){
     e=p->data;
	 p=p->next;
     printf("��%d��Ԫ�ص�ֵΪ:%d\n",i,e);
	 i++;
   }
}

int menu_Select(){
int a;
printf("\n*_*��������������������˵���*_*\n");
getch();                              //�ӿ���̨��ȡ������ַ�
system("cls");
printf("********************************MENU************************************\n");
printf("1............................������ջ\n");
printf("2............................��ջ\n");
printf("3............................��ջ\n");
printf("4............................ȡջ��Ԫ��\n");
printf("5............................���ջ\n");
printf("6............................�˳�\n");
printf("************************************************************************\n");

do{
printf("���������ѡ��(1~6):");
scanf("%d",&a);
}
while(a<1||a>7);

return a;
}
