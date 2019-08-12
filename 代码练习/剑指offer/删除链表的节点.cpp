//删除链表的节点 
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
	int value;
	ListNode* next;
};
//时间复杂度O(1),思路依靠复制下一节点 
void DeleteNode(ListNode** pHead,ListNode* pDeleted){
	if(!pHead||!pDeleted) return;
	//要删除的节点不是尾节点 
	if(pDeleted->next!=nullptr){
		ListNode* next=pDeleted->next;
		pDeleted->value=next->value;
		pDeleted->next=next->next; 
		delete next;
		next=nullptr;
	}
	//链表只有一个节点，删除头节点
	else if(pDeleted==*pHead){
		delete pDeleted;
		pDeleted=nullptr;
		*pHead=nullptr;
	}
	//链表中有多个节点，删除尾节点 
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
