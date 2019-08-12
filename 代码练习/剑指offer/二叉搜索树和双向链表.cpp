//二叉搜索树和双向链表
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//方法一：非递归的中序遍历算法 ，修改当前遍历节点和前一个遍历节点的指针指向 
/*
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root==NULL) return NULL;
        stack<TreeNode*> s;
        TreeNode* p=root;
        TreeNode* pre=NULL;
        bool isFirst=true;
        while(p||!s.empty()){
        	while(p){
        		s.push(p);
        		p=p->left;
			}
			p=s.top();	s.pop();
			if(isFirst){
				root=p;	//将中序遍历的第一个节点记为root
				pre=root;
				isFirst=false; 
			}
			else{
				pre->right=p;
				p->left=pre;
				pre=p;
			}
			p=p->right;
		}
		return root;
    }
};*/

//方法二： 递归
/*思路：

1.将左子树构造成双链表，并返回链表头节点。
2.定位至左子树双链表最后一个节点。
3.如果左子树链表不为空的话，将当前root追加到左子树链表。
4.将右子树构造成双链表，并返回链表头节点。
5.如果右子树链表不为空的话，将该链表追加到root节点之后。
6.根据左子树链表是否为空确定返回的节点。*/ 
class Solution{
public:
	TreeNode* Convert(TreeNode* root){
		if(root==NULL){
			return NULL;
		}
		if(!root->left&&!root->right)
			return root;
		//1.将左子树构造成双向链表，返回链表头节点
		TreeNode* left=Convert(root->left);
		TreeNode* p=left;	//链表头节点 
		//2.定位至左子树双链表的最后一个节点
		while(p&&p->right)
			p=p->right;
		//3.如果左子树链表不为空的话，将当前root追加到左子树链表 
		if(left){
			p->right=root;
			root->left=p;
		}
		//4.将右子树构成双链表，并返回链表头节点 
		TreeNode* right=Convert(root->right);
		//5.如果右子树链表不为空的话，追加到root后
		if(right){
			root->right=right;
			right->left=root;
		} 
		return left!=NULL?left:root;
	}
}; 
