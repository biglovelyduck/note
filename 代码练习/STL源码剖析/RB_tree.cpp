
//RB_tree,节点分为两层
typedef bool __rb_tree_color_type;
const __rb_tree_color_type __rb_tree_red=false;
const __rb_tree_color_type __rb_tree_black=true;

//红黑树节点基类 
struct __rb_tree_node_base{
	typedef __rb_tree_color_type color_type;
	typedef __rb_tree_node_base* base_ptr;			//指向节点的基类指针 
	
	color_type color;			//节点颜色，非黑即红 
	base_ptr parent;			//RB_tree的很多操作，必须知道父结点 
	base_ptr left;				//指向左子节点
	base_ptr right;				//指向右子节点
	
	static base_ptr minimum(base_ptr x){
		while(x->left!=0) x=x->left;
		return x;
	}
	static base_ptr maximum(base_ptr x){
		while(x->right!=0) x=x->right;
		return x; 
	} 
};

//红黑树节点类
template <class Value>
struct __rb_tree_node:public __rb_tree_node_base{
	typedef __rb_tree_node<Value>* link_type;
	Value value_field;//节点的数值 
}; 

//基层迭代器
struct __rb_tree_base_iterator{
	typedef __rb_tree_node_base::base_ptr base_ptr;		//首先肯定得有一个指向节点的指针类型呀 
	typedef bidirectional_iterator_tag iterator_category; 	//迭代器策略的类型呀
	typedef ptrdiff_t difference_type;		//迭代器间距类型呀 
	base_ptr node;		//它与容器之间用来产生一个连结关系
	
	//以下可实现与operator++内，因为再无他处可以调用此函数了 
	void increment(){
		if(node->right!=0){
			//有右子结点，状况1,就左子树走到底 
			node=node->right;
			while(node->left!=0)
				node=node->left; 
		}
		else{
			//没有右子结点，状态2
			base_ptr y=node->parent;
			while(node==y->right){//如果现行节点本身就是个右子节点就不停的上溯直到不是 
				node=y;
				y=y->parent; 
			}
			if(node->right!=y)//状况3，不是右子节点只能是左子节点 
				node=y; 
		} 
	}
	//以下实现可实现于operator--() 
	void decrement(){
		//如果是红节点，且父结点的父结点等于自己，状况1，右子节点即为解答 
		//这种情况发生于node为header时，亦即node为end()时 
		if(node->color==__rb_tree_red&&node->parent->parent==node)
			node=node->right;
		//如果有左子节点，状况2，从左子节点出发一直找右子节点，走到头即为答案 
		else if(node->left!=0){
			base_ptr y=node->left;
			while(y->right!=0){
				y=y->right;
			}
			node=y;
		}
		//既非根结点，又无左子节点,状况3 
		else{
			base_ptr y=node->parent;
			while(node==y->left){
				//一直交替向上走，直到现行节点不为左子节点 
				node=y;
				y=y->parent; 
			}
			node=y;	//此时父结点即为答案 
		} 
	}
}; 

//RB_tree的正规迭代器,继承了父类的node那个变量 
template<class Value,class Ref,class Ptr>
struct __rb_tree_iterator:public __rb_tree_base_iterator{
	typedef Value value_type;
	typedef Ref reference;
	typedef Ptr pointer;
	typedef __rb_tree_iterator<Value,Value&,Value*> iterator;
	typedef __rb_tree_iterator<Value,const Value&,const Value*> const_iterator;
	typedef __rb_tree_iterator<Value,Ref,Ptr> self;		//标示自身 
	typedef __rb_tree_node<Value>* link_type;
	
	//构造函数 
	__rb_tree_iterator(){}
	__rb_tree_iterator(link_type x){node=x;}
	__rb_tree_iterator(const iterator& it){node=it.node;}
	
	//运算符重载
	reference operator*() const{
		return link_type(node)->value_field;
	}
	#ifndef __SGI_STL_NO_ARROW_OPERATOR
	pointer operator->() const{return &(operator*());}
	#endif
	
	//前置 ,++是单目运算符 
	self& operator++(){
		increment();
		return *this;
	}
	//后置 
	self operator++(int){
		self tmp=*this;
		increment();
		return *this;
	} 
	self& operator--(){
		decrement();
		return *this;
	}
	self operator--(int){
		self tmp=*this;
		decrement();
		return tmp;
	}
}; 

//左旋操作,新节点必须为红节点，如果插入处父节点也是红节点，就违反规则，需要旋转以及颜色改变 
inline void
__rb_tree_rotate_left(__rb_tree_node_base* x,__rb_tree_node_base*& root){
	//x为左旋点
	__rb_tree_node_base* y=x->right; //另y为旋转点的柚子节点
	x->right=y->left; 
	if(y->left!=0){
		y->left->parent=x;
	}
	y->parent=x->parent;
	//让y完全顶替x的地位（必须将x对其父节点的关系完全接收过来 
	if(x==root)
		root=y;
	else if(x==x->parent->left){
		x->parent->left=y;
	}
	else
		x->parent->right=y;
	y->left=x;
	x->parent=y;
}
//右旋操作 
inline void 
__rb_tree_rotate_right(__rb_tree_node_base* x,__rb_tree_node_base*& root){
	//略啦，和左旋类似，反过来	
}

//调整红黑树,旋转以及改变颜色 ,全局函数，参数1为新增结点，参数2为root
inline void
__rb_tree_rebalance(__rb_tree_node_base* x,__tb_tree_node_base* &root){
	//新节点必须为红
	x->color=__rb_tree_red;	//新节点必须为红
	while(x!=root&&x->parent->color=__rb_tree_red){
		//父节点为红
		//父节点为祖父结点的左子结点
		if(x->parent==x->parent->parent->left){
			__rb_tree_node_base* y=x->parent->parent->right;	//y为伯父节点
			//伯父存在且为红 ，对应状况3 4 
			if(y&&y->color==__rb_tree_red){
				x->parent->color=__rb_tree_black;	//更改父亲节点为黑
				x->parent->color=__rb_tree_black;	//更改伯父节点为黑
				x->parent->parent->color=__rb_tree_red;//更改祖父节点为红 
				x=x->parent->parent;	//x继续向上走 
			}
			//无伯父结点，或者伯父节点为黑  对应状况1 2 
			else{
				//如果新节点为父结点的右子节点 
				if(x==x->parent->right){
					//需要先左旋 
					x=x->parent;
					__rb_tree_rotate_left(x,root);	//第一参数为左旋点 
				}
				//如果新节点是父节点的左子结点就直接右旋 
				x->parent->color=__rb_tree_black;
				x->parent->parent->color=__rb_tree_red;
				__rb_tree_rotate_right(x->parent->parent,root);	//第一参数为右旋点 
			} 
		} 
		//父节点为祖父结点的右子节点 
		else{
			__rb_tree_node_base* y=x->parent->parent->left;
			if(y&&y->color==__rb_tree_red){	//有父节点且为红 
				x->parent->color=__rb_tree_black;	//更改父亲节点为黑
				x->parent->color=__rb_tree_black;	//更改伯父节点为黑
				x->parent->parent->color=__rb_tree_red;//更改祖父节点为红 
				x=x->parent->parent;	//x继续向上走 ,往上层检查 
			} 
			//无伯父节点或者伯父为黑 
			else{
				//如果新节点为父节点的左子节点 
				if(x==x->parent->left){
					//需要先右旋 
					x=x->parent;
					__rb_tree_rotate_right(x,root);
				}
				//如果是右子节点就直接左旋并且改变颜色
				x->parent->color=__rb_tree_black;
				x->parent->parent->color=__rb_tree_red;
				__rb_tree_rotate_left(x->parent->parent,root); 
			} 
		}
	}//while结束
	root->color=__rb_tree_black;	//根节点永远为黑 
} 

//RB_tree的数据结构
template <class Key,class value,class KeyOfValue,class Compare,class Alloc=alloc>
class rb_tree{
protected:
	//定义几个类型 
	typedef void* void_pointer;
	typedef __rb_tree_node_base* base_ptr;
	typedef __rb_tree_node<Value> rb_tree_node;
	typedef simple_alloc<rb_tree_node,Alloc> rb_tree_node_allocator;	//专属的空间配置器 
	typedef __rb_tree_color_type color_type;
public:
	typedef Key key_type;
	typedef Value value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef rb_tree_node* link_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
protected:
	link_type get_node(){return rb_tree_node_allocator::allocate();} 			//分配一个节点的空间 
	void put_node(link_type p){return rb_tree_node_allocator::deallocate(p);}	//删除一个节点的空间 
	//创建一个节点，但没有插在树上 
	link_type create_node(const value_type& x){
		link_type tmp=get_node();	//配置空间 
		__STL_TRY{
			construct(&tmp->value_field,x);	//用x来赋给我自己的值 
		} 
		__STL_UNWIND(put_node(tmp));
		return tmp;
	}
	//复制一个节点（值和颜色）
	link_type clone_node(link_type x){
		link_type tmp=create_node(x->value_field);
		tmp->color=x->color;
		tmp->left=0;
		tmp->right=0;
		return tmp;
	}
	//销毁一个节点
	void destroy_node(link_type p){
		destroy(&p->value_field);	//析构 
		put_node(p); 				//删除空间 
	} 
protected:
	//RB_tree只以三笔数据实现 
	size_type node_count;	//追踪记录树的大小（结点数量)
	link_type header;	//这是实现上的小技巧，为根结点设计了一个父节点
						//header和root互为对方的父节点 
	Compare key_compare; //节点间的键值大小比较准则，应该会是个function object 
	//以下三个函数用来方便的去的headet成员
	link_type& root() const {return (link_type&)header->parent;}
	link_type& leftmost() const {return (link_type&)header->left;}
	link_type& rightmost() const{return (link_type&)header->right;}
	//以下六个函数用来方便取得节点x的成员
	static link_type& left(link_type x){	//此link_type是__rb_tree_node* 
		return (link_type&)(x->left); 
	} 
	static link_type& right(link_type x){
		return (link_type&)(x->right);
	}
	static link_type& parent(link_tye x){
		return (link_type&)(x->parent);
	}
	static link_tpye& value(link_type x){
		return x->value_field;
	}
	static const Key& key(link_type x){
		return KeyOfValue()(value(x));		//函数对象 
	}
	static color_type& color(link_type x){
		return (color_type&)(x->color);
	}
	//以下六个函数用来方便取得节点x的成员
	static link_type left(base_ptr x){		//此base_ptr是_rb_tree_base_node* 
		return (link_type&)(x->left);
	} 
	static link_type& right(base_ptr x){
		return (link_type&)(x->right);
	}
	static link_type& parent(base_ptr x){
		return (link_type&)(x->parent);
	}
	static link_tpye& value(base_ptr x){
		return ((link_type)x)->value_field;
	}
	//返回键的值，该结点的值 
	static const Key& key(base_ptr x){
		return KeyOfValue()(value(link_type(x)));		//函数对象 
	}
	static color_type& color(base_ptr x){
		return (color_type&)(link_type(x)->color);
	}
	//求取极大值和极小值，node class有实现此功能，交给他们完成 
	static link_type minimum(link_tpye x){
		return (link_type) __rb_tree_node_base::minimum(x); 
	}
	static link_type maxinum(link_type x){
		return (link_type) __rb_tree_node_base::maximum(x);
	}
public:
	typedef __rb_tree_iterator<value_type,reference,pointer> iterator;
	
private:
	iterator __insert(base_ptr x,base_ptr y,const value_type& v);
	iterator find(const Key& k);
	link_type __copy(link_type x,link_type p);
	void __erase(link_type x);
	void init(){
		header=get_node();	//产生一个节点空间，令header指向它
		color(header)=__rb_tree_red; 	//令header为红色,用来区分header和root 
		root()=0;
		leftmost()=header;	//令header的左子节点为自己 
		rightmost()=header;
	}
public:
	//allocation/deallocation
	rb_tree(const Compare& comp=Compare()):node_count(0),key_compare(comp){
		init();	//是实现技巧的一个关键点 
	}
	~rb_tree(){
		clear();
		put_node(hearder);
	}
	rb_tree<Key,Value,KeyOfValue,Compare,Alloc>&
	operator=(const rb_tree<Key,Value,KeyOfValue,Compare,Alloc>& x);

public: 
	Compare key_comp() const{return key_compare;}
	iterator begin(){return leftmost();}//红黑树的起点为最左（最小）节点处 
	iterator end(){return header;}//红黑树的终点是header所指处
	bool empty() const{return node_count==0;} 
	size_type size() const{return node_count;}
	size_type max__size() const{return size_type(-1);}
	
public:
	//insert/erase
	//将x插入到 红黑树，保持节点值独一无二
	pair<iterator,bool> insert_unique(const value_type& x);
	//将x插入到红黑树中，允许节点值重复
	iterator insert_equal(const value_type& x);
	//... 
};

//元素插入操作
//插入新值，允许重复，返回一个RB_tree迭代器，指向新增结点
template<class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,ComPare,Alloc>::insert_equal(const Value& v){
	link_type y=header;
	link_type x=root();	//从根结点开始
	while(x!=0){
		//从根结点开始，往下寻找适当的插入点
		y=x;
		x=key_compare(KeyOfValue()(v),key(x))?left(x):right(x); 
		//遇大则左，遇小则右 
	}
	return __insert(x,y,v);//x为新值插入点，y为插入点的父节点，v为新值 
}
//元素插入操作，不允许值重复
template<class Key,class Value,class KeyOfValue,class Compare,class Alloc>
pair<typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator,bool>
rb_tree<Key,Value,KeyOfValue,ComPare,Alloc>::insert_unique(const Value& v){
	link_type y=header;
	link_type x=root();	//从根节点开始
	bool comp=true;
	while(x!=0) {
		y=x;
		comp=key_compare(KeyOfValue()(v),key(x)); 
		x=comp?left(x):right(x);//往下寻找适当的插入点 ，遇大则左，遇小则右 
	}
	//离开while，y所指即加入点的父节点
	iterator j=iterator(y);
	if(comp)	//为真，表示遇到x大，插入左侧
		if(j==begin()) //如果插入点的父节点为最左节点
			return pair<iterator,bool>(__insert(x,y,v),true); 	//构造pair对象 
	 	else	//插入点的父节点不为最左结点 
			--j;//调整j，回头准备测试
	if(key_compare(key(j.node),KeyOfValue()(v)));
		//表示小于新值，遇小，将插入右侧 
		return pair<iterator,bool>(__insert(x,y,v),true);
	//进行至此，表示新值一定与树中键值重复，那么就不该插入新值
	return pair<iterator,bool>(j,false);
}

//真正的插入执行程序
template <class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::__insert(base_ptr x_,base_ptr y_,const Value& v){
	//参数x为新值插入点，y为插入点父节点，v为新值 
	link_type x=(link_type)x_;
	link_type y=(link_type)y_;
	link_type z;
	//key_compare是键值大小比较准则,y的值大 
	if(y==header||x!=0||key_compare(KeyOfValue()(v),key(y))){
		z=create_node(v);	//产生一个新节点
		left(y)=z; 	//当y为header的时候，使得z为最左结点 
		if(y==header){
			root()=z;
			rightmost()=z;
		}
		else if(y==leftmost()) //如果y是最左结点 
			leftmost()=z; 
	}
	else	//y的值小
	{
		z=create_node(v);
		right(y)=z;	//另新节点成为插入节点的右子节点
		if(y==rightmost()) 
			rightmost()=z;
	}
	parent(z)=y;
	left(z)=0;
	right(z)=0;
	//设置新节点的颜色
	__rb_tree_rebalance(z,header->parent);	//参数1为新增节点，参数2为root
	++node_count;
	return iterator(z); 
} 

//查找元素
template <class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::find(const Key& k){
	link_type y=header;		//last node which is not less than k
	link_type x=root();		//current node
	while(x!=0){
		//key_compare是一个节点键值大小比较准则
		if(!key_compare(key(x),k))
			//x>k或者x=k 
			y=x,x=left(x); 
		else
			//x<k
			x=right();
	}
	iterator j=iterator(y);
	return (j==end()||key_compare(k,key(j.node)))?end():j;
}

