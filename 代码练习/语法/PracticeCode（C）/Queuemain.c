#include "stdaf.h"    //Ԥ�������л��� 
#include <stdio.h>    //Ԥ����������� 
#include <stdlib.h>   //��׼��ͷ�ļ������õĺ�����malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()�ȵȡ�
#include <conio.h>    //������������̨����������躯����ͷ�ļ������Ҫ�õ���getch() cprintf() cputs() kbhit()֮��ĺ������Ǿ���Ҫ���ͷ�ļ��� 
#define MSIZE 30      //������еĳ��� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{      //�Զ����������ͣ�Ŀ��һ����������һ���Ǹ�����һ���׼���������ȷ�������֣���һ���Ǽ�һЩ�Ƚϸ��ӵ����������� 
	int data[MSIZE];
	int front;
	int rear;
}Queue;  //���� 

void initQueue(Queue *Q){//����һ���ն���Q 
	Q->front=Q->rear=0;
} 

void EnQueue(Queue *Q,int e){//��� ��eΪҪ��ӵ�Ԫ�� 
	if(Q->rear+1%MSIZE==Q->front){//��rearΪ1����rear+1ȡ����Ϊ2�� 
		printf("����������");
	} 
	else{
		Q->data[Q->rear]=e;
		Q->rear=(Q->rear+1)%MSIZE;
	}
} 

void deleteQueue(Queue *Q,int *e)
{
	if(Q->front==Q->rear){
		pritf("����Ϊ�գ�\n")
		return;
	}
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MSIZE;
	printf("����Ԫ�أ�%d\n"��*e)
}

void QueuePrint(Queue *Q){
	int i,j,p,e;
	j=(Q.rear-Q.front+MSIZE)%MSIZE;  //jΪ���еĳ��� 
	p=Q.front;  //pΪ�����±꣬��ʼΪfront 
	if(Q.rear==Q.front) printf("����Ϊ�գ�\n");
	else if(Q.rear+1%MSIZE==Q.front){
		printf("����������\n")
	}
	else if(Q.rear+1%MSIZE!=Q.front){
		printf("����δ����\n")
	}
	for(i=1;i<=j;i++){
	    e=Q.data[p]; 
	    p=(p+1)%MSIZE;
	    printf("��%d��Ԫ�ص�ֵΪ��%d\n",i,e);
	} 
}

int menu_select(){//�������ѡ�� 
int a;
getch(); //�ӿ���̨��ȡһ���ַ�,����ֵ����ȡ���ַ� 
system("cls");//�������//system("time /t") ;//��ʾʱ��system("dir"); //��Ŀ¼
printf("\n*_*��������������������˵���*_*\n");	
printf("*********************MUNE*************************\n");
printf("1.................�����ն���\n");
printf("2.................�����\n");
printf("3.................������\n");
printf("4.................�������\n");
printf("1.................�˳�\n");
printf("**************************************************\n");
do{
	printf("���������ѡ��1~5��\n");
	scanf("%d",&a);
}
while(a<1||a>5);//����1~5������������ѭ�� 
return a;
}//ϵͳ�˵� 

int main(int argc, char *argv[]) {
	return 0;
}
