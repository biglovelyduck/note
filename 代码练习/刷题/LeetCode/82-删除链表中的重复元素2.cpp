//82-删除链表中的重复元素2
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <regex>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//没写出来 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(!head->next) return head;
        ListNode* pre=NULL,*new_head=head;
        for(ListNode* i=head;i->next!=NULL;i=i->next){
        	if(i->val!=i->next->val){
        		 pre=i;
        		 pre->next=NULL;
			}
        	while(i->next&&->val==i->next->val){
        		i=i->next;	
			} 
			if(pre==NULL&&i->next==NULL) return pre;
			if(pre==NULL){
				new_head=i->next;
			}      		
			else{
				pre->next=i->next;
			}
		}
		return new_head;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* preHead = new ListNode(0);
    preHead->next = head;

    ListNode* cur = preHead;
    int delVal;
    while(cur->next != NULL){
        if (cur->next->next != NULL && cur->next->val == cur->next->next->val) {
            delVal = cur->next->val;
            while(cur->next != NULL && cur->next->val == delVal){
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
        } else {
            cur = cur->next;
        }
    }
    ListNode* newHead = preHead->next;
    delete preHead;
    return newHead;
}


