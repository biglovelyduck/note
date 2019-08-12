//list�ڵ� 
template <class T>
struct __list_node{
	typedef void * void_pointer;//�ͱ�Ϊvoid* ��ʵҲ����Ϊ __list_node<T>*
	void_pointer prev;
	void_pointer next;
	T data;
};

//list�ĵ�����,list�ṩ����Bidirectional Iterators
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
	
	link_type node;//�������ڲ���ָ��ָ��list�Ľ��
	
	//constructor
	__list_iterator(link_type x):node(x){}
	__list_iteratpr(){}
	__list_iterator(const iterator& x)::node(x.node){} 
	
	bool operator==(const self& x) const{return node==x.node;}
	bool operator!=(const self& x) const{return node!=x.node;}
	//�Ե�����ȡֵ��ȡ���ǽ�������ֵ
	reference operator*() const{return (*node).data;}
	//�������ĳ�Ա��ȡ(member access)�����ӵı�׼����
	pointer operator->() const{return &(operator*());}
	//�Ե������ۼ�1������ǰ��һ�����
	//ǰ�� 
	self& operator++(){
		node=(link_type)((*node).next);
		return *this;
	} 
	//���� 
	self operator++(int){
		self tmp=*this;
		++*this;
		return tmp; 
	}
	//�Ե�������1�����Ǻ���һ�����
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

//list�����ݽṹ��SGI list��һ����״˫����������ֻ��Ҫһ��ָ�룬�Ϳ��Ա�����������
template <class T,class Alloc=alloc>
class list{
protected:
	typedef __list_node<T> list_node;
	//ר��֮�ռ�������,ÿ������һ������С
	typedef simple_alloc<list_node,Alloc> list_node_allocator; 
public:
	typedef list_node* link_type;
protected:
	link_type node;//ֻҪһ��ָ��Ϳ��Ա�ʾ������״˫������
	
public:
	//��nodeָ���������β�˵�һ���հ׽�㣬node���ܷ���ǰ�պ󿪣���Ϊlast������
	//������
	iterator begin(){
		return (link_type()((*node).next);
	}
	iterator end(){
		return node;
	} 
	bool empty() const{return node->next==node;}
	size_type size() const{
		size_type result=0;
		distance(begin(),end(),result);//ȫ�ֺ��� 
		return reslut; 
	}
	//ȡͷ��������
	reference front(){
		return *begin();
	} 
	reference back(){
		return *(--end());
	}
	
	//default constructor 
	list(){
		empty_initialize();//����һ�������� 
	}
	
	void push_back(const T& x){
		insert(end(),x);
	}
	
	//�Ƴ�������poison��ָ�Ľ��
	iterator erase(iterator position){
		link_type next_node=link_type(position.node->next);
		link_type prev_node=link_type(position.node->prev); 
		prev_node->next=next_node;
		next_node->prev=prev_node;
		destroy_node(position.node);
		return iterator(next_node);
	} 
	
	//�ڵ�����position��ָ��λ�ò���һ����㣬����Ϊx
	iterator insert(iterator position,const T& x){
		link_type tmp=create_node(x);//����һ����㣬��������Ϊx 
		//����˫��ָ�룬ʹ��tmp�����ȥ
		tmp->next=position.node;
		tmp->prev=position.node->prev;
		(link_type(position.node->prev))->next=tmp;
		position.node->pre=tmp;
		return tmp; 
	}
	
	//����һ����㣬��Ϊͷ���
	void push_front(const T& x){
		insert(begin(),x);
	} 
	//����һ����㣬��Ϊβ���
	void push_back(const T& x){
		insert(end(),x);
	} 
	
	//�Ƴ�ͷ���
	void pop_front(){
		erase(begin());
	}
	//�Ƴ�β���
	void pop_back(){
		iterator tmp=end();
		erase(--tmp);
	}  
	
	//������еĽ��
	void clear();
	//����ֵΪvalue������Ԫ���Ƴ�
	void remove(const T& value); 
	//�Ƴ���ֵ��ͬ������Ԫ�أ�֪��ʣ��һ��
	void unique(); 
	
	//��[first,last)�ڵ�����Ԫ���ƶ���position֮ǰ
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
	
	//����splice�汾,��x�Ӻ���position��ָλ��֮ǰ��x��ͬ��*this 
	void splice(iterator position,list &x){
		if(!x.empty())
			transfer(position,x.begin(),x.end());
	} 
	//��i��ָԪ�ؽ����position��ָλ��֮ǰ������ָ��ͬһ��list
	void splice(iteartor position,list&, iterator i){
		iterator j=i;
		++j;//j�� 
		if(position==i||position==j) return;
		transfer(position,i,j);
	}
	//��[fisrt,last)������Ԫ�ؽӺ���position֮ǰ
	//position��[first,last)����ָ��ͬһ��list
	//��position����λ��[first,last)��
	void splice(iterator position,list&, iterator first,iterator last){
		if(first!=last)
			transfer(position,first,last);
	} 
	
	//��x�ϲ���*this���ϣ�����list�����ݱ��붼�Ⱦ����˵������� 
	void merge(list<T,Alloc> &x);
	//��*this��������������
	void reverse(); 
	//list������ͬSTL��sort�㷨�������Լ�����
	//��ΪSTL��sortֻ����RandomAccessIterator
	//quick sort
	void sort(); 
	
protected:
	//����һ����㲢����ָ�����ָ�� 
	link_type get_node(){
		return list_node_allocator::allocate();
	} 
	//�ͷ�һ�����
	void put_node(link_type p){
		list_node_allocator::deallocate(p);
	}
	//���������ò����죩һ����㣬����Ԫ��ֵ
	link_type create_node(const T& x){
		link_type p=get_node();
		construct(&p->data,x);
		return p;
	} 
	//���٣��������ͷţ�һ�����
	void destroy_node(link_type p){
		destroy(&p->data);//����
		put_node(p);//�ͷ� 
	} 
	
	//����һ��������
	void empty_initialize(){
		node=get_node();//����һ�����ռ䣬��nodeָ����
		node->next=node;//��nodeͷβ��ָ���Լ�������Ԫ��ֵ
		node->prev=node; 
	} 
}; 

template <class T,class Alloc>
void list<T,Alloc>::clear(){
	link_type cur=(link_type)node->next;//begin
	while(cur!=node){
		//����ÿһ�����
		link_type tmp=cur;
		cur=(link_type)cur->next;
		destroy_node(tmp);//�������ͷ� 
	}
	//�ָ�node��ԭʼ״̬
	node->next=node;
	node->prev=node; 
}

template <class T,class Alloc>
void list<T,Alloc>::remove(const T& value){
	iterator first=begin();
	iterator last=end();
	while(first!=last){
		//����ÿһ�����
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
	if(first==last) return;//������ʲô������
	iterator next=first;
	while(++next!=first){
		//����ÿһ�����
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
	
	//ǰ��������list���Ѿ��ź���
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
	//һЩ�µ�lists����Ϊ�н����ݴ����
	list<T,Alloc> carry;
	list<T,Alloc> counter[64];
	int fill=0;
	while(!empty()){
		carry.splice(carry.begin(),*this,begin());//��*this��begin���뵽carry.begin֮ǰ 
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
 
