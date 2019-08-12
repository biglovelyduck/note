#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

//结点
typedef struct Teacher{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

void main(){
	int len = 0, ret = 0,i;
	//创建链表
	LinkList* list = NULL;
	list = LinkList_Create();
	if (list == NULL){
		return;
	}

	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;
	ret = LinkList_Insert(list, (LinkListNode *)&t1, 0);//头插入
	ret = LinkList_Insert(list, (LinkListNode *)&t2, 0);//头插入
	ret = LinkList_Insert(list, (LinkListNode *)&t3, 0);//头插入
	ret = LinkList_Insert(list, (LinkListNode *)&t4, 0);//头插入
	ret = LinkList_Insert(list, (LinkListNode *)&t5, 0);//头插入

	//遍历
	for (i = 0; i < LinkList_Length(list); i++){
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp == NULL){
			return;
		}
		printf("tmp->age:%d\n", tmp->age);
	}

	//删除结点
	while (LinkList_Length(list) > 0){
		Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
		if (tmp == NULL){
			return;
		}
		printf("tmp->age:%d\n", tmp->age);
	}
	
	//删除链表
	LinkList_Destroy(list);

	len = LinkList_Length(list);

	system("pause");
	return;
}