//�������е���λ��2
/*���ӣ�https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
��Դ��ţ����

��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��
λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����*/ 
#include <iostream>
#include <vector>
//#include <functional>
#include <algorithm>
#include <stdexcept> 

using namespace std; 

//ƽ�����������˼��
struct TreeNode{
	int val;
	int count;	//��������
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int v):val(v),count(1),left(NULL),right(NULL){
	} 
};
 
TreeNode *root=NULL;

class Solution{
public:
	//�����Խڵ�Ϊ�������ĸ߶�
	int totalCount(TreeNode *node){
		if(node==NULL)
			return 0;
		else
			return node->count; 
	} 
	//����
	void rotateLL(TreeNode *p){
		TreeNode *k=p->left;
		TreeNode *tm=NULL;
		while(k->right!=NULL){
			k->count--;		//��ǰ�ڵ�Ϊ�������ĸ߶� 
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
