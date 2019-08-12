//��֮���δ�ӡ������ 
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > v;
        if(pRoot==NULL) return v;
        stack<TreeNode*> s[2];	//��Ҫ�õ�����ջ,һ����������㣬һ�����ż���� 
		int current=0;			//��ǰ�� 
		int next=1;				//��һ�� ,Ҫ�������ñ��λ 
		s[current].push(pRoot);
		vector<int> data;
		while(!s[0].empty()||!s[1].empty()){
			TreeNode* node=s[current].top();
			s[current].pop();	//ȡ��ջ��Ԫ��
			data.push_back(node->val);
			if(current==0){
				//��һ���Ҫ�������ұ������η���ջ2�� 
				if(node->left) s[next].push(node->left);
				if(node->right) s[next].push(node->right); 
			}
			else{
				//��һ���Ҫ��������������η���ջ1�� 
				if(node->right) s[next].push(node->right);
				if(node->left) s[next].push(node->left); 
			}
			if(s[current].empty()){
				v.push_back(data);
				data.clear();
				current=1-current;
				next=1-next;
			}
		}
		return v;
    }
    
};

/*

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        stack<TreeNode *> stack1,stack2;
        bool direction = true;//���Ҵ�ӡΪtrue�������ӡΪfalse
        if(pRoot!=NULL)
            stack1.push(pRoot);
        struct TreeNode *node;
        while(!stack1.empty() || !stack2.empty()){
            vector<int> data;
            if(!stack1.empty()){
                while(!stack1.empty()){
                    node = stack1.top();
                    stack1.pop();
                    data.push_back(node->val);
                    if(node->left!=NULL)
                        stack2.push(node->left);
                    if(node->right!=NULL)
                        stack2.push(node->right);
                }
                result.push_back(data);
            }
            else if(!stack2.empty()){
                while(!stack2.empty()){
                    node = stack2.top();
                    stack2.pop();
                    data.push_back(node->val);
                    if(node->right!=NULL)
                        stack1.push(node->right);
                    if(node->left!=NULL)
                        stack1.push(node->left);
                }
                result.push_back(data);
            }
        }
        return result;
    }*/
