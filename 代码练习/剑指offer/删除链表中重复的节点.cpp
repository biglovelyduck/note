//ɾ���������ظ��Ľڵ� 
/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻������
��������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5*/
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
				//�Ѻ����ظ��Ķ���ɾ���� 
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
