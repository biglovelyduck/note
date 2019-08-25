//树的遍历
#include <iostream>
#include <stack>
using namespace std;

//迭代版，栈，前序遍历
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

//中序遍历
void in(TreeNode* root){
	stack<Node*> st;
	TreeNode* cur=root;			//cur表示当前节点 
	while(cur||!st.empty()){
		if(cur){
			st.push(cur);
			cur=cur->left;	//依次将左边的结点放进栈 
		}
		else{
			cur=st.top();	//走不动了就弹出 
			st.pop();
			cout<<cur->val<<" ";
			cur=cur->right;	//左结点到头了再搞右节点 
		}
	}
} 

//后序遍历
void post(TreeNode *root){
	stack<TreeNode*> st;
	TreeNode *pre;
	TreeNode* cur=root; 
	while(cur||!st.empty()){
		/*出栈条件：
				对于叶子节点：直接弹出
				对于非叶子节点，如果已经遍历过其左节点或者右节点则弹出*/
		if(cur){
			st.push(p);
			cur=cur->left;		//走到最左边 
		}
		else{					//向右 
			cur=st.top();
			if(cur->right&&cur->right!=pre)	//如果右子节点存在并且未访问过 
			{
				cur=cur->right;	//转向右子节点
				st.push(cur);
				cur=cur->left;	//再走到最左 
			}
			else{				//没有右子节点就弹出 
				cur=st.top();
				st.pop();
				cout<<cur->val<<" ";
				pre=cur;		//记录最近访问过的节点 
				cur=NULL;		//节点访问完毕后重置 
			}
		}		
	}
} 
