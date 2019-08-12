//list节点 
template <class T>
struct __list_node{
	typedef void * void_pointer;//型别为void* 其实也可设为 __list_node<T>*
	void_pointer prev;
	void_pointer next;
	T data;
};

//list的迭代器,list提供的是Bidirectional Iterators
template <class T,class Ref,class Ptr>
struct __list_iterator{
	typedef __list_iterator<T,T&,T*> iterator;
	typedef __list_iterator<T,Ref,Ptr> self;
	
	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef __list_node<T>* link_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	
	link_type node;//迭代器内部的指针指向list的结点
	
	//constructor
	__list_iterator(link_type x):node(x){}
	__list_iteratpr(){}
	__list_iterator(const iterator& x)::node(x.node){} 
	
	bool operator==(const self& x) const{return node==x.node;}
	bool operator!=(const self& x) const{return node!=x.node;}
	//对迭代器取值，取的是结点的数据值
	reference operator*() const{return (*node).data;}
	//迭代器的成员存取(member access)运算子的标准做法
	pointer operator->() const{return &(operator*());}
	//对迭代器累加1，就是前置一个结点
	//前置 
	self& operator++(){
		node=(link_type)((*node).next);
		return *this;
	} 
	//后置 
	self operator++(int){
		self tmp=*this;
		++*this;
		return tmp; 
	}
	//对迭代器减1，就是后退一个结点
	self operator--(){
		node=(link_type)((*node).prev);
		return *this;
	} 
	self operator--(int){
		self tmp=*this;
		--*this;
		return tmp;
	}
}; 

//list的数据结构，SGI list是一个环状双向链表，所以只需要一个指针，就可以表现整个链表
template <class T,class Alloc=alloc>
class list{
protected:
	typedef __list_node<T> list_node;
	//专属之空间配置器,每次配置一个结点大小
	typedef simple_alloc<list_node,Alloc> list_node_allocator; 
public:
	typedef list_node* link_type;
protected:
	link_type node;//只要一个指针就可以表示整个环状双向链表
	
public:
	//让node指向刻意置于尾端的一个空白结点，node便能符合前闭后开，成为last迭代器
	//所以有
	iterator begin(){
		return (link_type()((*node).next);
	}
	iterator end(){
		return node;
	} 
	bool empty() const{return node->next==node;}
	size_type size() const{
		size_type result=0;
		distance(begin(),end(),result);//全局函数 
		return reslut; 
	}
	//取头结点的内容
	reference front(){
		return *begin();
	} 
	reference back(){
		return *(--end());
	}
	
	//default constructor 
	list(){
		empty_initialize();//产生一个空链表 
	}
	
	void push_back(const T& x){
		insert(end(),x);
	}
	
	//移除迭代器poison所指的结点
	iterator erase(iterator position){
		link_type next_node=link_type(position.node->next);
		link_type prev_node=link_type(position.node->prev); 
		prev_node->next=next_node;
		next_node->prev=prev_node;
		destroy_node(position.node);
		return iterator(next_node);
	} 
	
	//在迭代器position所指的位置插入一个结点，内容为x
	iterator insert(iterator position,const T& x){
		link_type tmp=create_node(x);//产生一个结点，设置内容为x 
		//调整双向指针，使得tmp插入进去
		tmp->next=position.node;
		tmp->prev=position.node->prev;
		(link_type(position.node->prev))->next=tmp;
		position.node->pre=tmp;
		return tmp; 
	}
	
	//插入一个结点，作为头结点
	void push_front(const T& x){
		insert(begin(),x);
	} 
	//插入一个结点，作为尾结点
	void push_back(const T& x){
		insert(end(),x);
	} 
	
	//移除头结点
	void pop_front(){
		erase(begin());
	}
	//移除尾结点
	void pop_back(){
		iterator tmp=end();
		erase(--tmp);
	}  
	
	//清除所有的结点
	void clear();
	//将数值为value的所有元素移除
	void remove(const T& value); 
	//移除数值相同的连续元素，知道剩余一个
	void unique(); 
	
	//将[first,last)内的所有元素移动到position之前
	void transfer(iterator position,iterator first,iterator last){
		if(position!=last){
			(*(link_type((*last.node).prev))).next=position.node;
			(*(link_type((*first.node).prev))).next=last.node;
			(*(link_type((*position.node).prev))).next=first.node;
			link_type tmp=link_type((*position.node).prev);
			(*position.node).prev=(*last.node).prev;
			(*last.node).prev=(*first.node).prev;
			(*first.node).prev=tmp;
		}
	}
	
	//各种splice版本,将x接合与position所指位置之前，x不同于*this 
	void splice(iterator position,list &x){
		if(!x.empty())
			transfer(position,x.begin(),x.end());
	} 
	//将i所指元素结合于position所指位置之前，可以指向同一个list
	void splice(iteartor position,list&, iterator i){
		iterator j=i;
		++j;//j大 
		if(position==i||position==j) return;
		transfer(position,i,j);
	}
	//将[fisrt,last)内所有元素接合与position之前
	//position和[first,last)可能指向同一个list
	//但position不能位于[first,last)内
	void splice(iterator position,list&, iterator first,iterator last){
		if(first!=last)
			transfer(position,first,last);
	} 
	
	//将x合并到*this身上，两个list的内容必须都先经过了递增排序 
	void merge(list<T,Alloc> &x);
	//将*this的内容逆向重置
	void reverse(); 
	//list不能视同STL的sort算法，必须自己定义
	//因为STL的sort只接受RandomAccessIterator
	//quick sort
	void sort(); 
	
protected:
	//配置一个结点并传回指向结点的指针 
	link_type get_node(){
		return list_node_allocator::allocate();
	} 
	//释放一个结点
	void put_node(link_type p){
		list_node_allocator::deallocate(p);
	}
	//产生（配置并构造）一个结点，带有元素值
	link_type create_node(const T& x){
		link_type p=get_node();
		construct(&p->data,x);
		return p;
	} 
	//销毁（析构并释放）一个结点
	void destroy_node(link_type p){
		destroy(&p->data);//析构
		put_node(p);//释放 
	} 
	
	//产生一个空链表
	void empty_initialize(){
		node=get_node();//配置一个结点空间，另node指向他
		node->next=node;//另node头尾都指向自己，不设元素值
		node->prev=node; 
	} 
}; 

template <class T,class Alloc>
void list<T,Alloc>::clear(){
	link_type cur=(link_type)node->next;//begin
	while(cur!=node){
		//遍历每一个结点
		link_type tmp=cur;
		cur=(link_type)cur->next;
		destroy_node(tmp);//析构并释放 
	}
	//恢复node的原始状态
	node->next=node;
	node->prev=node; 
}

template <class T,class Alloc>
void list<T,Alloc>::remove(const T& value){
	iterator first=begin();
	iterator last=end();
	while(first!=last){
		//遍历每一个结点
		iterator next=first;
		++next;
		if(*first==value) erase(first);
		fisrt=next; 
	}
}

template <class T,class Alloc>
void list<T,Alloc>::unique(){
	iterator first=begin();
	iterator last=end();
	if(first==last) return;//空链表，什么都不做
	iterator next=first;
	while(++next!=first){
		//遍历每一个结点
		if(*first==*next) erase(next);
		else first=next;
		next=first; 
	}
}

template <class T,class Alloc>
void list<T,Alloc>::merge(list<T,Alloc> &x){
	iterator first1=begin();
	iterator last1=end();
	iterator first2=x.begin();
	iterator last2==x.end();
	
	//前提是两个list都已经排好序
	while(first1!=last1&&first2!=last2)
		if(*first2<*first1){
			iterator next=first2;
			transfer(first1,first2,++next);
			first2=next;
		} 
		else{
			++first1;
		}
	if((fisrt2!=last2) tranfer(last1,first2,last2);
} 

template <class T,class Alloc>
void list<T,Alloc>::reverse(){
	if(node->next==node||link_type(node->next)->next==node) return;
	iterator first=begin();
	++first;
	while(first!=end()){
		iterator old=first;
		++first;
		transfer(begin(),old,first);
	}
}

template <class T,class Alloc>
void list<T,Alloc>::sort(){
	if(node->next=node||(link_type(node->next)->next)==node) return;
	//一些新的lists。作为中介数据存放区
	list<T,Alloc> carry;
	list<T,Alloc> counter[64];
	int fill=0;
	while(!empty()){
		carry.splice(carry.begin(),*this,begin());//将*this的begin插入到carry.begin之前 
		int i=0;
		while(i<fill&&!counter[i].empty()){
			counter[i].merge(carry);
			carry.swap(counter[i++]);
		}
		carry.swap(counter[i]);
		if(i==fill) ++fill;
	} 
	for(int i=1;i<fill;++i){
		counter[i].merge(counter[i-1]);
	}
	swap(counter[fill-1]);
}
 
