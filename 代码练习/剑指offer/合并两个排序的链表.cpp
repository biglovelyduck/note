//合并两个排序的链表
#include <bits/stdc++.h>
using namespace std;
//合并使得依然有序 
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr&&pHead2==nullptr) return nullptr;
		else if(pHead1==nullptr) return pHead2;
		else if(pHead2==nullptr) return pHead1;
		ListNode* mergedNode=nullptr;
		if(pHead1->val<pHead2->val){
			mergedNode=pHead1;
			mergedNode->next=Merge(pHead1->next,pHead2);
		}
		else{
			mergedNode=pHead2;
			mergedNode->next=Merge(pHead1,pHead2->next);
		}
		return mergedNode;
    }
}; 
