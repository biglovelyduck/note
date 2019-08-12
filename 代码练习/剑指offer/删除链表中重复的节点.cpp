//删除链表中重复的节点 
/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(pHead==nullptr) return nullptr;
		ListNode *pPre=nullptr;
		ListNode *pNode=pHead;
		while(pNode!=nullptr){
			ListNode *pNext=pNode->next;
			bool needDelete=false;
			if(pNext!=nullptr&&pNext->val==pNode->val)
				needDelete=true;
			if(!needDelete){
				pPre=pNode;
				pNode=pNode->next;
			}
			else{
				int value=pNode->val;
				ListNode* pDel=pNode;
				//把后面重复的都给删除了 
				while(pDel!=nullptr&&pDel->val==value){
					pNext=pDel->next;
					delete pDel;
					pDel=nullptr;
					pDel=pNext;
				}
				if(pPre==nullptr){
					pHead=pNext;
				}
				else{
					pPre->next=pNext;
				}
				pNode=pNext;
			}
		}
		return pHead;
    }
};
