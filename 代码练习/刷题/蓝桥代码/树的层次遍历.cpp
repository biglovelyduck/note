#include <iostream>
#include <ctring>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Node{
	bool have_value;//是否被赋值过
	int v;//结点的值
	Node* left,right;//左右孩子指针 
	Node():have_value(false),left(NULL),right(NULL){}//构造函数 
};

Node* root;

Node* newnode(){
	return new Node();
} 

void addnode(int v,char* s){
	int n=strlen(s);
	Node* u=root;
	for(int i=0;i<n;i++){//挨个获取s里的字符 
		if(s[i]=='L'){
			if(u->left==NULl) u->left=newnode();
			u=u->left;//往左走 
		}
		else if(s[i]=='R'){
			if(u->right==NULL) u->right=newnode(); 
			u=u->right;
		}
		if(u.have_value) failed=true;//已经赋过值，输入有误 
		u->v=v;
		u->have_value=true;//做标记 
	} 
}

char s[maxn];
bool read_input(){
	failed=false;//假设输入无误 
	root=new Node();//创建根结点
	for(;;){
		if(scanf("%s",s)!=1) return false;//整个输入结束
		if(!strcmp(s,"()")) break;//读到结束标志，退出循环
		int v;
		sscanf(&s[1],"%d",v);//通过字符串读取到整数值.&s[1]对应的字符串是“11，LL” 
		addnode(v,strchr(s,',')+1);//strchr(s,',')+1返回s中第一次出现‘，’的指针，所以是“LL” 
	} 
}

//使用队列遍历整棵树
bool dfs(vector<int>& ans) {//ans为输出队列
queue<Node*> q;//q中存放指向Node的指针 ,出队列挨个判断 
ans.clear();
q.push(root);//根放入队列中 
while(!q.empty()){
	Node* u=q.front();//取出队首元素 
	q.pop();
	if(!u->have_value) return false;//初始赋值失败，该点没有被赋值，表明输入有误
	ans.push_back(u->v);
	if(u->left!=NULL) q.push(u->left);
	if(u->right!=NULL) q.push(u->right); 
}
return true;
}

int main(int argc, char** argv) {
	return 0;
}
