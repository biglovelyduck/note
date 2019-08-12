//�������к�Ϊĳһֵ��·�� 
#include <vector>
#include <queue>
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
	void FindPath(TreeNode* root,int n,vector<int> &path,int current,
					vector<vector<int> >& vec){
		current+=root->val;
		path.push_back(root->val);
		
		//�����Ҷ�ӽڵ㣬����·���ϵĽڵ�ֵ�ĺ͵��������ֵ
		//���ӡ�����ڵ�
		bool isLeaf=root->left==NULL&&root->right==NULL;
		if(current==n&&isLeaf){
			vec.push_back(path);
		}
		//�������Ҷ�ӽڵ㣬�ͱ��������ӽ��
		if(root->left!=nullptr){
			FindPath(root->left,n,path,current,vec);
		}
		if(root->right!=nullptr){
			FindPath(root->right,n,path,current,vec);
		}	
		path.pop_back();
	}
	//���ص�ÿһ�д���һ��·�� 
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > vec;
    	vector<int> path;
		if(root==NULL) return vec;
		int current=0;
		FindPath(root,expectNumber,path,current,vec);
		return vec;
    }
};

//����Ĵ���
/* 

class Solution {
public:
     vector<vector<int>> res;
     vector<int> path;
    void find(TreeNode* root,  int sum)
    {
        if (root == NULL)return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            res.push_back(path);
        else
        {
            if (root->left)
                find(root->left, sum - root->val);
            if (root->right)
                find(root->right, sum - root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
}; 	*/
