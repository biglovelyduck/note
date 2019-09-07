//25-k��һ�鷴ת���� 
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
//�����֣��ѷ�ת������ת��δ��ת
//start,end�ֱ��ʾ����ת����Ŀ�ͷ��ĩβ��pre��ʾ�ѷ�ת�����ĩβ��next��ʾδ��ת����Ŀ�ͷ 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy=new ListNode(0);
		dummy->next=head;
		
		ListNode* pre=dummy;
		ListNode *end=dummy;
		
		while(end->next){
			for(int i=0;i<k&&end!=NULL;i++) end=end->next;	//�ҵ�����ת�����ĩβ 
			if(end==NULL) break;
			ListNode *start=pre->next;		//����ת�����ͷ�� 
			ListNode *next=end->next;		//δ��ת�����ͷ�� 
			end->next=NULL;					//�Ͽ�ԭ������ 
			pre->next=reverse(start);		//���ط�ת���ͷ�ڵ�,���Ӻ�ǰ�����ѷ�ת���� 
			start->next=next;				//���Ӻ��ѷ�ת����ͺ�̽ڵ� 
			pre=start;						//�����ѷ�ת�õ������ǰ�� 
			
			end=pre; 						//��ʼ��end 
		}
		return dummy->next;
    }
    ListNode *reverse(ListNode *head){
    	ListNode *pre=NULL;
    	ListNode *curr=head;
    	while(curr!=NULL){
    		ListNode *next=curr->next;
    		curr->next=pre;
    		pre=curr;
    		curr=next;
		}
		return pre;
	} 
};

//˼·2��ջ��ѹ��k���������������Ƿ���,д������������ 
class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	stack<ListNode*> s;
    	ListNode *end=new ListNode(0);
    	ListNode *rel=end,*pre=end;
    	ListNode* ret=rel;
    	end->next=head;
    	ListNode* cur=head;
		while(cur){
			for(int i=1;i<=k&&cur!=NULL;i++){
				s.push(cur);
				pre=cur;
				cur=cur->next;
			}
			if(cur==NULL){
				break;
			}
			end=pre;
			while(!s.empty()){
				ListNode *node=s.top();
				s.pop();
				rel->next=node;
				rel=rel->next;
			}
		}
		rel->next=end->next;
		return ret->next;
	} 
}; 

//˼·3��ջ+�ݹ飨����ʵ�ֵ�ջ��
/*class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
		int i = k;
		ListNode[] stack = new ListNode[k];//û���޲ι��췽�������ǹ�����û��ֵ�Ľ�㡣�൱��int i;
		ListNode q = head;
		while(k>0) {//�ѵ�ǰk��������ջ�С�
			stack[i-k] = q;
			if (q!=null) q=q.next;
			else return head;//���ղ���k��ʱ��ֱ�ӷ���ԭ��������
			k--;
		}
		while(k<i-1) {
			k++;
			stack[i-k].next=stack[i-k-1];
		}
		stack[0].next=reverseKGroup(q, k+1);
		return stack[i-1];
    }
}
*/ 

//˼·4���ݹ� 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre=head;
        int count=0;
        while(pre!=NULL&&count<k){
            pre=pre->next;
            count++;
        } //�˳�ѭ����preָ���k+1���ڵ�
        if(count==k) {
            pre=reverseKGroup(pre,k);
            while(count>0){ 
                /* headָ�򱾴�ѭ����תָ��Ľڵ�
                   tempָ���´�ѭ����תָ��Ľڵ�
                */
                ListNode* temp=head->next; 
                head->next=pre;
                pre=head;
                head=temp;
                count--;
            }
            head=pre;
        }
        return head;
    }
};
 
