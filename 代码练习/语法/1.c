//´«²Îchar**ºÍchar*& 
#include <stdio.h>
typedef struct node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node n;
void fun(Node **n){
	printf("%d\n",n);
}
Node *n;
void fun1(Node * &n){
	printf("%d\n",n);
}
void fun2(Node &n){
	printf("%d\n",n);
}
void fun3(Node *n){
	printf("%d\n",n);
}
int main(){
	Node n1;
	Node* n2;
	printf("%d\n",n2);
	fun(n2);
	fun1(n2);
	return 0;
}
