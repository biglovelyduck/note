//���ı���
#include <iostream>
#include <stack>
using namespace std;

//�����棬ջ��ǰ�����
void pre(TreeNode* root){
	stack<Node*> st;
	if(root) st.push(root);
	while(!st.empty()){
		TreeNode *nd=st.top();
		st.pop();
		cout<<nd.val<<" ";
		
		if(nd->right) st.push(nd->right);
		if(nd->left) st.push(nd->left);
	}
} 

//�������
void in(TreeNode* root){
	stack<Node*> st;
	TreeNode* cur=root;			//cur��ʾ��ǰ�ڵ� 
	while(cur||!st.empty()){
		if(cur){
			st.push(cur);
			cur=cur->left;	//���ν���ߵĽ��Ž�ջ 
		}
		else{
			cur=st.top();	//�߲����˾͵��� 
			st.pop();
			cout<<cur->val<<" ";
			cur=cur->right;	//���㵽ͷ���ٸ��ҽڵ� 
		}
	}
} 

//�������
void post(TreeNode *root){
	stack<TreeNode*> st;
	TreeNode *pre;
	TreeNode* cur=root; 
	while(cur||!st.empty()){
		/*��ջ������
				����Ҷ�ӽڵ㣺ֱ�ӵ���
				���ڷ�Ҷ�ӽڵ㣬����Ѿ�����������ڵ�����ҽڵ��򵯳�*/
		if(cur){
			st.push(p);
			cur=cur->left;		//�ߵ������ 
		}
		else{					//���� 
			cur=st.top();
			if(cur->right&&cur->right!=pre)	//������ӽڵ���ڲ���δ���ʹ� 
			{
				cur=cur->right;	//ת�����ӽڵ�
				st.push(cur);
				cur=cur->left;	//���ߵ����� 
			}
			else{				//û�����ӽڵ�͵��� 
				cur=st.top();
				st.pop();
				cout<<cur->val<<" ";
				pre=cur;		//��¼������ʹ��Ľڵ� 
				cur=NULL;		//�ڵ������Ϻ����� 
			}
		}		
	}
} 
