//二叉搜索树的第k大节点
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
	int index=0;
    TreeNode* KthNode(TreeNode* root, int k)
    {
    	if(root!=NULL){
    		TreeNode *node=KthNode(root->left,k);
    		if(node!=NULL) return node;
    		index++;
    		if(index==k) return root;
    		node=KthNode(root->right,k);
    		if(node!=NULL) return node;
		}
		return NULL;
    }

    
}; 

/*最好理解的方法
链接：https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a
来源：牛客网


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
    //中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot==NULL||k<=0) return NULL;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec);
        if(k>vec.size())
            return NULL;
        return vec[k-1];
    }
    //中序遍历，将节点依次压入vector中
    void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
    {
        if(pRoot==NULL) return;
        Inorder(pRoot->left,vec);
        vec.push_back(pRoot);
        Inorder(pRoot->right,vec);
    } 
};*/
