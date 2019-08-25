//二叉树中节点的最大距离 
struct Node{
	int val;
	Node *l,*r;
};

struct Result{
	int maxDistance;	//最大距离
	int maxDepth;		//最大深度，最大距离和最大深度有关系 
}; 

Result getMax(Node* root){
	if(!root){
		Result empty={0,-1};	//最大深度初始化为-1，因为调用者要对其加1 
		return empty;
	} 
	Result lhs=getMax(root->l);
	Result rhs=getMax(root->r);
	Result result;
	result.maxDepth=max(lhs.maxDepth+1,rhs.maxDepth+1);
	result.maxDistance=max(max(lhs.maxDistance,rhs.maxDistance),lhs.maxDepth+rhs.maxDepth+2);
	return result; 
}
