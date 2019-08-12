//重建二叉树
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty()||vin.empty())
			return nullptr;
		
		//前序遍历的第一个节点是根
		int rootValue=pre[0];
		TreeNode *root=new TreeNode(pre[0]);
		root->left=root->right=nullptr;
		
		vector<int>::iterator index=find(vin.begin(),vin.end(),root->val);	//该迭代器不可以跨容器使用 
		vector<int>::iterator index1=pre.begin()+1+distance(vin.begin(),index); 
		vector<int> pL(pre.begin()+1,index1);		//全部都是左闭右开 
		vector<int> pR(index1,pre.end());
		vector<int> iL(vin.begin(),index);
		vector<int> iR(index+1,vin.end()); 
		
		root->left=reConstructBinaryTree(pL,iL);
		root->right=reConstructBinaryTree(pR,iR);

		return root;
    }
}; 
