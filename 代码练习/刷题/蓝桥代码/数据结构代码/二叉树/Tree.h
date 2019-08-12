#include<stdio.h>
#include<stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;//����Ԫ������
typedef struct ChainTree{//����������������

	DATA data;//Ԫ������
	struct ChainTree *left;//���������ָ��
	struct ChainTree *right;//���������ָ��
}ChainBinTree;
ChainBinTree *BinTreeInit(ChainBinTree *node){//��ʼ�����������ڵ㣬����ָ��ͷ����ָ��

	if(node!=NULL) return node;//������㲻Ϊ��
	else return NULL;
}
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n){
//btΪָ�򸸽���ָ�룬nodeΪ�ӽ�㣬n=1��ʾ�����������n=2��ʾ���������
    if(bt==NULL){
	
		printf("����㲻���ڣ��������ø���㣡\n");
		return 0;
	}

	switch(n){
	
	case 1:{//�������
		if(bt->left){
		
			printf("��������㲻��Ϊ�գ�\n");
			return 0;
		}
		else {bt->left=node;
		    printf("������������ɹ���");
		}

	break;
	}
	case 2:{//����ҽ��
		if(bt->right){
		
			printf("��������㲻��Ϊ�գ�\n");
			return 0;
		}
		else {bt->right=node;
            printf("������������ɹ���");
	}
	break;
	}
		default:
		printf("��������\n");
		return 0;
	}
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt){//�������

	if(bt){
	
		return bt->left;
	}
	else return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt){//����ҽڵ�
	if(bt){
	
		return bt->right;
	}
	else return NULL;
}
int BinTreeIsEmpty(ChainBinTree *bt){//���������Ƿ�Ϊ�գ���Ϊ�շ���1

	if(bt) return 0;
	else return 1;
}
int BinTreeDepth(ChainBinTree *bt){//��ȡ�����������

	int dep1,dep2;
	if(bt==NULL){
	
		return 0;
	}
	else{
	
		dep1=BinTreeDepth(bt->left);//��������ȣ��ݹ���ã�
		dep2=BinTreeDepth(bt->right);//���������
		if(dep1>dep2) return dep1+1;
		else return dep2+1;
	}
}
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data){//�ڶ������в���ֵΪdata�Ľ��

	ChainBinTree *p;
	if(bt->data==NULL){
	
		return NULL;
	}
	else{
	
		if(bt->data==data) return bt;
		else{//�ֱ������������ݹ����

		    if(p=BinTreeFind(bt->left,data)) return p;
			else if(p=BinTreeFind(bt->right,data)) return p;
			else return NULL;
		}
	}
}
void BinTreeClear(ChainBinTree *bt){//��ն�����,ʹ���Ϊһ�ÿ���
      
    if(bt){
	
		BinTreeClear(bt->left);//���������,�ݹ�
		BinTreeClear(bt->right);//���������
		free(bt);//�ͷŵ�ǰ�����ռ�ڴ�
		bt=NULL;
	}
	return;//��ĳ���û�����ҽ��ʱ����ոý��
}
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//�������,����Ĳ�����ʾ�����Ĳ���,��ʾ��ӡ���ý�������
    
    if(bt){//����Ϊ�գ���ִ�����²���
	
		oper(bt);//�����������
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper);
	}
	return;
}
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//�������,�����
    
    if(bt){//����Ϊ�գ���ִ�����²���
	
		BinTree_LDR(bt->left,oper);//�������������
		oper(bt);//�����������
		BinTree_LDR(bt->right,oper);
	}
	return;
}
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//�������,���Ҹ�
    
    if(bt){//����Ϊ�գ���ִ�����²���
	
		BinTree_LRD(bt->left,oper);//�������������
		BinTree_LRD(bt->right,oper);//�������������
		oper(bt);//�����������
	}
	return;
}
void oper(ChainBinTree *p){

	printf("%c ",p->data);
	return;
}
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){//�������
   
    ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];//����һ��˳��ջ
	int head=0,tail=0;//���׶�β���
    if(bt){//������ָ�벻Ϊ��
	
		tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����ж�β���
		q[tail]=bt;//����������ָ�����
	}
	while(head!=tail){//���в�Ϊ�գ�����ѭ��
	
		head=(head+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ������
        p=q[head];//��ȡ����Ԫ��
		oper(p);//�������Ԫ��
        if(p->left!=NULL){//������������������������ָ�����
		
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->left;//��������ָ�����
		}
		if(p->right!=NULL){
		
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->right;//��������ָ�����
		}
	}
	return;
}
/*������������*/
void BinTree_ExchangeChild(ChainBinTree *bt){

    ChainBinTree *temp;
	if(bt->left!=NULL&&bt->right!=NULL){

		temp=bt->left;
		bt->left=bt->right;
		bt->right=temp;
	}
	return;
}
void BinTree_DLR1(ChainBinTree *bt,void (*BinTree_ExchangeChild)(ChainBinTree *p)){//�������,����Ĳ�����ʾ�����Ĳ���,��ʾ��ӡ���ý�������
    
    if(bt){//����Ϊ�գ���ִ�����²���
	
		BinTree_ExchangeChild(bt);//�����������
		BinTree_DLR(bt->left,BinTree_ExchangeChild);
		BinTree_DLR(bt->right,BinTree_ExchangeChild);
	}
	return;
}
