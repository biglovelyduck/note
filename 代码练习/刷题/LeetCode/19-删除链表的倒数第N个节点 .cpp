//19-删除链表的倒数第N个节点 
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
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//16ms,8.5MB
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head==NULL) return NULL;
        ListNode* p=head;
        //得先求出链表的长度
        int len=0;
		while(p){
			len++;
			p=p->next;
		}
		if(len<n) return NULL;
		else if(len==n){
			ListNode* ret=head->next; 
			head=NULL;
			return ret;
		}
		int step=len-n;	//要走到删除的节点的步数 
		p=head;
		ListNode* pre=NULL;
		while(step--){
			pre=p;
			p=p->next;
		} 
		//p现在的位置就是要删除的位置
		ListNode* next=p->next;
		pre->next= next;
		p->next=NULL;
		
		return head;
    }    
};

//双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for( int i = 0 ; i < n + 1 ; i ++ ){
            q = q->next;
        }

        while(q){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
        
    }
};
