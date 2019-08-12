//����������һ���ڵ� 
//����һ��������������һ���ڵ㣬����ҳ���һ���ڵ�
#include <iostream>
using namespace std;
struct BinaryTreeNode {
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL){}
}; 

BinaryTreeNode *GetNext(BinaryTreeNode *pNode){
	if(pNode==nullptr)
		return nullptr;
	BinaryTreeNode *pNext=nullptr;
	//1.��������������һ���ڵ����������������ڵ� 
	if(pNode->right!=nullptr){
		BinaryTreeNode *pRight=pNode->right;
		while(pRight->left!=nullptr){
			pRight=pRight-left;
		}
		pNext=pRight;
	}
	//2.û������������һ���ڵ���Ǹ��ڵ�
	else if(pNode->parent!=nullptr){
		BinaryTreeNode *pCurrent=pNode;
		BinartTreeNode *pParent=pCurrent->parent;
		while(pParent!=nullptr&&pCurrent==pParent->right){
			//��ǰ�ڵ��Ǹ��ڵ�����ӽڵ�
			pCurrent=pParent;
			pParent=pParent->parent; 	//ֱ���ҵ�һ���ڵ��Ǹ��ڵ�����ӽڵ�Ľڵ� 
		}
		pNext=pParent;
	} 
	return pNext;
}
