//83-ɾ�����������е��ظ�Ԫ�� 
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
        			//p�ظ��ˣ���Ҫɾ��p
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

//1.˫ָ��
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;//��ָ��
        ListNode* q=head->next;//��ָ��
        while(p->next!=NULL)
        {
            if(p->val==q->val)//�ҵ��ظ�Ԫ��
            {
                if(q->next==NULL)//��ָ�������û��Ԫ��ֱ���޳�
                    p->next=NULL;
                else//��ָ�����Ԫ��
                {
                    p->next=q->next;
                    q=q->next;
                }
            }
            else //Ԫ�ز����
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};

//2.ֱ�ӷ�
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

//3.�ݹ鷨
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


 
