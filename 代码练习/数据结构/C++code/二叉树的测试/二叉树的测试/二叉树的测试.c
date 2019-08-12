#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//前序遍历
void preOrder(BiTNode *root){
	if (root == NULL){
		return;
	}
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild); 
}
//中序遍历
void inOrder(BiTNode *root){

}
//后序遍历
void postOrder(BiTNode *root){

}
//叶子数计算

void coutLeaf(BiTNode *T,int *sum){
	if (T != NULL){
		if (T->lchild == NULL&&T->rchild == NULL){
			(*sum)++;
		}
		if (T->lchild){
			coutLeaf(T->lchild,sum);
		}
		if (T->rchild){
			coutLeaf(T->rchild,sum); 
		}
	}
}
//树的高度
int Depth(BiTNode *root){
	int deptleft = 0;//左子树高度
	int deptright = 0;//右子树高度
	int deptval = 0;
	if (root == NULL){
		deptval = 0;
		return deptval;
	}
	deptleft = Depth(root->lchild);
	deptright = Depth(root->rchild);
	deptval = 1 + (deptleft > deptright ? deptleft : deptright);
	return deptval;
}
//copy树
BiTNode* CopyTree(BiTNode *T){
	BiTNode *newNode = NULL;
	BiTNode *newLp = NULL;
	BiTNode *newRp = NULL;
	if (T == NULL){
		return NULL;
	}
	//copy左子树
	if (T->lchild != NULL){
		newLp = CopyTree(T->lchild); 
	}
	else{
		newLp = NULL;
	}
	//copy右子树
	if (T->rchild != NULL){
		newRp = CopyTree(T->rchild);
	}
	else{
		newRp = NULL;
	}
	//malloc根结点
	newNode = (BiTNode *)malloc(sizeof(BiTNode)); 
	if (newNode == NULL){
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	newNode->data = T->data;
	return newNode;
}
//非递归算法中序遍历

int main(){
	BiTNode *p1, *p2, *p3, *p4, *p5;
	
	p1 = (BiTNode *)malloc(sizeof(BiTNode));
	p2 = (BiTNode *)malloc(sizeof(BiTNode));
	p3 = (BiTNode *)malloc(sizeof(BiTNode));
	p4 = (BiTNode *)malloc(sizeof(BiTNode));
	p5 = (BiTNode *)malloc(sizeof(BiTNode));
	//初始化为空
	memset(p1, 0, sizeof(BiTNode));
	memset(p2, 0, sizeof(BiTNode));
	memset(p3, 0, sizeof(BiTNode));
	memset(p4, 0, sizeof(BiTNode));
	memset(p5, 0, sizeof(BiTNode));
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p3->lchild = p5;
	printf("中序遍历：\n");
	preOrder(p1);
	int sum = 0;
	printf("coutLeaf:");
	coutLeaf(p1, &sum);
	printf("\n");
	printf("sum:%d\n", sum);
	printf("Depth:%d\n", Depth(p1));
	BiTNode * copyNode = CopyTree(p1);
	printf("copy后的中序遍历:");
	preOrder(copyNode);
	return 0;
}