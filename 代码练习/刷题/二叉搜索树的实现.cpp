/*二叉搜索树树的实现*/
//删除情况：
//1.需要删除的结点没有左儿子，那么就把右儿子提上去
//2.需要删除的结点的左儿子没有右儿子，那么就把左儿子提上去
//3.以上两种情况都不满足的话，就把左儿子的子孙中最大的结点提到需要删除的结点的位置
#include <iostream>
using namespace std;
struct node{
	int val;
	node *lch,*rch;
}; 

//插入数值x,p为从这个节点开始插入 
node* insert(node *p,int x){
	if(p==NULL){
		node *q=new node;
		q->val=x;
		q->lch=q->rch=NULL;
		return q;
	} 
	else {
		if(x<p->val) p->lch=insert(p->lch,x);
		else p->rch=insert(p->rch,x);
		return p;							//?
	}
}

//查找数值x
bool find(node *p,int x){
	if(p==NULL) return false;
	else if(x==p->val) return true;
	else if(x<p->val)	return find(p->lch,x); 
	else return find(p->rch,x);
}

//删除数值x
node *remove(node *p,int x){
	if(p==NULL) return NULL;
	else if(x<p->val) p->lch=remove(p->lch,x);
	else if(x>p->val) p->rch=remove(p->rch,x);
	else if(p->lch==NULL){
		//把右儿子提上去
		node *q=p->rch;
		delete p;
		return q; 
	}
	else if(p->lch->rch==NULL){
		//把左儿子提上去
		node *q=p->lch;
		q->rch=p->rch;
		delete p;
		return q; 
	}
	else{
		//左儿子子孙最大的提上去
		node *q;
		for(q=p->lch;q->rch->rch!=NULL;q=q->rch);
		node *r=q->rch;//最大子孙 
		q->rch=r->lch;//q的右子树续接r的左子树 
		r->lch=p->lch;
		r->rch=p->rch;
		delete p;
		return r;
	}
	return p;
} 

int main(){
	node *p=NULL;
	node *p1=insert(p,7);
	cout<<p1->val;
	node *p2=insert(p1,2);
	cout<<p2->val;
	node *p3=insert(p1,5);
	cout<<p3->val<<endl;
	cout<<find(p1,2)<<endl;
	node *p4=remove(p1,2);
	cout<<p4->val<<endl;
	cout<<find(p1,2)<<endl;
	return 0;
}

//c++里，set和map使用二叉搜索树实现的 
