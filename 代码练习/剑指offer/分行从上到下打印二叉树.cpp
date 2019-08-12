//分行从上到下打印二叉树
#include <vector>
#include <queue>
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

void Print(TreeNode* root){
	if(root==nullptr) return;
	queue<TreeNode*> q;
	q.push(root);
	int nextLevel=0;	//下一层的节点数
	int toBePrinted=1;	//当前层中还没有打印的节点数
	while(!q.empty()){
		TreeNode* node=q.front();
		cout<<node->val;
		if(node->left){
			q.push(node->left);
			++nextLevel;
		}
		if(node->right){
			q.push(node->right);
			++nextLevel;
		}
		q.pop();
		--toBePrinted;
		if(toBePrinted==0){
			cout<<endl;
			toBePrinted=nextLevel;
			nextLevel=0;
		}
	} 
} 
