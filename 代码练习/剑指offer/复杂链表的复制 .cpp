//��������ĸ��� 
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
//��һ��˼·����������,�ݹ�˼�룬O(n) ,�����Ǹ���� 
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
		//����ֻ�Ǳ��������������
		//���ڿ�ʼ������������� 
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
				//step�Ѿ��ҵ�
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

//�ڶ���˼·����ϣ����O(n) 
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
   hash_map[p] = new RandomListNode(p->label);	//ָ������µĵ�ַ�ռ� 
   //[N,N']��ԵĹ�ϵ������ֻ��������� 
  }

  for (RandomListNode* p = pHead; p != nullptr; p = p->next)
  {
   hash_map[p]->next = hash_map[p->next];	//���ڿ�ʼ������������Ŀռ� 
   hash_map[p]->random = hash_map[p->random];
  }

  return hash_map[pHead];
 }
};
*/

//������˼·�������ߣ����´����Ľڵ�N'����ԭ���ڵ�N�ĺ���, O(n) 
//��һ������ԭʼ����ÿ���ڵ�N֮�󴴽���ӦN'
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
	//�ڶ��������ø��Ƴ����Ľڵ������ڵ� 
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
	//����������������
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

