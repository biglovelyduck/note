//������������˫������
#include <vector>
#include <stack>
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

//����һ���ǵݹ����������㷨 ���޸ĵ�ǰ�����ڵ��ǰһ�������ڵ��ָ��ָ�� 
/*
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root==NULL) return NULL;
        stack<TreeNode*> s;
        TreeNode* p=root;
        TreeNode* pre=NULL;
        bool isFirst=true;
        while(p||!s.empty()){
        	while(p){
        		s.push(p);
        		p=p->left;
			}
			p=s.top();	s.pop();
			if(isFirst){
				root=p;	//����������ĵ�һ���ڵ��Ϊroot
				pre=root;
				isFirst=false; 
			}
			else{
				pre->right=p;
				p->left=pre;
				pre=p;
			}
			p=p->right;
		}
		return root;
    }
};*/

//�������� �ݹ�
/*˼·��

1.�������������˫��������������ͷ�ڵ㡣
2.��λ��������˫�������һ���ڵ㡣
3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
4.�������������˫��������������ͷ�ڵ㡣
5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
6.���������������Ƿ�Ϊ��ȷ�����صĽڵ㡣*/ 
class Solution{
public:
	TreeNode* Convert(TreeNode* root){
		if(root==NULL){
			return NULL;
		}
		if(!root->left&&!root->right)
			return root;
		//1.�������������˫��������������ͷ�ڵ�
		TreeNode* left=Convert(root->left);
		TreeNode* p=left;	//����ͷ�ڵ� 
		//2.��λ��������˫��������һ���ڵ�
		while(p&&p->right)
			p=p->right;
		//3.�������������Ϊ�յĻ�������ǰroot׷�ӵ����������� 
		if(left){
			p->right=root;
			root->left=p;
		}
		//4.������������˫��������������ͷ�ڵ� 
		TreeNode* right=Convert(root->right);
		//5.�������������Ϊ�յĻ���׷�ӵ�root��
		if(right){
			root->right=right;
			right->left=root;
		} 
		return left!=NULL?left:root;
	}
}; 
