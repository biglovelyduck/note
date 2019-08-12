#include <iostream>
#include <cstdlib>

/*二叉树实现*/
#define BinNodePosi(T) BinNode<T>*//结点位置
#define stature(p) ((p)?(p)->height:-1)//结点高度，与空树高度-1约定统一

/******************************************************************************************
 * BinNode状态与性质的判断 
 ******************************************************************************************/
 #define IsRoot(x) (!((x).parent))
 #define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
 #define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
 #define HasParent(x) (!IsRoot(x))
 #define HasLChild(x) ((x).lChild)
 #define HasRChild(x) ((x).rChild)
 #define HasChild(x) (HasLChild(x) || HasRChild(x)) //至少拥有一个孩子
 #define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
 #define IsLeaf(x) (!HasChild(x))
 
/******************************************************************************************
* 与BinNode具有特定关系的节点及指针
******************************************************************************************/
#define sibling(p) (IsLChild(*(p))?(p)->parent->rChild:(p)->parent->lChild) //兄弟

#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rChild : (x)->parent->parent->lChild) //叔叔

#define FromParentTo(x) ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lChild : (x).parent->rChild)) //来自父亲癿指针

typedef enum{
	RB_RED,RB_BLACK
}RBColor;//结点颜色 

//二叉树结点类 
template <typename T> 
struct BinNode{
	BinNodePosi(T) parent,lChild,rChild;
	T data;int height;int size();//结点所处的高度 
	int npl;//左式堆，也可以用height代替
	RBColor color; 
	//构造函数
	BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),npl(1),color(RB_RED){}
	BinNode(T e,BinNodePosi(T) p=NULL,BinNodePosi(T) lc=NULL,BinNodePosi(T) rc=NULL,
	int h=0,int l=1,RBColor c=RB_RED):data(e),parent(p),lChild(lc),rChild(rc),
	height(h),npl(l),color(c){}
	//操作接口
	BinNodePosi(T) insertAsLC(T const &);//作为左孩子插入新结点
	BinNodePosi(T) insertAsRC(T const &);
	BinNodePosi(T) succ();//中序遍历意义下，当前结点的直接后继
	template <typename VST> void travLevel(VST &);//子树层次遍历
	template <typename VST> void tracPre(VST &);//先序遍历
	template <typename VST> void travIn(VST &);//中序遍历
	template <typename VST> void travPost(VST &);//后序遍历 
	//比较器，判等器
	bool operator<(BinNode const& bn){
		return data<bn.data;
	} 
	bool operator==(BinNode const& bn){
		return data==bn.data;
	}
};

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e){
	return lChild=new BinNode(e,this);
}
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e){
	return rChild=new BinNode(e,this);
}

template <typename T>
int BinNode<T>::size(){//子树的规模 
	int s=1;//计入本身 
	if(lChild) s+=lChild->size();
	if(rChild) s+=rChild->size();
	return s;
}

//操作器
template <typename T> template <typename VST>//元素类型，操作器
void BinNode<T>::travIn(VST &visit){//二叉树遍历算法统一入口 
	switch(rand()%5){
		case 1:	travIn_I1(this,visit);break;
		case 2: travIn_I2(this, visit); break; //迭代版#2
		case 3: travIn_I3(this, visit); break; //迭代版#3
		case 4: travIn_I4(this, visit); break; //迭代版#4
		default: travIn_R(this, visit); break; //递归版
	} 
} 

//二叉树模板类 
template <typename T>
class BinTree{
protected:
	int _size;//规模
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x);//更新结点x的高度
	void updateHeightAbove(BinNodePosi(T) x);//更新结点x及其祖先的高度
public:
	BinTree():_size(0),_root(NULL){}
	~BinTree(){
		if(0<_size) remove(_root);
	}
	int size() const{return _size;}
	bool empty() const{return !_root;} 
	BinNodePosi(T) root() const{return _root;}
	BinNodePosi(T) insertAsRoot(T const &e);//插入根结点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const &e);//e作为x的左孩子 
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const &e);//e作为x的右孩子 
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &S);//T作为x的左子树插入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &S);//T作为x的右子树插入 
	int remove(BinNodePosi(T) x) ;//删除位置x处结点为根的子树，返回子树原先的规模
	BinTree<T>* secede(BinNodePosi(T) x);//将子树x摘除，并转换为一棵独立子树
	template <typename VST>
	void travLevel(VST& visit){
		if(_root) _root->travLevel(visit);//层次遍历 
	} 
	template <typename VST>
	void travPre(VST& visit) { if (_root) _root->travPre(visit); } //先序遍历
	template <typename VST> //操作器
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //中序遍历
	template <typename VST> //操作器
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //后序遍历
	// 比较器、刞等器（各列其一，其余自行补充）
	bool operator<(BinTree<T> const& t) { return _root && t._root && lt(_root, t._root); }
	bool operator==(BinTree<T> const& t) { return _root && t._root && (_root == t._root); }
}; 

template <typename T> 
int BinTree<T>::updateHeight(BinNodePosi(T) x) //更新节点x高度
{ return x->height = 1 + max(stature(x->lChild), stature(x->rChild)); } //具体规则因树而异 
template <typename T> 
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //更新v及祖先的高度
{ while (x) { updateHeight(x); x = x->parent; } } //可优化：一旦高度未发，即可终止

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{ _size = 1; return _root = new BinNode<T>(e); } 

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lChild; } 

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rChild; } 

//子树插入
template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) { //x->lChild == NULL
	if (x->lChild = S->_root) x->lChild->parent = x; //接入
	_size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //释放原树，返回接入位置
}

template <typename T> //二叉树子树接入算法：将S弼作节点x癿右子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) { //x->rChild == NULL
	if (x->rChild = S->_root) x->rChild->parent = x; //接入
	_size += S->_size; updateHeightAbove(x); //更新全树觃模不x所有祖先癿高度
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //释放原树，迒回接入位置
} 

//子树删除
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点规模的数值
int BinTree<T>::remove(BinNodePosi(T) x) { //assert: x为二叉树中的合法位置
	FromParentTo(*x) = NULL; //切断来自父节点的指针
	updateHeightAbove(x->parent); //更新祖先高度
	int n = removeAt(x); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
}

template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点规模的数值
static int removeAt(BinNodePosi(T) x) { //assert: x为二叉树中癿合法位置
	if (!x) return 0; //递归基：空树
	int n = 1 + removeAt(x->lChild) + removeAt(x->rChild); //递归释放左、右子树
	release(x->data); release(x); return n; //释放被摘除节点，并返回删除节点总数
}

//子树分离 
template <typename T> //二叉树子树分离算法：将子树x从弼前树中摘除，将其封装为一棵独立子树迒回
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) { //assert: x为二叉树中癿合法位置
	FromParentTo(*x) = NULL; //切断来自父节点癿指针
	updateHeightAbove(x->parent); //更新原树中所有祖先癿高度
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
	S->_size = x->size(); _size -= S->_size; return S; //更新觃模，迒回分离出来癿子树
}

//先序遍历
template <typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	visit(x->data);
	travPre_R(x->lChild,visit);
	travPre_R(x->rChild,visit);
} 
//迭代版先序遍历
template <typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,Stack<BinNodePosi(T)>& S){
	while(x){
		visit(x->data);
		S.push(x->rChild);
		x=x->lChild; 
	}
} 
template <typename T, typename VST> //元素类型、操作器
void travPre_I2(BinNodePosi(T) x, VST& visit) { //二叉树先序遍历算法（迭代版#2）
	Stack<BinNodePosi(T)> S; //辅劣栈
	while (true) {
		visitAlongLeftBranch(x, visit, S); //从弼前节点出収，逐批讵问
		if (S.empty()) break; //直刡栈空
		x = S.pop(); //弹出下一批癿起点
	}
}
//后序遍历
template <typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	travPost_R(x->lChild,visit);
	travPost_R(x->rChild,visit);
	visit(x->data);
} 
//中序遍历
template <typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	travIn_R(x->lChild,visit);
	visit(x->data);
	travIn_R(x->rChild,visit);	
}
//中序遍历迭代实现
template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x,Stack<BinNodePosi(T)> &S){
	while(x){
		S.push(x);
		x=x->lChild;
	}
}
template <typename T,typename V>
void travIn_I1(BinNodePosi(T) x,V& visit){
	Stack<BinNodePosi(T)> S;
	while(true){
		goAlongLeftBranch(x,S);
		if(S.empty()) break;
		x=S.pop();
		visit(x->data);
		x=x->rChild;
	}
}

//层次遍历
template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST &visit){
	Queue<BinNodePosi(T)> Q;
	Q.enqueue(this);//根结点入队
	while(!Q.empty()) {
		BinNodePosi(T) x=Q.dequeue();
		visit(x->data);
		if(HasLChild(*x)) Q.enqueue(x->lChild);
		if(HasRChild(*X)) Q.enqueue(x->rChild);
	}
} 
