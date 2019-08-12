#include <iostream>
#include <ctring>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Node{
	bool have_value;//�Ƿ񱻸�ֵ��
	int v;//����ֵ
	Node* left,right;//���Һ���ָ�� 
	Node():have_value(false),left(NULL),right(NULL){}//���캯�� 
};

Node* root;

Node* newnode(){
	return new Node();
} 

void addnode(int v,char* s){
	int n=strlen(s);
	Node* u=root;
	for(int i=0;i<n;i++){//������ȡs����ַ� 
		if(s[i]=='L'){
			if(u->left==NULl) u->left=newnode();
			u=u->left;//������ 
		}
		else if(s[i]=='R'){
			if(u->right==NULL) u->right=newnode(); 
			u=u->right;
		}
		if(u.have_value) failed=true;//�Ѿ�����ֵ���������� 
		u->v=v;
		u->have_value=true;//����� 
	} 
}

char s[maxn];
bool read_input(){
	failed=false;//������������ 
	root=new Node();//���������
	for(;;){
		if(scanf("%s",s)!=1) return false;//�����������
		if(!strcmp(s,"()")) break;//����������־���˳�ѭ��
		int v;
		sscanf(&s[1],"%d",v);//ͨ���ַ�����ȡ������ֵ.&s[1]��Ӧ���ַ����ǡ�11��LL�� 
		addnode(v,strchr(s,',')+1);//strchr(s,',')+1����s�е�һ�γ��֡�������ָ�룬�����ǡ�LL�� 
	} 
}

//ʹ�ö��б���������
bool dfs(vector<int>& ans) {//ansΪ�������
queue<Node*> q;//q�д��ָ��Node��ָ�� ,�����а����ж� 
ans.clear();
q.push(root);//����������� 
while(!q.empty()){
	Node* u=q.front();//ȡ������Ԫ�� 
	q.pop();
	if(!u->have_value) return false;//��ʼ��ֵʧ�ܣ��õ�û�б���ֵ��������������
	ans.push_back(u->v);
	if(u->left!=NULL) q.push(u->left);
	if(u->right!=NULL) q.push(u->right); 
}
return true;
}

int main(int argc, char** argv) {
	return 0;
}
