//链表 
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};
//链表的插入
void AddToTail(ListNode** pHead,int value){
	//注意pHead是指针的指针
	ListNode *pNew=new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=nullptr;
	
	if(*pHead==nullptr)
		*pHead=pNew;
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr)
			pNode=pNode->m_pNext;
		pNode->m_pNext=pNew;
	} 
} 

//链表的删除
void RemoveNode(ListNode **pHead,int value){
	if(pHead==nullptr||*pHead==nullptr)
		return;
	ListNode *pToBeDeleted=nullptr;
	if((*pHead)->m_nValue==value){
		pToBeDeleted=nullptr;
		*pHead=(*pHead)->m_pNext;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr&&pNode->m_pNext->m_nValue!=value){
			pNode=pNode->m_pNext;
		}
		if(pNode->m_pNext!=nullptr&&pNode->m_pNext->m_nValue==value){
			pToBeDeleted=pNode->m_pNext;
			pNode->m_pNext=pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted!=nullptr){
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}
} 
