//61-��ת���� 
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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(k==0) return head;
    	if(head==NULL) return NULL;
    	//�ȱ���һ��ȷ��������
		int len=0;
		ListNode *p=head;
		while(p!=NULL){
			len++;
			p=p->next;
		} 
		//���k>=n
		k=k%len;	//k�������ƶ����� 
		if(k==0) return head;
		//�ҵ�Ҫ�Ͽ���λ��
		p=head;
		ListNode* pre=NULL;
		for(int i=0;i<len-k;i++){
			pre=p;
			p=p->next;
		}
		ListNode* ret=p;
		pre->next=NULL;
		while(p->next) p=p->next;
		p->next=head;
		return ret;
    }
};

//���빦��
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *p;
		int n = 1;
		for(p=head; p->next; ++n, p=p->next); // list length
		p->next = head;     // relink to head
		for(k=n-k%n; k--; p=head,head=head->next);
		p->next = NULL;     // cut down list
		return head;
	}
};


int main(){
	for(int i=0;i<0;i++) cout<<i<<endl;
	return 0;
}
