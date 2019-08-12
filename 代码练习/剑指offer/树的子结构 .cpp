//树的子结构 
#include <bits/stdc++.h>
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
	bool Equal(int num1,int num2){
		if(num1==num2)
			return true;
		else 
			return false;
	} 
	
	bool DoesTree1HasTree2(TreeNode *pRoot1,TreeNode* pRoot2){
		if(pRoot2==nullptr) return true;
		if(pRoot1==nullptr) return false;
		if(!Equal(pRoot1->val,pRoot2->val)) return false;
		return DoesTree1HasTree2(pRoot1->left,pRoot2->left)&&
				DoesTree1HasTree2(pRoot1->right,pRoot2->right);
	} 
	
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool result=false;
		if(pRoot1!=nullptr&&pRoot2!=nullptr){
			if(Equal(pRoot1->val,pRoot2->val))
				result=DoesTree1HasTree2(pRoot1,pRoot2);
			if(!result)
				result==DoesTree1HasTree2(pRoot1->left,pRoot2);
			if(!result)
				result==DoesTree1HasTree2(pRoot1->right,pRoot2);
		}	
		return result;
    }
};
