//二叉树中和为某一值的路径 
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
		
		//如果是叶子节点，并且路径上的节点值的和等于输入的值
		//则打印这条节点
		bool isLeaf=root->left==NULL&&root->right==NULL;
		if(current==n&&isLeaf){
			vec.push_back(path);
		}
		//如果不是叶子节点，就遍历它的子结点
		if(root->left!=nullptr){
			FindPath(root->left,n,path,current,vec);
		}
		if(root->right!=nullptr){
			FindPath(root->right,n,path,current,vec);
		}	
		path.pop_back();
	}
	//返回的每一行代表一条路径 
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > vec;
    	vector<int> path;
		if(root==NULL) return vec;
		int current=0;
		FindPath(root,expectNumber,path,current,vec);
		return vec;
    }
};

//大神的代码
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
