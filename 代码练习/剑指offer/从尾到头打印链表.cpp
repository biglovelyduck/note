//从尾到头打印链表
#include <vector>
#include <stack>
#include <iostream>
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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        stack<ListNode*> nodes;
        ListNode* pNode=head;
        while(pNode!=nullptr){
        	nodes.push(pNode);
        	pNode=pNode->next;
		}
		while(!nodes.empty()){
			pNode=nodes.top();
			v.push_back(pNode->val);
			nodes.pop();
		}
		return v;
    }
    
    vector<int> test(){
    	vector<int> v;
    	for(int i=0;i<10;i++)
    		v.push_back(i);
    	return v;
	}
}; 

int main(){
	Solution s;
	vector<int> v=s.test();
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	return 0;
}
