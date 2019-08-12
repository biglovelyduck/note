//求链表倒数第k个节点 
#include <cstdlib>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	//统计链表的节点总数
		ListNode *p1=pListHead;
		ListNode *p2=pListHead;
		if(pListHead==NULL||k==0) return NULL;
		unsigned int len=1;
		while(p1->next!=NULL){
			len++;
			p1=p1->next;
		} 
		if(len<k) return NULL;
		
		//解:双指针
		p1=pListHead;
		p2=pListHead;  
		for(unsigned int i=0;i<k-1;i++){
			p1=p1->next;
		} 
		while(p1->next!=NULL){
			p2=p2->next;
			p1=p1->next;
		}
		return p2;
    }
};
