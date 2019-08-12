#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//ǰ�����
void preOrder(BiTNode *root){
	if (root == NULL){
		return;
	}
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild); 
}
//�������
void inOrder(BiTNode *root){

}
//�������
void postOrder(BiTNode *root){

}
//Ҷ��������

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
//���ĸ߶�
int Depth(BiTNode *root){
	int deptleft = 0;//�������߶�
	int deptright = 0;//�������߶�
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
//copy��
BiTNode* CopyTree(BiTNode *T){
	BiTNode *newNode = NULL;
	BiTNode *newLp = NULL;
	BiTNode *newRp = NULL;
	if (T == NULL){
		return NULL;
	}
	//copy������
	if (T->lchild != NULL){
		newLp = CopyTree(T->lchild); 
	}
	else{
		newLp = NULL;
	}
	//copy������
	if (T->rchild != NULL){
		newRp = CopyTree(T->rchild);
	}
	else{
		newRp = NULL;
	}
	//malloc�����
	newNode = (BiTNode *)malloc(sizeof(BiTNode)); 
	if (newNode == NULL){
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	newNode->data = T->data;
	return newNode;
}
//�ǵݹ��㷨�������

int main(){
	BiTNode *p1, *p2, *p3, *p4, *p5;
	
	p1 = (BiTNode *)malloc(sizeof(BiTNode));
	p2 = (BiTNode *)malloc(sizeof(BiTNode));
	p3 = (BiTNode *)malloc(sizeof(BiTNode));
	p4 = (BiTNode *)malloc(sizeof(BiTNode));
	p5 = (BiTNode *)malloc(sizeof(BiTNode));
	//��ʼ��Ϊ��
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
	printf("���������\n");
	preOrder(p1);
	int sum = 0;
	printf("coutLeaf:");
	coutLeaf(p1, &sum);
	printf("\n");
	printf("sum:%d\n", sum);
	printf("Depth:%d\n", Depth(p1));
	BiTNode * copyNode = CopyTree(p1);
	printf("copy����������:");
	preOrder(copyNode);
	return 0;
}