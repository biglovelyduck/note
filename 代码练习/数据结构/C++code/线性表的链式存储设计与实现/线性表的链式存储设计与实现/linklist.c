#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

typedef struct _tag_LinkList{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create(){
	TLinkList *ret = NULL;
	ret = malloc(sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;
	return ret;
}
void LinkList_Destroy(LinkList* list){
	if (list != NULL){
		free(list);
		list = NULL;
	}
	return ;
}

//让链表恢复到初始值
void LinkList_Clear(LinkList* list){
	if (list == NULL){
		return;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	tList->length = 0;
	tList->header.next = NULL;
	return ;
}



int LinkList_Length(LinkList* list){
	if (list == NULL){
		return -1;
	}
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	return tList->length;
}


int LinkList_Insert(LinkList* list, LinkListNode* node, int pos){
	int ret = 0,i;
	LinkListNode *current = NULL;
	TLinkList *tList = NULL;
	if (list == NULL ||node==NULL|| pos < 0){
		ret = -1;
		printf("Insert Error:%d\n", ret);
	}
	tList = (TLinkList *)list;
	current = &(tList->header);
	//移动current
	for (i = 0; i < pos&&(current->next!=NULL); i++){
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tList->length++;
	return 0;
}


LinkListNode* LinkList_Get(LinkList* list, int pos){
	int ret = 0, i;
	LinkListNode *current = NULL;
	TLinkList *tList = NULL;
	if (list == NULL || pos < 0){
		ret = -1;
		printf("Get Error:%d\n", ret);
	}
	tList = (TLinkList *)list;
	current = &(tList->header);
	//移动current
	for (i = 0; i < pos && (current->next != NULL); i++){
		current = current->next;
	}
	return current->next;
}


LinkListNode* LinkList_Delete(LinkList* list, int pos){
	int  i;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;
	TLinkList *tList = NULL;
	if (list == NULL  || pos < 0){
	
		printf("Insert Error:%d\n", ret);
	}
	tList = (TLinkList *)list;
	current = &(tList->header);
	//移动current
	for (i = 0; i < pos && (current->next != NULL); i++){
		current = current->next;
	}
	ret = current->next;
	current->next = ret-> next;
	tList->length--;
	return ret;
}


