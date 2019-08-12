#include<stdio.h>
#include<stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;//定义元素类型
typedef struct ChainTree{//定义二叉树结点类型

	DATA data;//元素数据
	struct ChainTree *left;//左子树结点指针
	struct ChainTree *right;//右子树结点指针
}ChainBinTree;
ChainBinTree *BinTreeInit(ChainBinTree *node){//初始化二叉树根节点，返回指向头结点的指针

	if(node!=NULL) return node;//若根结点不为空
	else return NULL;
}
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n){
//bt为指向父结点的指针，node为子结点，n=1表示添加左子树，n=2表示添加右子树
    if(bt==NULL){
	
		printf("父结点不存在，请先设置父结点！\n");
		return 0;
	}

	switch(n){
	
	case 1:{//添加左结点
		if(bt->left){
		
			printf("左子树结点不能为空！\n");
			return 0;
		}
		else {bt->left=node;
		    printf("添加左子树结点成功！");
		}

	break;
	}
	case 2:{//添加右结点
		if(bt->right){
		
			printf("右子树结点不能为空！\n");
			return 0;
		}
		else {bt->right=node;
            printf("添加右子树结点成功！");
	}
	break;
	}
		default:
		printf("参数错误！\n");
		return 0;
	}
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt){//获得左结点

	if(bt){
	
		return bt->left;
	}
	else return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt){//获得右节点
	if(bt){
	
		return bt->right;
	}
	else return NULL;
}
int BinTreeIsEmpty(ChainBinTree *bt){//检查二叉树是否为空，若为空返回1

	if(bt) return 0;
	else return 1;
}
int BinTreeDepth(ChainBinTree *bt){//获取二叉树的深度

	int dep1,dep2;
	if(bt==NULL){
	
		return 0;
	}
	else{
	
		dep1=BinTreeDepth(bt->left);//左子树深度（递归调用）
		dep2=BinTreeDepth(bt->right);//右子树深度
		if(dep1>dep2) return dep1+1;
		else return dep2+1;
	}
}
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data){//在二叉树中查找值为data的结点

	ChainBinTree *p;
	if(bt->data==NULL){
	
		return NULL;
	}
	else{
	
		if(bt->data==data) return bt;
		else{//分别向左右子树递归查找

		    if(p=BinTreeFind(bt->left,data)) return p;
			else if(p=BinTreeFind(bt->right,data)) return p;
			else return NULL;
		}
	}
}
void BinTreeClear(ChainBinTree *bt){//清空二叉树,使其变为一棵空树
      
    if(bt){
	
		BinTreeClear(bt->left);//清空左子树,递归
		BinTreeClear(bt->right);//清空右子树
		free(bt);//释放当前结点所占内存
		bt=NULL;
	}
	return;//当某结点没有左右结点时就清空该结点
}
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//先序遍历,右面的参数表示对树的操作,表示打印出该结点的数据
    
    if(bt){//树不为空，则执行以下操作
	
		oper(bt);//处理结点的数据
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper);
	}
	return;
}
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//中序遍历,左根右
    
    if(bt){//树不为空，则执行以下操作
	
		BinTree_LDR(bt->left,oper);//中序遍历左子树
		oper(bt);//处理结点的数据
		BinTree_LDR(bt->right,oper);
	}
	return;
}
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//后序遍历,左右根
    
    if(bt){//树不为空，则执行以下操作
	
		BinTree_LRD(bt->left,oper);//后序遍历左子树
		BinTree_LRD(bt->right,oper);//后序遍历右子树
		oper(bt);//处理结点的数据
	}
	return;
}
void oper(ChainBinTree *p){

	printf("%c ",p->data);
	return;
}
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//按层遍历
   
    ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];//定义一个顺序栈
	int head=0,tail=0;//队首队尾序号
    if(bt){//若队首指针不为空
	
		tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列队尾序号
		q[tail]=bt;//将二叉树根指针入队
	}
	while(head!=tail){//队列不为空，进行循环
	
		head=(head+1)%QUEUE_MAXSIZE;//计算循环队列的队首序号
        p=q[head];//获取队首元素
		oper(p);//处理队首元素
        if(p->left!=NULL){//若结点存在左子树，则左子树指针进队
		
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->left;//将左子树指针进队
		}
		if(p->right!=NULL){
		
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->right;//将右子树指针进队
		}
	}
	return;
}
/*交换左右子树*/
void BinTree_ExchangeChild(ChainBinTree *bt){

    ChainBinTree *temp;
	if(bt->left!=NULL&&bt->right!=NULL){

		temp=bt->left;
		bt->left=bt->right;
		bt->right=temp;
	}
	return;
}
void BinTree_DLR1(ChainBinTree *bt,void (*BinTree_ExchangeChild)(ChainBinTree *p)){//先序遍历,右面的参数表示对树的操作,表示打印出该结点的数据
    
    if(bt){//树不为空，则执行以下操作
	
		BinTree_ExchangeChild(bt);//处理结点的数据
		BinTree_DLR(bt->left,BinTree_ExchangeChild);
		BinTree_DLR(bt->right,BinTree_ExchangeChild);
	}
	return;
}
