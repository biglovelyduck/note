#include<stdio.h>
#include<stdlib.h>
#define QUE_MAXSIZE 50
typedef char DATA;
typedef num{

	SubTree;
	Thread;
}NodeFlag;//ö��ֵSubTree(����)��Thread(����)��ֵ�ֱ�Ϊ0,1
typedef struct ThreadTree{

	DATA data;//Ԫ����ֵ
	NodeFlag lflag;//���־
	NodeFlag rflag;
	struct ThreadTree left;//���������ָ��
	struct ThreadTree right;
}ThreadBinTree;