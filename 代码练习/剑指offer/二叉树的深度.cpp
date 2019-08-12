//二叉树的深度

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
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==NULL) return 0;
		int l=TreeDepth(pRoot->left);
		int r=TreeDepth(pRoot->right);
		return (l>r)?l+1:r+1; 
    }
};
 
