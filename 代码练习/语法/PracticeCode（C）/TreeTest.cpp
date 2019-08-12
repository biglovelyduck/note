#include <stdio.h>
#include<conio.h>
#include "Tree.h"
/*void oper(ChainBinTree *p){//�����������������

	printf("%c ",p->data);//�������
	return ;
}*/
ChainBinTree *initRoot(){//��ʼ���������ĸ�,����ָ��ͷ����ָ��,����node

	ChainBinTree *node;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){//�����ڴ�,������ڴ�һ��ָ������ָ�룬�������node
	
		printf("\n�������������ݣ�");
        scanf("%s",&node->data);
		node->left=NULL;
		node->right=NULL;
		return BinTreeInit(node);
	}
	return NULL;
}
void addNode(ChainBinTree *bt){//btΪָ�������ָ��

	ChainBinTree *node,*parent;
	DATA data;//���常��������Ϊdata
	char select;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){
	
		printf("\n����������������:");
        fflush(stdin);//������뻺����
		scanf("%s",&node->data);
		node->left=NULL;//������������Ϊ��
		node->right=NULL;

		printf("\n���븸�������:");
		fflush(stdin);//������뻺����
		scanf("%s",&data);
		parent=BinTreeFind(bt,data);//����ָ�����ݵĽ��
		if(!parent){//��δ�ҵ�ָ�����ݵĽ��

			printf("δ�ҵ�����㣡\n");
			free(node);//�ͷŴ����Ľ���ڴ�
			return;
		}
		
		printf("1.��ӵ���������2.��ӵ���������\n");
		do{
		
			select=getch();
			select-='0';
			if(select==1||select==2)
				BinTreeAddNode(parent,node,select);//��ӽ�㵽������
		}while(select=='1'||select=='2');
	}
	return;
}
int main(){

	ChainBinTree *root=NULL;
	char select;
	void (*oper1)(ChainBinTree *p);//ָ������ָ��
	oper1=oper;//ָ���������ĺ���,�����ݽ����в�����
	do{
	
		printf("\n1.���ö�������Ԫ��:");
		printf("\n2.��Ӷ��������:");
		printf("\n3.�������:");
		printf("\n4.�������:");
		printf("\n5.�������:");
		printf("\n6.�������:");
		printf("\n7.���������:");
		printf("\n0.�˳�:\n");

		select=getch();
		switch(select){
		
		    case '1':
				root=initRoot();//���ø�Ԫ��,rootΪָ�������ָ��
			break;
			case '2':
				addNode(root);//��ӽ��
			break;
			case '3':
				printf("��������Ľ��:");
				BinTree_DLR(root,oper1);
                printf("\n");
			break;
			case '4':
				printf("��������Ľ��:");
                BinTree_LDR(root,oper1);
				printf("\n");
			break;
			case '5':
				printf("��������Ľ��:");
                BinTree_LRD(root,oper1);
				printf("\n");
			break;
			case '6':
				printf("��������Ľ��:");
				BinTree_Level(root,oper1);
				printf("\n");
			break;
			case '7':
				printf("�����������Ϊ:%d",BinTreeDepth(root));
				printf("\n");
			break;
			case '0':
			break;
		}
	}while(select!='0');
	BinTreeClear(root);//��ն�����
	root=NULL;
	getch();
	return 0;
}