#include<stdio.h>
#include<stdlib.h>
#define QUE_MAXSIZE 50
typedef char DATA;
typedef num{

	SubTree;
	Thread;
}NodeFlag;//枚举值SubTree(子树)和Thread(线索)的值分别为0,1
typedef struct ThreadTree{

	DATA data;//元素数值
	NodeFlag lflag;//左标志
	NodeFlag rflag;
	struct ThreadTree left;//左子树结点指针
	struct ThreadTree right;
}ThreadBinTree;