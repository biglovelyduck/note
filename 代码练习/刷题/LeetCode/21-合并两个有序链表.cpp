//21-�ϲ������������� 
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//�ҵ�ʺ���� 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		ListNode* p1=l1,*p2=l2;
		ListNode *res1=new ListNode(0);
		ListNode* res=res1; 
		while(p1&&p2){
			if(p1->val<p2->val){
				res->next=p1;
				p1=p1->next;
				res=res->next;
			}
			else{
				res->next=p2;
				p2=p2->next;
				res=res->next;
			}
		} 
		if(p1==NULL){
			while(p2){
				res->next=p2;
				p2=p2->next; 
				res=res->next;
			}
		}
		if(p2==NULL){
			while(p1){
				res->next=p1;
				p1=p1->next;
				res=res->next;
			}
		}
		ListNode* result=res1->next;
		delete res1;
		return result;
	}
};

//�ݹ�
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {	//����ͷ��� 
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val) {
			l1->next=mergeTwoLists(l1->next,l2);
			return l1; 
		} 
		else{
			l2->next=mergeTwoLists(l1,l2->next);
			return l2;
		}
	}
};

//���� 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {	//����ͷ��� 
        ListNode* preHead=new ListNode(-1);
		ListNode *pre=preHead;
		while(l1!=NULL&&l2!=NULL){
			if(l1->val<l2->val){
				pre->next=l1;
				l1=l1->next;
			}else{
				pre->next=l2;
				l2=l2->next;
			}
			pre=pre->next;
		} 
		pre->next=(l1==NULL)?l2:l1;
		
		ListNode* res=preHead->next;
		delete preHead;
		return  res;
	}
};
