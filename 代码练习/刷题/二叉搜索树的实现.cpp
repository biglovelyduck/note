/*��������������ʵ��*/
//ɾ�������
//1.��Ҫɾ���Ľ��û������ӣ���ô�Ͱ��Ҷ�������ȥ
//2.��Ҫɾ���Ľ��������û���Ҷ��ӣ���ô�Ͱ����������ȥ
//3.�������������������Ļ����Ͱ�����ӵ����������Ľ���ᵽ��Ҫɾ���Ľ���λ��
#include <iostream>
using namespace std;
struct node{
	int val;
	node *lch,*rch;
}; 

//������ֵx,pΪ������ڵ㿪ʼ���� 
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

//������ֵx
bool find(node *p,int x){
	if(p==NULL) return false;
	else if(x==p->val) return true;
	else if(x<p->val)	return find(p->lch,x); 
	else return find(p->rch,x);
}

//ɾ����ֵx
node *remove(node *p,int x){
	if(p==NULL) return NULL;
	else if(x<p->val) p->lch=remove(p->lch,x);
	else if(x>p->val) p->rch=remove(p->rch,x);
	else if(p->lch==NULL){
		//���Ҷ�������ȥ
		node *q=p->rch;
		delete p;
		return q; 
	}
	else if(p->lch->rch==NULL){
		//�����������ȥ
		node *q=p->lch;
		q->rch=p->rch;
		delete p;
		return q; 
	}
	else{
		//�����������������ȥ
		node *q;
		for(q=p->lch;q->rch->rch!=NULL;q=q->rch);
		node *r=q->rch;//������� 
		q->rch=r->lch;//q������������r�������� 
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

//c++�set��mapʹ�ö���������ʵ�ֵ� 
