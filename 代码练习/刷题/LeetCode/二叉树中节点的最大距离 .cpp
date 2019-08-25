//�������нڵ�������� 
struct Node{
	int val;
	Node *l,*r;
};

struct Result{
	int maxDistance;	//������
	int maxDepth;		//�����ȣ���������������й�ϵ 
}; 

Result getMax(Node* root){
	if(!root){
		Result empty={0,-1};	//�����ȳ�ʼ��Ϊ-1����Ϊ������Ҫ�����1 
		return empty;
	} 
	Result lhs=getMax(root->l);
	Result rhs=getMax(root->r);
	Result result;
	result.maxDepth=max(lhs.maxDepth+1,rhs.maxDepth+1);
	result.maxDistance=max(max(lhs.maxDistance,rhs.maxDistance),lhs.maxDepth+rhs.maxDepth+2);
	return result; 
}
