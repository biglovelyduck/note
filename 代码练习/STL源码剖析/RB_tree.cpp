
//RB_tree,�ڵ��Ϊ����
typedef bool __rb_tree_color_type;
const __rb_tree_color_type __rb_tree_red=false;
const __rb_tree_color_type __rb_tree_black=true;

//������ڵ���� 
struct __rb_tree_node_base{
	typedef __rb_tree_color_type color_type;
	typedef __rb_tree_node_base* base_ptr;			//ָ��ڵ�Ļ���ָ�� 
	
	color_type color;			//�ڵ���ɫ���Ǻڼ��� 
	base_ptr parent;			//RB_tree�ĺܶ����������֪������� 
	base_ptr left;				//ָ�����ӽڵ�
	base_ptr right;				//ָ�����ӽڵ�
	
	static base_ptr minimum(base_ptr x){
		while(x->left!=0) x=x->left;
		return x;
	}
	static base_ptr maximum(base_ptr x){
		while(x->right!=0) x=x->right;
		return x; 
	} 
};

//������ڵ���
template <class Value>
struct __rb_tree_node:public __rb_tree_node_base{
	typedef __rb_tree_node<Value>* link_type;
	Value value_field;//�ڵ����ֵ 
}; 

//���������
struct __rb_tree_base_iterator{
	typedef __rb_tree_node_base::base_ptr base_ptr;		//���ȿ϶�����һ��ָ��ڵ��ָ������ѽ 
	typedef bidirectional_iterator_tag iterator_category; 	//���������Ե�����ѽ
	typedef ptrdiff_t difference_type;		//�������������ѽ 
	base_ptr node;		//��������֮����������һ�������ϵ
	
	//���¿�ʵ����operator++�ڣ���Ϊ�����������Ե��ô˺����� 
	void increment(){
		if(node->right!=0){
			//�����ӽ�㣬״��1,���������ߵ��� 
			node=node->right;
			while(node->left!=0)
				node=node->left; 
		}
		else{
			//û�����ӽ�㣬״̬2
			base_ptr y=node->parent;
			while(node==y->right){//������нڵ㱾����Ǹ����ӽڵ�Ͳ�ͣ������ֱ������ 
				node=y;
				y=y->parent; 
			}
			if(node->right!=y)//״��3���������ӽڵ�ֻ�������ӽڵ� 
				node=y; 
		} 
	}
	//����ʵ�ֿ�ʵ����operator--() 
	void decrement(){
		//����Ǻ�ڵ㣬�Ҹ����ĸ��������Լ���״��1�����ӽڵ㼴Ϊ��� 
		//�������������nodeΪheaderʱ���༴nodeΪend()ʱ 
		if(node->color==__rb_tree_red&&node->parent->parent==node)
			node=node->right;
		//��������ӽڵ㣬״��2�������ӽڵ����һֱ�����ӽڵ㣬�ߵ�ͷ��Ϊ�� 
		else if(node->left!=0){
			base_ptr y=node->left;
			while(y->right!=0){
				y=y->right;
			}
			node=y;
		}
		//�ȷǸ���㣬�������ӽڵ�,״��3 
		else{
			base_ptr y=node->parent;
			while(node==y->left){
				//һֱ���������ߣ�ֱ�����нڵ㲻Ϊ���ӽڵ� 
				node=y;
				y=y->parent; 
			}
			node=y;	//��ʱ����㼴Ϊ�� 
		} 
	}
}; 

//RB_tree�����������,�̳��˸����node�Ǹ����� 
template<class Value,class Ref,class Ptr>
struct __rb_tree_iterator:public __rb_tree_base_iterator{
	typedef Value value_type;
	typedef Ref reference;
	typedef Ptr pointer;
	typedef __rb_tree_iterator<Value,Value&,Value*> iterator;
	typedef __rb_tree_iterator<Value,const Value&,const Value*> const_iterator;
	typedef __rb_tree_iterator<Value,Ref,Ptr> self;		//��ʾ���� 
	typedef __rb_tree_node<Value>* link_type;
	
	//���캯�� 
	__rb_tree_iterator(){}
	__rb_tree_iterator(link_type x){node=x;}
	__rb_tree_iterator(const iterator& it){node=it.node;}
	
	//���������
	reference operator*() const{
		return link_type(node)->value_field;
	}
	#ifndef __SGI_STL_NO_ARROW_OPERATOR
	pointer operator->() const{return &(operator*());}
	#endif
	
	//ǰ�� ,++�ǵ�Ŀ����� 
	self& operator++(){
		increment();
		return *this;
	}
	//���� 
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

//��������,�½ڵ����Ϊ��ڵ㣬������봦���ڵ�Ҳ�Ǻ�ڵ㣬��Υ��������Ҫ��ת�Լ���ɫ�ı� 
inline void
__rb_tree_rotate_left(__rb_tree_node_base* x,__rb_tree_node_base*& root){
	//xΪ������
	__rb_tree_node_base* y=x->right; //��yΪ��ת������ӽڵ�
	x->right=y->left; 
	if(y->left!=0){
		y->left->parent=x;
	}
	y->parent=x->parent;
	//��y��ȫ����x�ĵ�λ�����뽫x���丸�ڵ�Ĺ�ϵ��ȫ���չ��� 
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
//�������� 
inline void 
__rb_tree_rotate_right(__rb_tree_node_base* x,__rb_tree_node_base*& root){
	//���������������ƣ�������	
}

//���������,��ת�Լ��ı���ɫ ,ȫ�ֺ���������1Ϊ������㣬����2Ϊroot
inline void
__rb_tree_rebalance(__rb_tree_node_base* x,__tb_tree_node_base* &root){
	//�½ڵ����Ϊ��
	x->color=__rb_tree_red;	//�½ڵ����Ϊ��
	while(x!=root&&x->parent->color=__rb_tree_red){
		//���ڵ�Ϊ��
		//���ڵ�Ϊ�游�������ӽ��
		if(x->parent==x->parent->parent->left){
			__rb_tree_node_base* y=x->parent->parent->right;	//yΪ�����ڵ�
			//����������Ϊ�� ����Ӧ״��3 4 
			if(y&&y->color==__rb_tree_red){
				x->parent->color=__rb_tree_black;	//���ĸ��׽ڵ�Ϊ��
				x->parent->color=__rb_tree_black;	//���Ĳ����ڵ�Ϊ��
				x->parent->parent->color=__rb_tree_red;//�����游�ڵ�Ϊ�� 
				x=x->parent->parent;	//x���������� 
			}
			//�޲�����㣬���߲����ڵ�Ϊ��  ��Ӧ״��1 2 
			else{
				//����½ڵ�Ϊ���������ӽڵ� 
				if(x==x->parent->right){
					//��Ҫ������ 
					x=x->parent;
					__rb_tree_rotate_left(x,root);	//��һ����Ϊ������ 
				}
				//����½ڵ��Ǹ��ڵ�����ӽ���ֱ������ 
				x->parent->color=__rb_tree_black;
				x->parent->parent->color=__rb_tree_red;
				__rb_tree_rotate_right(x->parent->parent,root);	//��һ����Ϊ������ 
			} 
		} 
		//���ڵ�Ϊ�游�������ӽڵ� 
		else{
			__rb_tree_node_base* y=x->parent->parent->left;
			if(y&&y->color==__rb_tree_red){	//�и��ڵ���Ϊ�� 
				x->parent->color=__rb_tree_black;	//���ĸ��׽ڵ�Ϊ��
				x->parent->color=__rb_tree_black;	//���Ĳ����ڵ�Ϊ��
				x->parent->parent->color=__rb_tree_red;//�����游�ڵ�Ϊ�� 
				x=x->parent->parent;	//x���������� ,���ϲ��� 
			} 
			//�޲����ڵ���߲���Ϊ�� 
			else{
				//����½ڵ�Ϊ���ڵ�����ӽڵ� 
				if(x==x->parent->left){
					//��Ҫ������ 
					x=x->parent;
					__rb_tree_rotate_right(x,root);
				}
				//��������ӽڵ��ֱ���������Ҹı���ɫ
				x->parent->color=__rb_tree_black;
				x->parent->parent->color=__rb_tree_red;
				__rb_tree_rotate_left(x->parent->parent,root); 
			} 
		}
	}//while����
	root->color=__rb_tree_black;	//���ڵ���ԶΪ�� 
} 

//RB_tree�����ݽṹ
template <class Key,class value,class KeyOfValue,class Compare,class Alloc=alloc>
class rb_tree{
protected:
	//���弸������ 
	typedef void* void_pointer;
	typedef __rb_tree_node_base* base_ptr;
	typedef __rb_tree_node<Value> rb_tree_node;
	typedef simple_alloc<rb_tree_node,Alloc> rb_tree_node_allocator;	//ר���Ŀռ������� 
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
	link_type get_node(){return rb_tree_node_allocator::allocate();} 			//����һ���ڵ�Ŀռ� 
	void put_node(link_type p){return rb_tree_node_allocator::deallocate(p);}	//ɾ��һ���ڵ�Ŀռ� 
	//����һ���ڵ㣬��û�в������� 
	link_type create_node(const value_type& x){
		link_type tmp=get_node();	//���ÿռ� 
		__STL_TRY{
			construct(&tmp->value_field,x);	//��x���������Լ���ֵ 
		} 
		__STL_UNWIND(put_node(tmp));
		return tmp;
	}
	//����һ���ڵ㣨ֵ����ɫ��
	link_type clone_node(link_type x){
		link_type tmp=create_node(x->value_field);
		tmp->color=x->color;
		tmp->left=0;
		tmp->right=0;
		return tmp;
	}
	//����һ���ڵ�
	void destroy_node(link_type p){
		destroy(&p->value_field);	//���� 
		put_node(p); 				//ɾ���ռ� 
	} 
protected:
	//RB_treeֻ����������ʵ�� 
	size_type node_count;	//׷�ټ�¼���Ĵ�С���������)
	link_type header;	//����ʵ���ϵ�С���ɣ�Ϊ����������һ�����ڵ�
						//header��root��Ϊ�Է��ĸ��ڵ� 
	Compare key_compare; //�ڵ��ļ�ֵ��С�Ƚ�׼��Ӧ�û��Ǹ�function object 
	//���������������������ȥ��headet��Ա
	link_type& root() const {return (link_type&)header->parent;}
	link_type& leftmost() const {return (link_type&)header->left;}
	link_type& rightmost() const{return (link_type&)header->right;}
	//��������������������ȡ�ýڵ�x�ĳ�Ա
	static link_type& left(link_type x){	//��link_type��__rb_tree_node* 
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
		return KeyOfValue()(value(x));		//�������� 
	}
	static color_type& color(link_type x){
		return (color_type&)(x->color);
	}
	//��������������������ȡ�ýڵ�x�ĳ�Ա
	static link_type left(base_ptr x){		//��base_ptr��_rb_tree_base_node* 
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
	//���ؼ���ֵ���ý���ֵ 
	static const Key& key(base_ptr x){
		return KeyOfValue()(value(link_type(x)));		//�������� 
	}
	static color_type& color(base_ptr x){
		return (color_type&)(link_type(x)->color);
	}
	//��ȡ����ֵ�ͼ�Сֵ��node class��ʵ�ִ˹��ܣ������������ 
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
		header=get_node();	//����һ���ڵ�ռ䣬��headerָ����
		color(header)=__rb_tree_red; 	//��headerΪ��ɫ,��������header��root 
		root()=0;
		leftmost()=header;	//��header�����ӽڵ�Ϊ�Լ� 
		rightmost()=header;
	}
public:
	//allocation/deallocation
	rb_tree(const Compare& comp=Compare()):node_count(0),key_compare(comp){
		init();	//��ʵ�ּ��ɵ�һ���ؼ��� 
	}
	~rb_tree(){
		clear();
		put_node(hearder);
	}
	rb_tree<Key,Value,KeyOfValue,Compare,Alloc>&
	operator=(const rb_tree<Key,Value,KeyOfValue,Compare,Alloc>& x);

public: 
	Compare key_comp() const{return key_compare;}
	iterator begin(){return leftmost();}//����������Ϊ������С���ڵ㴦 
	iterator end(){return header;}//��������յ���header��ָ��
	bool empty() const{return node_count==0;} 
	size_type size() const{return node_count;}
	size_type max__size() const{return size_type(-1);}
	
public:
	//insert/erase
	//��x���뵽 ����������ֽڵ�ֵ��һ�޶�
	pair<iterator,bool> insert_unique(const value_type& x);
	//��x���뵽������У�����ڵ�ֵ�ظ�
	iterator insert_equal(const value_type& x);
	//... 
};

//Ԫ�ز������
//������ֵ�������ظ�������һ��RB_tree��������ָ���������
template<class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,ComPare,Alloc>::insert_equal(const Value& v){
	link_type y=header;
	link_type x=root();	//�Ӹ���㿪ʼ
	while(x!=0){
		//�Ӹ���㿪ʼ������Ѱ���ʵ��Ĳ����
		y=x;
		x=key_compare(KeyOfValue()(v),key(x))?left(x):right(x); 
		//����������С���� 
	}
	return __insert(x,y,v);//xΪ��ֵ����㣬yΪ�����ĸ��ڵ㣬vΪ��ֵ 
}
//Ԫ�ز��������������ֵ�ظ�
template<class Key,class Value,class KeyOfValue,class Compare,class Alloc>
pair<typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator,bool>
rb_tree<Key,Value,KeyOfValue,ComPare,Alloc>::insert_unique(const Value& v){
	link_type y=header;
	link_type x=root();	//�Ӹ��ڵ㿪ʼ
	bool comp=true;
	while(x!=0) {
		y=x;
		comp=key_compare(KeyOfValue()(v),key(x)); 
		x=comp?left(x):right(x);//����Ѱ���ʵ��Ĳ���� ������������С���� 
	}
	//�뿪while��y��ָ�������ĸ��ڵ�
	iterator j=iterator(y);
	if(comp)	//Ϊ�棬��ʾ����x�󣬲������
		if(j==begin()) //��������ĸ��ڵ�Ϊ����ڵ�
			return pair<iterator,bool>(__insert(x,y,v),true); 	//����pair���� 
	 	else	//�����ĸ��ڵ㲻Ϊ������ 
			--j;//����j����ͷ׼������
	if(key_compare(key(j.node),KeyOfValue()(v)));
		//��ʾС����ֵ����С���������Ҳ� 
		return pair<iterator,bool>(__insert(x,y,v),true);
	//�������ˣ���ʾ��ֵһ�������м�ֵ�ظ�����ô�Ͳ��ò�����ֵ
	return pair<iterator,bool>(j,false);
}

//�����Ĳ���ִ�г���
template <class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::__insert(base_ptr x_,base_ptr y_,const Value& v){
	//����xΪ��ֵ����㣬yΪ����㸸�ڵ㣬vΪ��ֵ 
	link_type x=(link_type)x_;
	link_type y=(link_type)y_;
	link_type z;
	//key_compare�Ǽ�ֵ��С�Ƚ�׼��,y��ֵ�� 
	if(y==header||x!=0||key_compare(KeyOfValue()(v),key(y))){
		z=create_node(v);	//����һ���½ڵ�
		left(y)=z; 	//��yΪheader��ʱ��ʹ��zΪ������ 
		if(y==header){
			root()=z;
			rightmost()=z;
		}
		else if(y==leftmost()) //���y�������� 
			leftmost()=z; 
	}
	else	//y��ֵС
	{
		z=create_node(v);
		right(y)=z;	//���½ڵ��Ϊ����ڵ�����ӽڵ�
		if(y==rightmost()) 
			rightmost()=z;
	}
	parent(z)=y;
	left(z)=0;
	right(z)=0;
	//�����½ڵ����ɫ
	__rb_tree_rebalance(z,header->parent);	//����1Ϊ�����ڵ㣬����2Ϊroot
	++node_count;
	return iterator(z); 
} 

//����Ԫ��
template <class Key,class Value,class KeyOfValue,class Compare,class Alloc>
typename rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::iterator
rb_tree<Key,Value,KeyOfValue,Compare,Alloc>::find(const Key& k){
	link_type y=header;		//last node which is not less than k
	link_type x=root();		//current node
	while(x!=0){
		//key_compare��һ���ڵ��ֵ��С�Ƚ�׼��
		if(!key_compare(key(x),k))
			//x>k����x=k 
			y=x,x=left(x); 
		else
			//x<k
			x=right();
	}
	iterator j=iterator(y);
	return (j==end()||key_compare(k,key(j.node)))?end():j;
}

