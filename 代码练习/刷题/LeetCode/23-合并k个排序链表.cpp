//23-�ϲ�k����������
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
 
 //1.���� �������н���ֵ����һ�������� 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	vector<int> v;
    	if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size();i++){
        	ListNode* node=lists[i];		//ÿ��Ԫ�ض���ListNode*���� 
        	while(node){
        		v.push_back(node->val);
        		node=node->next;
			}
		} 
		sort(v.begin(),v.end(),less<int>()) ;
		ListNode *rel=NULL;
		if(v.size()>0)
			rel=new ListNode(v[0]);
		else return NULL;
		ListNode *p=rel;
		for(int i=1;i<v.size();i++){
			p->next=new ListNode(v[i]);
			p=p->next;
		}
		return rel;
    }
}; 

//2.��һ�Ƚ� ��ÿ�α��������Сֵ�Ľ��,���Ƽ���д�������鷳 
//3.ʹ���ϴ�д����������ϲ��ĺ��������������ϲ� ,���� �鲢 
class Solution1 {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size()==0) return NULL;
		return solve(lists,0,lists.size()-1);		
    }
    ListNode* solve(vector<ListNode*>& lists,int left,int right){
    	if(left==right) return lists[left];
    	int mid=(left+right)/2;
    	ListNode *lNode=solve(lists,left,mid);
    	ListNode *rNode=solve(lists,mid+1,right);
		return mergeTwoLists(lNode,rNode);
	}
}; 

//4.���ȶ���
class Solution3 {
public:
    struct cmp{
		bool operator()(ListNode* l1, ListNode* l2){
			return l1->val > l2->val;
		}
	};
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* phead = new ListNode(0); ListNode* p = phead;
        if(lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> MinHeap;	//valС�����ȼ��� 
        for(int i = 0;i < lists.size();i++) if(lists[i] != nullptr)MinHeap.push(lists[i]);
        while(!MinHeap.empty()){
            p->next = MinHeap.top();p = p->next;
            if(MinHeap.top()->next != nullptr) MinHeap.push(MinHeap.top()->next);MinHeap.pop();
        }
        return phead->next;
    }   
};

