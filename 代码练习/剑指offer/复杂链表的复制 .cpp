//复杂链表的复制 
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
//第一种思路，挨个遍历,递归思想，O(n) ,我真是个天才 
/*
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        RandomListNode* node=new RandomListNode(pHead->label);
        RandomListNode* newNode=node;
        RandomListNode* start=pHead;
       	while(start){
       		if(start->next)
       			node->next=new RandomListNode(start->next->label);
       		start=start->next;
       		node=node->next;
		}
		//到这只是遍历了正向的链表
		//现在开始复制随机的链表 
		start=pHead;
		RandomListNode* start2=pHead;
		node=newNode;
		RandomListNode* node2=newNode;
		int step;
		while(start){
			if(start->random){
				step=0;
				while(start2){
					if(start2==start->random){
						break;	
					}
					start2=start2->next; 
					step++;
				}
				//step已经找到
				start2=pHead;
				node2=newNode;
				while(node2){
					node2=node2->next;
					step--;
					if(step==0){
						node->random=node2;
						break;		
					}
				} 
			}
			start=start->next; 
			node=node->next;
		} 
		return newNode;
    }
};*/ 

//第二种思路，哈希表法，O(n) 
/* 
class Solution {
public:
 RandomListNode* Clone(RandomListNode* pHead)
 {
  if (pHead == nullptr)
  {
  	return nullptr;
  }

  std::unordered_map<RandomListNode*, RandomListNode*> hash_map;

  for (RandomListNode* p = pHead; p != nullptr; p = p->next)
  {
   hash_map[p] = new RandomListNode(p->label);	//指向的了新的地址空间 
   //[N,N']配对的关系，现在只是做了配对 
  }

  for (RandomListNode* p = pHead; p != nullptr; p = p->next)
  {
   hash_map[p]->next = hash_map[p->next];	//现在开始连接起来分配的空间 
   hash_map[p]->random = hash_map[p->random];
  }

  return hash_map[pHead];
 }
};
*/

//第三种思路，三步走，把新创建的节点N'放在原来节点N的后面, O(n) 
//第一步：在原始链表每个节点N之后创建对应N'
class Solution{
public:
	void CLoneNodes(RandomListNode* pHead){
		RandomListNode* pNode=pHead;
		while(pNode!=NULL){
			RandomListNode* pCloned=new RandomListNode(pNode->label);
			pCloned->next=pNode->next;
			pCloned->random=NULL;
			pNode->next=pCloned;
			pNode=pCloned->next;
		}
	} 
	//第二步：设置复制出来的节点的随机节点 
	void ConnectSiblingNodes(RandomListNode* pHead){
		RandomListNode* pNode=pHead;
		while(pNode!=NULL){
			RandomListNode* pCloned=pNode->next;
			if(pNode->random!=NULL){
				pCloned->random=pNode->random->next;
			}
			pNode=pCloned->next;
		}
	} 
	//第三步，将链表拆分
	RandomListNode* ReconnectNodes(RandomListNode *pHead){
			RandomListNode* pNode=pHead;
			RandomListNode* pClonedHead=NULL;
			RandomListNode* pClonedNode=NULL;
			if(pNode!=NULL){
				pClonedHead=pClonedNode=pNode->next;
				pNode->next=pClonedNode->next;
				pNode=pNode->next;
			}
			while(pNode){
				pClonedNode->next=pNode->next;
				pClonedNode=pClonedNode->next;
				pNode->next=pClonedNode->next;
				pNode=pNode->next;
			}
			return pClonedHead;
	} 
	RandomListNode* Clone(RandomListNode* pHead){
		CLoneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
};

