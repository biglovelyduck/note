// ���ռ�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"   //Ԥ�������л��� 
#include <stdio.h>    //Ԥ����������� 
#include <stdlib.h>   //��׼��ͷ�ļ������õĺ�����malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()�ȵȡ�
#include <conio.h>    //������������̨����������躯����ͷ�ļ������Ҫ�õ���getch() cprintf() cputs() kbhit()֮��ĺ������Ǿ���Ҫ���ͷ�ļ��� 
#define MSIZE 30      //������еĳ���

int main(int argc, char *argv[]) {
	int x;//Ҫ��ӵ�Ԫ��
	Queue Q;
	int choice=0;

	int e;//Ҫ���ӵ�Ԫ��
	for(;;){
		switch(menuSelect()){
		case 1: 
			initQueue(&Q);
			printf("��ʼ��������ϣ�\n");
			break;
		case 2: 
		    printf("�������Ԫ�أ�\n");		
		    scanf("%d",&x);
		    enQueue(&Q,x);
		    printf("�����ɣ�\n");
		    break;
		case 3: 
			deleteQueue(&Q,&e);
			printf("������ɣ�\n");
			break;
		case 4:
			queuePrint(Q);
			printf("��ӡ������ɣ�\n");
			break;
		case 5:
			exit(0);//0��ʾ�����˳�
		}
	}
	return 0;
}
