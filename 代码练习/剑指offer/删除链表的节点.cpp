//ɾ������Ľڵ� 
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
	int value;
	ListNode* next;
};
//ʱ�临�Ӷ�O(1),˼·����������һ�ڵ� 
void DeleteNode(ListNode** pHead,ListNode* pDeleted){
	if(!pHead||!pDeleted) return;
	//Ҫɾ���Ľڵ㲻��β�ڵ� 
	if(pDeleted->next!=nullptr){
		ListNode* next=pDeleted->next;
		pDeleted->value=next->value;
		pDeleted->next=next->next; 
		delete next;
		next=nullptr;
	}
	//����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ�
	else if(pDeleted==*pHead){
		delete pDeleted;
		pDeleted=nullptr;
		*pHead=nullptr;
	}
	//�������ж���ڵ㣬ɾ��β�ڵ� 
	else{
		ListNode *node=*pHead;
		while(node->next!=pDeleted){
			node=node->next;
		}
		node->next=nullptr;
		delete pDeleted;
		pDeleted=nullptr;
	}
}
int main(){
	return 0;
}
