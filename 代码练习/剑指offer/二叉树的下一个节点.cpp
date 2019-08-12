//二叉树的下一个节点 
//给定一个二叉树和其中一个节点，如何找出下一个节点
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
	//1.有右子树，即下一个节点就是右子树的最左节点 
	if(pNode->right!=nullptr){
		BinaryTreeNode *pRight=pNode->right;
		while(pRight->left!=nullptr){
			pRight=pRight-left;
		}
		pNext=pRight;
	}
	//2.没有右子树，下一个节点就是父节点
	else if(pNode->parent!=nullptr){
		BinaryTreeNode *pCurrent=pNode;
		BinartTreeNode *pParent=pCurrent->parent;
		while(pParent!=nullptr&&pCurrent==pParent->right){
			//当前节点是父节点的右子节点
			pCurrent=pParent;
			pParent=pParent->parent; 	//直到找到一个节点是父节点的左子节点的节点 
		}
		pNext=pParent;
	} 
	return pNext;
}
