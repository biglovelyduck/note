//�ؽ�������
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
		
		//ǰ������ĵ�һ���ڵ��Ǹ�
		int rootValue=pre[0];
		TreeNode *root=new TreeNode(pre[0]);
		root->left=root->right=nullptr;
		
		vector<int>::iterator index=find(vin.begin(),vin.end(),root->val);	//�õ����������Կ�����ʹ�� 
		vector<int>::iterator index1=pre.begin()+1+distance(vin.begin(),index); 
		vector<int> pL(pre.begin()+1,index1);		//ȫ����������ҿ� 
		vector<int> pR(index1,pre.end());
		vector<int> iL(vin.begin(),index);
		vector<int> iR(index+1,vin.end()); 
		
		root->left=reConstructBinaryTree(pL,iL);
		root->right=reConstructBinaryTree(pR,iR);

		return root;
    }
}; 
