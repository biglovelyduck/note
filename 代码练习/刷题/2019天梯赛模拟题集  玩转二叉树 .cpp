//2019天梯赛模拟题集  玩转二叉树 
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
struct node{
	int data;
	node *lc;
	node *rc;
};
void pre_order(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	pre_order(root->lc);
	pre_order(root->rc);
}
void in_order(node* root){
	if(root==NULL) return;
	in_order(root->lc);
	cout<<root->data<<" ";
	in_order(root->rc); 
}
void post_order(node* root){
	if(root==NULL) return;
	post_order(root->lc);
	post_order(root->rc);
	cout<<root->data<<" ";
}
void cengci(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* n=q.front();q.pop();
		if(n->lc!=NULL) q.push(n->lc);
		if(n->rc!=NULL)	q.push(n->rc);
		if(q.empty()){
			cout<<n->data;
			break;
		}
		cout<<n->data<<" ";
	}
}
void mirror_level(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* n=q.front();q.pop();
		if(n->rc!=NULL)	q.push(n->rc);
		if(n->lc!=NULL) q.push(n->lc);
		if(q.empty()){
			cout<<n->data;
			break;
		}
		cout<<n->data<<" ";
	}
}
/*思路，先找到中序遍历的根
然后：分割，找到左右子树前序遍历和中序遍历*/
node* CreateTree(vector<int>& in,vector<int>& pre){
	node *root=NULL;
	if(pre.size()>0){
		root=new node;
		root->data=pre[0];
		root->lc=NULL;
		root->rc=NULL;
		//找到根结点位置 
		vector<int>::iterator index=find(in.begin(),in.end(),root->data);
		//前序遍历中左右子树的分界点 
		vector<int>::iterator index1=pre.begin()+1+distance(in.begin(),index); 
		vector<int> pL(pre.begin()+1,index1);		//全部都是左闭右开 
		vector<int> pR(index1,pre.end());
		vector<int> iL(in.begin(),index);
		vector<int> iR(index+1,in.end()); 
		root->lc=CreateTree(iL,pL);
		root->rc=CreateTree(iR,pR); 
	}
	return root;
}
int main(){
	int N;
	cin>>N;
	vector<int> in(N),pre(N);
	for(int i=0;i<N;i++){
		cin>>in[i];
	}
	for(int i=0;i<N;i++){
		cin>>pre[i];
	}
	node* root=CreateTree(in,pre);
	mirror_level(root);
	
	return 0;
}
