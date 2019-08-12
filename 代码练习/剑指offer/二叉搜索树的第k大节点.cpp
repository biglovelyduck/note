//�����������ĵ�k��ڵ�
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

/*������ķ���
���ӣ�https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a
��Դ��ţ����


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
    //��������Ľ�������������У���K��Ԫ�ؾ���vec[K-1]�洢�Ľڵ�ָ�룻
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot==NULL||k<=0) return NULL;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec);
        if(k>vec.size())
            return NULL;
        return vec[k-1];
    }
    //������������ڵ�����ѹ��vector��
    void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
    {
        if(pRoot==NULL) return;
        Inorder(pRoot->left,vec);
        vec.push_back(pRoot);
        Inorder(pRoot->right,vec);
    } 
};*/
