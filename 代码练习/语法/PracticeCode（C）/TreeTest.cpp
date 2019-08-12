#include <stdio.h>
#include<conio.h>
#include "Tree.h"
/*void oper(ChainBinTree *p){//操作二叉树结点数据

	printf("%c ",p->data);//输出数据
	return ;
}*/
ChainBinTree *initRoot(){//初始化二叉树的根,返回指向头结点的指针,返回node

	ChainBinTree *node;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){//分配内存,给这块内存一个指向他的指针，另其等于node
	
		printf("\n请输入根结点数据：");
        scanf("%s",&node->data);
		node->left=NULL;
		node->right=NULL;
		return BinTreeInit(node);
	}
	return NULL;
}
void addNode(ChainBinTree *bt){//bt为指向根结点的指针

	ChainBinTree *node,*parent;
	DATA data;//定义父结点的数据为data
	char select;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){
	
		printf("\n输入二叉树结点数据:");
        fflush(stdin);//清空输入缓冲区
		scanf("%s",&node->data);
		node->left=NULL;//设置左右子树为空
		node->right=NULL;

		printf("\n输入父结点数据:");
		fflush(stdin);//清空输入缓冲区
		scanf("%s",&data);
		parent=BinTreeFind(bt,data);//查找指定数据的结点
		if(!parent){//若未找到指定数据的结点

			printf("未找到父结点！\n");
			free(node);//释放创建的结点内存
			return;
		}
		
		printf("1.添加到左子树。2.添加到左子树。\n");
		do{
		
			select=getch();
			select-='0';
			if(select==1||select==2)
				BinTreeAddNode(parent,node,select);//添加结点到二叉树
		}while(select=='1'||select=='2');
	}
	return;
}
int main(){

	ChainBinTree *root=NULL;
	char select;
	void (*oper1)(ChainBinTree *p);//指向函数的指针
	oper1=oper;//指向具体操作的函数,对数据结点进行操作的
	do{
	
		printf("\n1.设置二叉树根元素:");
		printf("\n2.添加二叉树结点:");
		printf("\n3.先序遍历:");
		printf("\n4.中序遍历:");
		printf("\n5.后序遍历:");
		printf("\n6.按层遍历:");
		printf("\n7.二叉树深度:");
		printf("\n0.退出:\n");

		select=getch();
		switch(select){
		
		    case '1':
				root=initRoot();//设置根元素,root为指向根结点的指针
			break;
			case '2':
				addNode(root);//添加结点
			break;
			case '3':
				printf("先序遍历的结果:");
				BinTree_DLR(root,oper1);
                printf("\n");
			break;
			case '4':
				printf("中序遍历的结果:");
                BinTree_LDR(root,oper1);
				printf("\n");
			break;
			case '5':
				printf("后序遍历的结果:");
                BinTree_LRD(root,oper1);
				printf("\n");
			break;
			case '6':
				printf("按层遍历的结果:");
				BinTree_Level(root,oper1);
				printf("\n");
			break;
			case '7':
				printf("二叉树的深度为:%d",BinTreeDepth(root));
				printf("\n");
			break;
			case '0':
			break;
		}
	}while(select!='0');
	BinTreeClear(root);//清空二叉树
	root=NULL;
	getch();
	return 0;
}