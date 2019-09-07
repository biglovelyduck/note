//�������������
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
vector<Node*> v;	//������ 
//���㵱ǰ�ڵ���ܼ�ֵ
int summ(int parent){
	if(parent==-1) return 0;
	return v[parent]->val+summ(v[parent]->left)+summ(v[parent]->right);
} 
//���㵱ǰ�ڵ�����������Ĳ�ľ���ֵ 
int del(int parent){
	if(parent==-1) return 0;
	return abs(summ(v[parent]->left)-summ(v[parent]->right)); 
}
int main(){
	int N;
	cin>>N;	//�ڵ�ĸ��� 
	for(int i=0;i<N;i++){
		int val;
		cin>>val;
		Node *node=new Node(val);
		v.push_back(node);
	} 
	//����N-1���� 
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;		//�����б߽ڵ���±� 
		int parent=min(a,b);		//���׵��±� 
		int son=max(a,b);			//���ӵ��±� 
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
