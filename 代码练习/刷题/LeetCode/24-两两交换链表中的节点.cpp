//24-�������������еĽڵ� 
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

//���ˣ�ûд���� 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;	//����Ҫ�����ڵ�ſ��Խ��� 
        ListNode *rel=head->next;
        ListNode *p=*head;
        ListNode *pre=head;
        while(p&&p->next){
        	ListNode* next=p->next->next;				//p����һ����λ�� 
        	p->next->next=p;						
        	p->next=next;   
        	pre=p;
			p=next;    	
		}
		return rel;
    }
};

//�ݹ�
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

//�ǵݹ�ⷨ
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
