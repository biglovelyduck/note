//数据流中的中位数2
/*链接：https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
来源：牛客网

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后
位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。*/ 
#include <iostream>
#include <vector>
//#include <functional>
#include <algorithm>
#include <stdexcept> 

using namespace std; 

//平衡二叉搜索树思想
struct TreeNode{
	int val;
	int count;	//根的树高
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int v):val(v),count(1),left(NULL),right(NULL){
	} 
};
 
TreeNode *root=NULL;

class Solution{
public:
	//计算以节点为根的树的高度
	int totalCount(TreeNode *node){
		if(node==NULL)
			return 0;
		else
			return node->count; 
	} 
	//左左
	void rotateLL(TreeNode *p){
		TreeNode *k=p->left;
		TreeNode *tm=NULL;
		while(k->right!=NULL){
			k->count--;		//当前节点为根的树的高度 
			tm=k;
			k=k->right;
		}
		if(k!=p->left){
			p->left=k;
			tm->right=NULL;
		} 
		tm->right=p;
		
		t->count=totalCount(t->left)+totalCount(t->right)+1;
		k->count=totalCount(k->left)+t->count+1;
		
		t=k;
	} 
};
