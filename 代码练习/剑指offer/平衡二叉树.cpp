//ƽ����������ж϶������ǲ���ƽ�������
//˼·1������ÿ���ڵ�����������������ĸ߶ȣ����Ƽ�
//˼·2���������
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
