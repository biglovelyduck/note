
//ȫ�ֺ���,����������������С�ĺ���
inline size_t __deque_buf_size(size_t n,size_t sz){
	return n!=0?n:(sz<512?size_t(512/sz):size_t(1));
}

//deque�ĵ�����
template <class T,class Ref,class Ptr,size_t BufSiz>
struct __deque_iterator{		//δ�̳�std::iterator 
	typedef __deque_iterator<T,T&,T*,BufSiz> iterator;
	typedef __deque_iterator<T,const T&,const T*,BufSiz> const_iterator;
	static size_t buff_size(){
		return __deque_buf_size(BufSiz,sizeof(T));
	}
	
	//δ�̳�std::iterator�����Ա�������׫д�����Ҫ�ĵ�������Ӧ�ͱ�
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef ptrdiff_t difference_type;
	
	typedef size_t size_type;
	typedef T** map_pointer;
	
	typedef __deque_iterator self;
	
	//����������������
	T* cur;				//�˵�������ָ����ǰ�����е�����Ԫ��
	T* first;			//�˵�������ָ��ǰ��������ͷ
	T* last;			//�˵�������ָ��ǰ��������β�������ÿռ䣩
	map_pointer node;	//��ָ�ܿ����� ָ��map 
	
public:
	//deque�������ļ����ؼ���Ϊ
	
	//set_node:��һ����������������һ���������ڲ��Ľ�� 
	void set_node(map_pointer new_node){
		node=new_node;
		first=*new_node;
		last=first+difference_type(buffer_size());
	} 
	//����������
	reference operator*() const{return *cur;} 
	pointer operator->() const{return &(operator*());}
	difference_type operator-(const self& x) const{
		return difference_type(buffer_size())*(node-x.node-1)+(cur-first)+(x.last-x.cur);
	}
	self& operator++(){			//ǰ�����������һ������ 
		++cur;
		if(cur==last){
			set_node(node+1);
			cur=first;
		}
		return *this;
	}
	self operator++(int){
		self tmp=*this;
		++*this;
		return tmp;
	}
	self& operator--(){
		if(cur==first){
			set_node(node-1);
			cur=last;
		}
		--cur;
		return *this;
	}
	self operator--(int){
		self tmp=*this;
		--*this;
		return tmp;
	}
	
	//ʵ�������ȡ������������ֱ����Ծn������
	self& operator+=(difference_type n){
		difference_type offset=n+(cur-first);
		if(offset>=0&&offset<difference_type(buffer_size())) //Ŀ��λ����ͬһ��������
			cur+=n;
		else{
			//���λ�ò���ͬһ��������
			difference_type node_offset=offset>0?offset/difference_type(buffer_size())
										:-difference_type((-offset-1)/buffer_size())-1;
			//�л�����ȷ�Ľ��(�༴������)
			set_node(node+node_offset);
			//�л�����ȷ��Ԫ��
			cur=first+(offset-node_offset*difference_type(buffer_size())); 
		} 
		return *this;
	}
	
	self operator+(defference_type n) const{
		self tmp=*this;
		return tmp+=n;
	}
	self& operator-=(difference_type n){
		return *this+=-n;
	}
	self operator-(difference_type n) const{
		self tmp=*this;
		return tmp-=n;
	}
	
	reference operator[](difference_type n) const{return *(*this+n);}
	
	bool operator==(const self& x) const{return cur==x.cur;}
	bool operator!=(const self& x) const{return !(*this==x);}
	bool operator<(const self& x) const{
		return (node==x.node)?(cur<x.cur):(node<x.node); 
	}
}; 


//deque,��ÿһ����㶼��һ�������� ��ÿ��Ԫ�ض���ָ�룬ָ����һ���������Կռ� 
//SGI���������ƶ���������С��Ĭ��ֵ0��ʾ��ʹ��512bytes������ 
template <class T,class Alloc=alloc,size_t BufSiz=0> 
class deque{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef size_t size_type;
	
	typedef _deque_iterator<T,T&,T*,BufSiz> iterator; 	//������ 
	//...
protected:			//Internal typedefs
	//Ԫ�ص�ָ���ָ��
	typedef pointe=-p* map_pointer;
protected:			//Data members
 	map_pointer map;//ָ��map��map�ǿ������ռ䣬���ڵ�ÿһ��Ԫ�ض���һ��ָ�루��㣩
					//ָ��һ�黺����
	iterator start;		//���ֵ�һ���ڵ� ,ָ���һ�������� 
	iterator finish;	//�������һ���ڵ� ָ�����һ�������� 
	size_type map_size;//map�����ɶ���ָ��
	
	//���������ṹ�����½ܸ���ܱ����������� 
public: 
	iterator begin(){return start;}
	iterator end(){return finish;}
	reference operator[](size_type n){
		return start[difference_type(n)];//����__deque_itearator<>::operator[] 
	} 
	reference front(){return *start;}
	reference back(){
		iterator tmp=finish;
		--tmp;
		return *tmp;
	}
	size_type size() const{return finish-start;}
	size_type max_size() const{return size_type(-1);}
	bool empty() const{return finsh==start;} 
	
	//��Ԫ�صĳ�ʼֵ�趨�׵� 
	fill_initialize(size_type n,const value_type& value);
	//���ź�deque�Ľṹ
	create_map_and_nodes(size_type num_elements); 
	
	//����һ���µĻ���������������Ԫ�ص�����
	void push_back_aux(const value_type& t);
	void push_front_aux(const calue_type& t); 
	
	//���µ���map
	void reallocate map(size_type nodes_to_add,bool add_at_front); 
	
	//�ͷŻ�����
	void pop_back_aux(); 
	void pop_front_aux();
	
	//�������deque
	void clear(); 
	
	//ʲôʱ��map��Ҫ��������
	void reserve_map_at_back(size_type nodes_to_add=1){
		if(nodes_to_add+1>map_size-(finish.node-map))
			//���mapβ�˽ڵ㱸�ÿռ䲻��
			//���������������������»�һ��map�����ø���ģ�����ԭ���ģ��ͷ�ԭ���ģ�
			reallocate_map(nodes_to_add,false); 
	}
	void reserve_map_at_front(size_type nodes_to_add=1){
		if(nodes_to_add>start.node-map)
			//mapǰ�˽ڵ㱸�ÿռ䲻��
			reallocate_map(nodes_to_add,true); 
	} 
	
	void push_back(const value_type& t){
		if(finish.cur!=finish.last-1){
			//���һ������������һ�����ϵı��ÿռ�
			construct(finish.cur,t); //ֱ���ڱ��ÿռ��Ϲ���Ԫ��
			++finish.cur; 
		}
		else
			push_back_aux(t);//����һ���µĻ����� 
	}
	
	void push_front(const value_type& t){
		if(start.cur!=start.first){
			//��һ���������б��ÿռ䣬ֱ���ڱ��ÿռ��Ϲ���Ԫ��
			construct(start.cur-1);//��˿����ǿյ� 
			--start.cur; 
		}
		else push_front_aux(t);
	}
	
	void pop_back(){
		if(finish.cur!=finish.first){
			//���һ����������һ�������Ԫ��
			--finish.cur;
			destroy(finish.cur); 
		}
		else
		//��󻺳���û���κ�Ԫ��
		pop_back_aux();		//���ｫ���л��������ͷŲ��� 
	}
	
	void pop_front(){
		if(start,cur!=start.last-1){
			destroy(start.cur);
			++start.cur;
		}
		else
			pop_front_aux();
	}
	
	//���pos��ָԪ��
	iterator erase(iterator pos){
		iterator next=pos;
		++next;
		defference_type index=pos-start;		//�����֮ǰ��Ԫ�ظ��� 
		if(index<(size()>>1)){
			//��������֮ǰ��Ԫ�رȽ��٣����ƶ�֮ǰ��Ԫ��
			copy_backward(start,pos,index);
			pop_front(); 
		}
		else {
			copy(next,finish,pos);
			pop_back();
		}
		return start+index;
	}
	//���[first,last)�����ڵ�����Ԫ��
	iterator erase(iterator forst,iterator last); 
	
	iterator insert_aux(iterator pos,const value_type& x);
	
	//��positionλ�ò���һ��Ԫ��x
	iterator insert(iterator position,const value_type& x){
		if(position.cur==start.cur){
			//����������deque����ǰ��
			push_front(x);
			return start; 
		}
		else if(position.cur==finish.cur){
			push_back(x);
			iterator tmp=finish;
			--tmp;
			return tmp;
		}
		else return insert_aux(position,x);
	} 
	
protected:
	//ר���ռ�������,ÿ������һ��Ԫ�ش�С
	typedef simple_alloc<value_type,Alloc> data_allocator;
	//ר���ռ�������,ÿ������һ��ָ���С
	typedef simple_alloc<pointer,Alloc> map_allocator;
	
	//constructor
	deque(int n,const value_type& value)
		:start(),finish(),map(0),map_size(0){
			fill_initialize(n,value);
		} 
};

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::fill_initialize(size_type n,const value_type& value){
	create_map_and_nodes(n);//��deque�Ľṹ�����������ź�
	map_pointer cur;
	__STL_TRY{
		//Ϊÿ���ڵ�Ļ������趨��ֵ
		for(cur=start.node;cur<finish.node;++cur)
			uninitialized_fill(*cur,*cur+buffer_size(),value);
		//���һ�������趨���в�ͬ����Ϊβ�˿����б��ÿռ䣬�����趨��ֵ
		uninitialized_fill(finish.first,finish.cur,value); 
	}
	catch(...){
		...
	} 
} 

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz::create_map_and_nodes(size_type num_elements){
	//��Ҫ��map�ڲ��Ľڵ���=(Ԫ�ظ���/ÿ���������������ɵ�Ԫ�ظ���)+1 
	//����պ������������һ�����
	size_type num_nodes=num_elements/buffer_size()+1;
	
	//һ��mapҪ����ܸ��㣬���ٰ˸������������ڵ���+2
	//ǰ���Ԥ��һ��������ʱ����
	map_size=max(initial_map_size(),num_nodes+2);
	map=map_allocator::allocate(map_size); //���ó�����map_size���ڵ��map
	
	//������nstart��nfinishָ��map��ӵ��֮ȫ����������������
	//�����������룬����ʹ��ͷ����������һ���� 
	map_pointer nstart=map+(map_size-num_nodes)/2;
	map_pointer nfinish=nstart+num_nodes-1;
	
	map_pointer cur; 
	__STL_TRY{
		//Ϊmap�ڵ�ÿ�����ýڵ����û����������л���������������deuqe�Ŀ��ÿռ�
		for(cur=nstart;cur<=nfinish;++cur)
			*cur=allocate_node(); 
	}
	catch(...){
		...
	}
	
	//Ϊdeque�ڵ�����������start��end�趨��ȷ����
	start.set_node(nstart);
	finish.set_node(nfinish);
	start.cur=start.first;
	finish.cur=finish.first+num_elements%buffer_size(); 
}

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::push_back_aux(const value_type& t){
	value_type t_copy=t;
	reserve_map_at_back();		//������ĳ��������������»�һ��map
	*(finish.node+1)=allocate_node(); 	//����һ���½ڵ�
	__STL_TRY{
		construct(finish.cur,t_copy);	//��Ա��Ԫ����ֵ 
		finish.set_node(finish.node+1); 
		finish.cur=finish.first;
	} 
	__STL_UNWIND(deallocate_node(*(finish.node+1)));
} 

//ֻ�е�start.cur==start.first�Żᱻ����
//ֻ�е���һ��������û���κα���Ԫ��ʱ�Żᱻ����
template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::push_front_aux(const value_type& t){
	value_type t_copy=t;
	reserve_map_at_front();//������ĳ����������������»�һ��map
	*(start.node-1)=allocate_node();//����һ���½ڵ㣨������)
	__STL_TRY{
		start.set_node(start.node-1);
		start.cur=start.last-1;
		construct(start.cur,t_copy);
	}
	catch(...){
		start.ser_node(start.node+1);
		start.cur=start.first;
		deallocate_node(*(start.node-1));
		throw;
	} 
} 

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::reallocate_map(size_type nodes_to_add,bool add_at_front){
	size_type old_num_nodes=finish.node-start.node+1;
	size_type new_num_nodes=old_num_nodes+node_to_add; 			//�µĽڵ��� 
	
	map_pointer new_nstart;
	if(map_size>2*new_num_nodes){				//�ռ��㹻��
		//�������ǰ���룬�������� 
		new_nstart=map+(map_size-new_num_nodes)/2)+(add_at_front?nodes_to_add:0);
		//�����룬������ 
		if(new_nstart<start.node)
			copy(start.node,finish.node+1,new_nstart);
		//��ǰ���룬������ 
		else 
			copy_backward(start.node,finish.node+1,new_nstart+old_num_nodes);
	}
	else{									//�ռ䲻������ 
		size_type new_map_size=map_size+max(map_size,nodes_to_add)+2;
		//����һ��ռ䣬׼������mapʹ��
		map_pointer new_map=map_allocator::allocate(new_map_size); 
		new_nstart=new_map+(map_size-new_num_nodes)/2)+(add_at_front?nodes_to_add:0);
		//��ԭ����map���ݿ�������
		copy(start.node,finish.node+1,new_nstart);
		//�ͷ�ԭ����map
		map_allocator::deallocate(map,map_size);
		//�趨��map����ʵ��ַ�ʹ�С
		map=new_map; 
		map_size=new_map_size;
	} 
	//�����趨������start��finish
	start.set_node(new_nstart);
	finish.set_node(new_nstart+old_num_nodes-1); 
}

//ֻ�е�finish.cur==finish.firstʱ�Żᱻ����
template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::pop_back_aux(){
	deallocate_node(finish.first);
	finish.set_node(finish.node-1);
	finish.cur=finish.last-1;
	destroy(finish.cur);
} 
template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::pop_front_aux(){
	destroy(start.cur);
	deallocate_node(start.first);
	start.set_node(start.node+1);
	start.cur=start.first;
}

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::clear(){
	//�������ͷβ�����ÿһ����������ÿһ�����Ǳ�����
	for(map_pointer node=start.node+1;node<finish.node;++node){
		//���������ڵ�����Ԫ������������destroy()�ڶ��汾
		destroy(*node,*node+buffer_size());
		//�ͷŻ������ڴ�
		data_allocator::deallocate(*node,buffer_size()); 
	}
	if(start.node!=finish.node){
		//������ͷβ����������
		destroy(start.cur,start.last);
		destroy(finish.first,finish.cur);
		//�����ͷ�β��������ע��ͷ����������
		data_allocator::deallocate(finish.first,buffer_size()) ;
	} 
	else{
		//ֻ��һ��������
		destroy(start.cur,finish.cur);//�����ͷŻ���������������������Ԫ������ 
	}
	finish=start; 
}

template <class T,class Alloc,size_t BufSiz>
deque<T,Alloc,BufSiz>::iterator
deque<T,Alloc,BusSiz>::erase(iterator first,iterator last){
	if(first==start&&last==finish){
		clear();
		return finish;
	}
	else{
		defference_type n=last-first;//	�������ĳ���
		defference_type elems_before=first-start;//�������ǰ����Ԫ�ظ��� 
		if(elems_before<(size()-n)/2){
			copy_backward(start,first,last);
			iterator new_start=start+n;
			destroy(start.new_start);
			//������Ļ������ͷ�
			for(map_pointer cur=start.node;cur<new_start.node;++cur)
				data_allocator::deallocate(*cur,buffer_size());
			start=new_start; 
		}
		else{
			copy(last,finish,first);
			iterator new_finish=finish-n;
			destroy(new_finish,finish);
			for(map_pointer cur=new_finish.node+1;cur<=finish.node;++cur);
			data_allocator::deallocate(*cur,buffer_size());
		}
		return start+elems_before; 
	}
}

template <class T,class Alloc,size_t BufSiz>
typename deque<T,Alloc,BufSiz>::iterator	//typename��עiterator������ 
deque<T,Alloc,BufSiz>::insert_aux(iterator pos,const value_type& x){
	difference_type index=pos-start;	//�����֮ǰ��Ԫ�ظ���
	value_type x_copy=x;
	if(index<size()/2){
		//�����֮ǰ��Ԫ�رȽ���
		push_front(front());
		iterator front1=start;
		++front1;
		iterator front2=front1;
		++front2;
		pos=start+index;
		iterator pos1=pos;
		++pos1;
		copy(front2,pos1,front1);		//Ԫ���ƶ� 
	}
	else{
		push_back(back());
		iterator back1=finish;
		--back1;
		iterator back2=back1;
		--back2;
		pos=start+index;
		copy_backward(pos,back2,back1);
	} 
	*pos=x_copy;
	return pos;
} 










