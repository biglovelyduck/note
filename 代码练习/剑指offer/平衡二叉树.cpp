//平衡二叉树，判断二叉树是不是平衡二叉树
//思路1：遍历每个节点的左子树和右子树的高度，不推荐
//思路2：后序遍历
class Solution{
public:
	bool isBalenced(BinaryTreeNode *root,int *depth){
		if(root==NULL){
			*depth=0;
			return true;
		}
		int l,r;
		if(isBalenced(root->left,&l)&&isBalenced(root->right,&r)){
			int diff=left-right;
			if(diff<=1&&diff>=-1){
				*depth=1+(l>r?l:r);
				return true;
			}
		}
		return false;
	}
}; 
