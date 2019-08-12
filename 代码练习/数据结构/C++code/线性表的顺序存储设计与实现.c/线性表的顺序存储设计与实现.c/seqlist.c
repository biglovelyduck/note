#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _tag_SeqList{
	int length;
	int capcity;
	unsigned int *node;
}TSeqList;

SeqList* SeqList_Create(int capacity){
	int ret = 0;
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)malloc(sizeof(TSeqList));
	if (tlist == NULL){
		ret = -1;
		printf("func SeqList_Create() err:%d \n",ret);
		return NULL;
	}
	memset(tlist, 0, sizeof(TSeqList));
	//根据capcity分配大小
	tlist->node = (unsigned int *)malloc(sizeof(unsigned int *)*capacity);
	if (tlist->node == NULL){
		ret = -2;
		printf("func SeqList_Create() err:malloc error:%d\n", ret);
		return NULL;
	}
	tlist->capcity = capacity;
	tlist->length = 0;
	return (SeqList *)tlist;
}

void SeqList_Destroy(SeqList* list){
	TSeqList *tlist = NULL;
	if (list == NULL){
		return;
	}
	tlist = (TSeqList *)list;
	if (tlist->node!= NULL){
		free(tlist->node);
	}
	free(tlist);
	return ;
}
//清空链表，回到初始化状态
void SeqList_Clear(SeqList* list){
	TSeqList *tlist = NULL;
	if (list == NULL){
		return;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list){
	TSeqList *tlist = NULL;
	if (list == NULL){
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list){
	TSeqList *tlist = NULL;
	if (list == NULL){
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->capcity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	int i,ret=0;
	TSeqList *tlist = NULL;
	if (list == NULL || node == NULL || pos < 0 ){
		ret = -1;
		printf("func SeqList_Insert() err:%d \n", ret);
		return ret;
	}
	tlist = (TSeqList *)list;
	//判断是不是满了
	if (tlist->length > tlist->capcity){
		ret = -2;
		printf("func SeqList_Insert() err:capcity is full:%d \n", ret);
		return ret;
	}
	//容错修正
	if (pos > tlist->length){
		pos = tlist->length;
	}
	for (i = tlist->length; i > pos; i--){
		tlist->node[i] = tlist->node[i - 1];
	}
	tlist->node[i] = (unsigned int *)node;
	tlist->length += 1;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
	int ret = 0;
	TSeqList *tlist = NULL;
	if (list == NULL  || pos < 0){
		ret = -1;
		printf("func SeqList_Get() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqList *)list;
	return (void *)tlist->node[pos];

}

SeqListNode* SeqList_Delete(SeqList* list, int pos){
	int i;
	SeqListNode *ret = 0;
	TSeqList *tlist = NULL;
	if (list == NULL || pos < 0){
		ret = -1;
		printf("func SeqList_Delete() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqList *)list;
	ret = (SeqListNode *)tlist->node[pos];//暂时保存要删除的结点
	for (i = pos + 1; i < tlist->length; i++){
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}