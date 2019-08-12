//2016天梯赛模拟题 树的遍历 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
/*
struct node{
	char data;
	node* lc;
	node* rc;
};*/
struct node{
	int data;
	node* lc;
	node* rc;
};
void PreOrder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	PreOrder(root->lc);
	PreOrder(root->rc);
}
void Cengci(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* n=q.front(); q.pop();
		if(n->lc!=NULL) q.push(n->lc);
		if(n->rc!=NULL)	q.push(n->rc);
		if(q.empty()){
			cout<<n->data;
			break;
		}
		cout<<n->data<<" ";
	}
}
//只针对字符串有效 
/* 
node* Create(string postorder,string inorder){
	node* root=NULL;
	if(postorder.size()>0){		//后序遍历还有元素 
		root=new node;
		int len=postorder.size();
		root->data=postorder[len-1];
		root->lc=NULL;
		root->rc=NULL;
		string postL,postR;		//左子树和右子树的后序遍历 
		string inL,inR;			//左子树和右子树的中序遍历
		int index=inorder.find(postorder[len-1]);	//中序遍历中root的位置
		//分割
		inL=inorder.substr(0,index);
		inR=inorder.substr(index+1,inorder.size()-1-index); 
		postL=postorder.substr(0,index);
		postR=postorder.substr(index,postorder.size()-1-index);
		
		root->lc=Create(postL,inL);
		root->rc=Create(postR,inR);
	}
	return root;
} 
*/
//返回根结点 
node* Create(vector<int> &post,vector<int> &in){
	node* root=NULL;
	if(post.size()>0){
		root=new node;
		int len=post.size();
		root->data=post[len-1];
		root->lc=NULL;
		root->rc=NULL; 
		vector<int>::iterator index=find(in.begin(),in.end(),root->data);	//该迭代器不可以跨容器使用 
		vector<int>::iterator index1=post.begin()+distance(in.begin(),index); 
		vector<int> iL(in.begin(),index); 
		vector<int> iR(index+1,in.end());
		vector<int> pL(post.begin(),index1);
		vector<int> pR(index1,post.end()-1);

		
		root->lc=Create(pL,iL);
		root->rc=Create(pR,iR);
	}
	return root;
}
int main(){
//	int n;
//	cin>>n;
//	char c;
//	string strP="";
//	string strI="";
//	for(int i=0;i<n;i++){
//		cin>>c;
//		strP+=c;
//	}
//	for(int i=0;i<n;i++){
//		cin>>c;
//		strI+=c;
//	}
//	node* root=Create(strP,strI);
//	//PreOrder(root);
//	Cengci(root);

//重写
	int n;
	cin>>n;
	vector<int> a(n),b(n);	//后序和中序遍历的数组 
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i]; 
	node* root=Create(a,b);
	Cengci(root);
	return 0;
}
