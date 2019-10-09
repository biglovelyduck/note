//83-删除排序链表中的重复元素 
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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return NULL;
        if(!head->next) return head;
        ListNode *p=head->next,*pre=head,*pi=head;
        while(p){
        	while(pi&&pi!=p){
        		if(pi->val==p->val){
        			pi=head;
        			//p重复了，就要删除p
        			pre->next=p->next; 
        			break;
				}
        		pi=pi->next;
			}
			if(pre->next==p)
				pre=p;
			p=p->next;
		}
		return head;
    }
};

//1.双指针
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;//慢指针
        ListNode* q=head->next;//快指针
        while(p->next!=NULL)
        {
            if(p->val==q->val)//找到重复元素
            {
                if(q->next==NULL)//快指针后面若没有元素直接剔除
                    p->next=NULL;
                else//快指针后有元素
                {
                    p->next=q->next;
                    q=q->next;
                }
            }
            else //元素不相等
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};

//2.直接法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* p=head;
        while(p->next!=NULL&&p!=NULL)
        {
            if(p->val == p->next->val)
            {
                p->next=p->next->next;
            }
            else 
                p=p->next;
        }
        return head;
    }
};

//3.递归法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        head->next=deleteDuplicates(head->next);
        if(head->val==head->next->val) head=head->next;
        return head;
    }
};


 
