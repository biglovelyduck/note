#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

//���
typedef struct Teacher{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

void main(){
	int len = 0, ret = 0,i;
	//��������
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
	ret = LinkList_Insert(list, (LinkListNode *)&t1, 0);//ͷ����
	ret = LinkList_Insert(list, (LinkListNode *)&t2, 0);//ͷ����
	ret = LinkList_Insert(list, (LinkListNode *)&t3, 0);//ͷ����
	ret = LinkList_Insert(list, (LinkListNode *)&t4, 0);//ͷ����
	ret = LinkList_Insert(list, (LinkListNode *)&t5, 0);//ͷ����

	//����
	for (i = 0; i < LinkList_Length(list); i++){
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp == NULL){
			return;
		}
		printf("tmp->age:%d\n", tmp->age);
	}

	//ɾ�����
	while (LinkList_Length(list) > 0){
		Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
		if (tmp == NULL){
			return;
		}
		printf("tmp->age:%d\n", tmp->age);
	}
	
	//ɾ������
	LinkList_Destroy(list);

	len = LinkList_Length(list);

	system("pause");
	return;
}