#include <iostream>
#include <cstdlib>

/*������ʵ��*/
#define BinNodePosi(T) BinNode<T>*//���λ��
#define stature(p) ((p)?(p)->height:-1)//���߶ȣ�������߶�-1Լ��ͳһ

/******************************************************************************************
 * BinNode״̬�����ʵ��ж� 
 ******************************************************************************************/
 #define IsRoot(x) (!((x).parent))
 #define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
 #define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
 #define HasParent(x) (!IsRoot(x))
 #define HasLChild(x) ((x).lChild)
 #define HasRChild(x) ((x).rChild)
 #define HasChild(x) (HasLChild(x) || HasRChild(x)) //����ӵ��һ������
 #define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //ͬʱӵ����������
 #define IsLeaf(x) (!HasChild(x))
 
/******************************************************************************************
* ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
******************************************************************************************/
#define sibling(p) (IsLChild(*(p))?(p)->parent->rChild:(p)->parent->lChild) //�ֵ�

#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rChild : (x)->parent->parent->lChild) //����

#define FromParentTo(x) ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lChild : (x).parent->rChild)) //���Ը��װmָ��

typedef enum{
	RB_RED,RB_BLACK
}RBColor;//�����ɫ 

//����������� 
template <typename T> 
struct BinNode{
	BinNodePosi(T) parent,lChild,rChild;
	T data;int height;int size();//��������ĸ߶� 
	int npl;//��ʽ�ѣ�Ҳ������height����
	RBColor color; 
	//���캯��
	BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),npl(1),color(RB_RED){}
	BinNode(T e,BinNodePosi(T) p=NULL,BinNodePosi(T) lc=NULL,BinNodePosi(T) rc=NULL,
	int h=0,int l=1,RBColor c=RB_RED):data(e),parent(p),lChild(lc),rChild(rc),
	height(h),npl(l),color(c){}
	//�����ӿ�
	BinNodePosi(T) insertAsLC(T const &);//��Ϊ���Ӳ����½��
	BinNodePosi(T) insertAsRC(T const &);
	BinNodePosi(T) succ();//������������£���ǰ����ֱ�Ӻ��
	template <typename VST> void travLevel(VST &);//������α���
	template <typename VST> void tracPre(VST &);//�������
	template <typename VST> void travIn(VST &);//�������
	template <typename VST> void travPost(VST &);//������� 
	//�Ƚ������е���
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
int BinNode<T>::size(){//�����Ĺ�ģ 
	int s=1;//���뱾�� 
	if(lChild) s+=lChild->size();
	if(rChild) s+=rChild->size();
	return s;
}

//������
template <typename T> template <typename VST>//Ԫ�����ͣ�������
void BinNode<T>::travIn(VST &visit){//�����������㷨ͳһ��� 
	switch(rand()%5){
		case 1:	travIn_I1(this,visit);break;
		case 2: travIn_I2(this, visit); break; //������#2
		case 3: travIn_I3(this, visit); break; //������#3
		case 4: travIn_I4(this, visit); break; //������#4
		default: travIn_R(this, visit); break; //�ݹ��
	} 
} 

//������ģ���� 
template <typename T>
class BinTree{
protected:
	int _size;//��ģ
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x);//���½��x�ĸ߶�
	void updateHeightAbove(BinNodePosi(T) x);//���½��x�������ȵĸ߶�
public:
	BinTree():_size(0),_root(NULL){}
	~BinTree(){
		if(0<_size) remove(_root);
	}
	int size() const{return _size;}
	bool empty() const{return !_root;} 
	BinNodePosi(T) root() const{return _root;}
	BinNodePosi(T) insertAsRoot(T const &e);//��������
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const &e);//e��Ϊx������ 
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const &e);//e��Ϊx���Һ��� 
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &S);//T��Ϊx������������
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &S);//T��Ϊx������������ 
	int remove(BinNodePosi(T) x) ;//ɾ��λ��x�����Ϊ������������������ԭ�ȵĹ�ģ
	BinTree<T>* secede(BinNodePosi(T) x);//������xժ������ת��Ϊһ�ö�������
	template <typename VST>
	void travLevel(VST& visit){
		if(_root) _root->travLevel(visit);//��α��� 
	} 
	template <typename VST>
	void travPre(VST& visit) { if (_root) _root->travPre(visit); } //�������
	template <typename VST> //������
	void travIn(VST& visit) { if (_root) _root->travIn(visit); } //�������
	template <typename VST> //������
	void travPost(VST& visit) { if (_root) _root->travPost(visit); } //�������
	// �Ƚ������`������������һ���������в��䣩
	bool operator<(BinTree<T> const& t) { return _root && t._root && lt(_root, t._root); }
	bool operator==(BinTree<T> const& t) { return _root && t._root && (_root == t._root); }
}; 

template <typename T> 
int BinTree<T>::updateHeight(BinNodePosi(T) x) //���½ڵ�x�߶�
{ return x->height = 1 + max(stature(x->lChild), stature(x->rChild)); } //��������������� 
template <typename T> 
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //����v�����ȵĸ߶�
{ while (x) { updateHeight(x); x = x->parent; } } //���Ż���һ���߶�δ����������ֹ

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{ _size = 1; return _root = new BinNode<T>(e); } 

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lChild; } 

template <typename T> 
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rChild; } 

//��������
template <typename T> //���������������㷨����S�����ڵ�x�����������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) { //x->lChild == NULL
	if (x->lChild = S->_root) x->lChild->parent = x; //����
	_size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶�
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //�ͷ�ԭ�������ؽ���λ��
}

template <typename T> //���������������㷨����S�����ڵ�x�m���������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) { //x->rChild == NULL
	if (x->rChild = S->_root) x->rChild->parent = x; //����
	_size += S->_size; updateHeightAbove(x); //����ȫ���_ģ��x�������Ȱm�߶�
	S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //�ͷ�ԭ����ކ�ؽ���λ��
} 

//����ɾ��
template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ��ģ����ֵ
int BinTree<T>::remove(BinNodePosi(T) x) { //assert: xΪ�������еĺϷ�λ��
	FromParentTo(*x) = NULL; //�ж����Ը��ڵ��ָ��
	updateHeightAbove(x->parent); //�������ȸ߶�
	int n = removeAt(x); _size -= n; return n; //ɾ������x�����¹�ģ������ɾ���ڵ�����
}

template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ��ģ����ֵ
static int removeAt(BinNodePosi(T) x) { //assert: xΪ�������аm�Ϸ�λ��
	if (!x) return 0; //�ݹ��������
	int n = 1 + removeAt(x->lChild) + removeAt(x->rChild); //�ݹ��ͷ���������
	release(x->data); release(x); return n; //�ͷű�ժ���ڵ㣬������ɾ���ڵ�����
}

//�������� 
template <typename T> //���������������㷨��������x����ǰ����ժ���������װΪһ�ö�������ކ��
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) { //assert: xΪ�������аm�Ϸ�λ��
	FromParentTo(*x) = NULL; //�ж����Ը��ڵ�mָ��
	updateHeightAbove(x->parent); //����ԭ�����������Ȱm�߶�
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //������xΪ��
	S->_size = x->size(); _size -= S->_size; return S; //�����_ģ��ކ�ط�������m����
}

//�������
template <typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	visit(x->data);
	travPre_R(x->lChild,visit);
	travPre_R(x->rChild,visit);
} 
//�������������
template <typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,Stack<BinNodePosi(T)>& S){
	while(x){
		visit(x->data);
		S.push(x->rChild);
		x=x->lChild; 
	}
} 
template <typename T, typename VST> //Ԫ�����͡�������
void travPre_I2(BinNodePosi(T) x, VST& visit) { //��������������㷨��������#2��
	Stack<BinNodePosi(T)> S; //����ջ
	while (true) {
		visitAlongLeftBranch(x, visit, S); //����ǰ�ڵ����������ڪ��
		if (S.empty()) break; //ֱ�bջ��
		x = S.pop(); //������һ���m���
	}
}
//�������
template <typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	travPost_R(x->lChild,visit);
	travPost_R(x->rChild,visit);
	visit(x->data);
} 
//�������
template <typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST &visit){
	if(!x) return;
	travIn_R(x->lChild,visit);
	visit(x->data);
	travIn_R(x->rChild,visit);	
}
//�����������ʵ��
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

//��α���
template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST &visit){
	Queue<BinNodePosi(T)> Q;
	Q.enqueue(this);//��������
	while(!Q.empty()) {
		BinNodePosi(T) x=Q.dequeue();
		visit(x->data);
		if(HasLChild(*x)) Q.enqueue(x->lChild);
		if(HasRChild(*X)) Q.enqueue(x->rChild);
	}
} 
