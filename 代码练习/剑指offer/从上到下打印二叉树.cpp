//从上到下打印二叉树
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

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> v;
		if(root==NULL) return v;
		q.push(root);
		while(!q.empty()){
			TreeNode* node=q.front();
			q.pop();
			v.push_back(node->val);
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		return v;
    }
};
