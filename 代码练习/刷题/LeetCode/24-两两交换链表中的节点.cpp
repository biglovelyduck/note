//24-两两交换链表中的节点 
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
using namespace std; 

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//晕了，没写出来 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;	//至少要有俩节点才可以交换 
        ListNode *rel=head->next;
        ListNode *p=*head;
        ListNode *pre=head;
        while(p&&p->next){
        	ListNode* next=p->next->next;				//p的下一跳的位置 
        	p->next->next=p;						
        	p->next=next;   
        	pre=p;
			p=next;    	
		}
		return rel;
    }
};

//递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
		ListNode *next=head->next;
		head->next=swapPairs(next->next);
		next->next=head;
		return next;
    }
};

//非递归解法
class Solution{
	ListNode *swapPairs(ListNode *head){
		ListNode *pre=new ListNode(0);
		pre->next=head;
		ListNode *temp=pre;
		while(temp->next!=NULL&&temp->next->next!=NULL){
			ListNode *start=temp->next;
			ListNode *end=temp->next->next;
			temp->next=end;
			start->next=end->next;
			end->next=start;
			temp=start;
		}
		return pre->next;
	}
}; 
