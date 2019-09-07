//二叉树最大差异度
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
using namespace std; 

int Max=-1; 
struct Node{
	int val;
	int left;
	int right;
	Node(int x):val(x),left(-1),right(-1){
	}
};
vector<Node*> v;	//保存结点 
//计算当前节点的总价值
int summ(int parent){
	if(parent==-1) return 0;
	return v[parent]->val+summ(v[parent]->left)+summ(v[parent]->right);
} 
//计算当前节点的左右子树的差的绝对值 
int del(int parent){
	if(parent==-1) return 0;
	return abs(summ(v[parent]->left)-summ(v[parent]->right)); 
}
int main(){
	int N;
	cin>>N;	//节点的个数 
	for(int i=0;i<N;i++){
		int val;
		cin>>val;
		Node *node=new Node(val);
		v.push_back(node);
	} 
	//输入N-1条边 
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;		//两个有边节点的下标 
		int parent=min(a,b);		//父亲的下标 
		int son=max(a,b);			//儿子的下标 
		if(v[parent]->left==-1) v[parent]->left=son;
		if(v[parent]->right==-1) v[parent]->right=son; 
	}
	for(int i=0;i<v.size();i++){
		int dele=del(i);	//cout<<"dele:"<<dele<<endl;
		if(Max<dele) Max=dele;
	}
	//cout<<summ(0)<<endl;
	cout<<Max;
}
