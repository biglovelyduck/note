//25-k个一组反转链表 
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
//三部分，已反转，待反转，未反转
//start,end分别表示待反转链表的开头和末尾，pre表示已反转链表的末尾，next表示未反转链表的开头 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy=new ListNode(0);
		dummy->next=head;
		
		ListNode* pre=dummy;
		ListNode *end=dummy;
		
		while(end->next){
			for(int i=0;i<k&&end!=NULL;i++) end=end->next;	//找到待反转链表的末尾 
			if(end==NULL) break;
			ListNode *start=pre->next;		//待反转链表的头部 
			ListNode *next=end->next;		//未反转链表的头部 
			end->next=NULL;					//断开原有连接 
			pre->next=reverse(start);		//返回反转后的头节点,连接好前驱和已反转链表 
			start->next=next;				//连接好已反转链表和后继节点 
			pre=start;						//更新已反转好的链表的前驱 
			
			end=pre; 						//初始化end 
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

//思路2：栈，压入k个数，弹出来就是反的,写不出来。。。 
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

//思路3：栈+递归（数组实现的栈）
/*class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
		int i = k;
		ListNode[] stack = new ListNode[k];//没有无参构造方法，但是构建了没有值的结点。相当于int i;
		ListNode q = head;
		while(k>0) {//把当前k个结点存入栈中。
			stack[i-k] = q;
			if (q!=null) q=q.next;
			else return head;//结点凑不到k个时，直接返回原部分链表。
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

//思路4：递归 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre=head;
        int count=0;
        while(pre!=NULL&&count<k){
            pre=pre->next;
            count++;
        } //退出循环后pre指向第k+1个节点
        if(count==k) {
            pre=reverseKGroup(pre,k);
            while(count>0){ 
                /* head指向本次循环反转指向的节点
                   temp指向下次循环反转指向的节点
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
 
