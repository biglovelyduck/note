//2019������ģ���⼯  ��ת������ 
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
/*˼·�����ҵ���������ĸ�
Ȼ�󣺷ָ�ҵ���������ǰ��������������*/
node* CreateTree(vector<int>& in,vector<int>& pre){
	node *root=NULL;
	if(pre.size()>0){
		root=new node;
		root->data=pre[0];
		root->lc=NULL;
		root->rc=NULL;
		//�ҵ������λ�� 
		vector<int>::iterator index=find(in.begin(),in.end(),root->data);
		//ǰ����������������ķֽ�� 
		vector<int>::iterator index1=pre.begin()+1+distance(in.begin(),index); 
		vector<int> pL(pre.begin()+1,index1);		//ȫ����������ҿ� 
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
