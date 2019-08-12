
//全局函数,用来决定缓冲区大小的函数
inline size_t __deque_buf_size(size_t n,size_t sz){
	return n!=0?n:(sz<512?size_t(512/sz):size_t(1));
}

//deque的迭代器
template <class T,class Ref,class Ptr,size_t BufSiz>
struct __deque_iterator{		//未继承std::iterator 
	typedef __deque_iterator<T,T&,T*,BufSiz> iterator;
	typedef __deque_iterator<T,const T&,const T*,BufSiz> const_iterator;
	static size_t buff_size(){
		return __deque_buf_size(BufSiz,sizeof(T));
	}
	
	//未继承std::iterator，所以必须自行撰写五个必要的迭代器相应型别
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef ptrdiff_t difference_type;
	
	typedef size_t size_type;
	typedef T** map_pointer;
	
	typedef __deque_iterator self;
	
	//保持与容器的联结
	T* cur;				//此迭代器所指缓当前冲区中的现行元素
	T* first;			//此迭代器所指当前缓冲器的头
	T* last;			//此迭代器所指当前缓冲区的尾（含备用空间）
	map_pointer node;	//所指管控中心 指向map 
	
public:
	//deque迭代器的几个关键行为
	
	//set_node:跳一个缓冲区，就是跳一个主控器内部的结点 
	void set_node(map_pointer new_node){
		node=new_node;
		first=*new_node;
		last=first+difference_type(buffer_size());
	} 
	//重载运算子
	reference operator*() const{return *cur;} 
	pointer operator->() const{return &(operator*());}
	difference_type operator-(const self& x) const{
		return difference_type(buffer_size())*(node-x.node-1)+(cur-first)+(x.last-x.cur);
	}
	self& operator++(){			//前置运算符返回一个引用 
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
	
	//实现随机存取，迭代器可以直接跳跃n个距离
	self& operator+=(difference_type n){
		difference_type offset=n+(cur-first);
		if(offset>=0&&offset<difference_type(buffer_size())) //目标位置在同一个缓冲区
			cur+=n;
		else{
			//标的位置不在同一个缓冲区
			difference_type node_offset=offset>0?offset/difference_type(buffer_size())
										:-difference_type((-offset-1)/buffer_size())-1;
			//切换至正确的结点(亦即缓冲区)
			set_node(node+node_offset);
			//切换至正确的元素
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


//deque,，每一个结点都是一个缓冲区 ，每个元素都是指针，指向另一段连续线性空间 
//SGI允许我们制定缓冲区大小，默认值0表示将使用512bytes缓冲区 
template <class T,class Alloc=alloc,size_t BufSiz=0> 
class deque{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef size_t size_type;
	
	typedef _deque_iterator<T,T&,T*,BufSiz> iterator; 	//类型名 
	//...
protected:			//Internal typedefs
	//元素的指针的指针
	typedef pointe=-p* map_pointer;
protected:			//Data members
 	map_pointer map;//指向map，map是块连续空间，其内的每一个元素都是一个指针（结点）
					//指向一块缓冲区
	iterator start;		//表现第一个节点 ,指向第一个缓冲区 
	iterator finish;	//表现最后一个节点 指向最后一个缓冲区 
	size_type map_size;//map可容纳多少指针
	
	//有了上述结构，以下杰哥机能便可以轻易完成 
public: 
	iterator begin(){return start;}
	iterator end(){return finish;}
	reference operator[](size_type n){
		return start[difference_type(n)];//调用__deque_itearator<>::operator[] 
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
	
	//将元素的初始值设定妥当 
	fill_initialize(size_type n,const value_type& value);
	//安排好deque的结构
	create_map_and_nodes(size_type num_elements); 
	
	//配置一块新的缓冲区，再设妥新元素的内容
	void push_back_aux(const value_type& t);
	void push_front_aux(const calue_type& t); 
	
	//重新调整map
	void reallocate map(size_type nodes_to_add,bool add_at_front); 
	
	//释放缓冲区
	void pop_back_aux(); 
	void pop_front_aux();
	
	//清除整个deque
	void clear(); 
	
	//什么时候map需要重新整治
	void reserve_map_at_back(size_type nodes_to_add=1){
		if(nodes_to_add+1>map_size-(finish.node-map))
			//如果map尾端节点备用空间不足
			//若符合上述条件必须重新换一个map（配置更大的，拷贝原来的，释放原来的）
			reallocate_map(nodes_to_add,false); 
	}
	void reserve_map_at_front(size_type nodes_to_add=1){
		if(nodes_to_add>start.node-map)
			//map前端节点备用空间不足
			reallocate_map(nodes_to_add,true); 
	} 
	
	void push_back(const value_type& t){
		if(finish.cur!=finish.last-1){
			//最后一个缓冲区尚有一个以上的备用空间
			construct(finish.cur,t); //直接在备用空间上构造元素
			++finish.cur; 
		}
		else
			push_back_aux(t);//配置一块新的缓冲区 
	}
	
	void push_front(const value_type& t){
		if(start.cur!=start.first){
			//第一缓冲区尚有备用空间，直接在备用空间上构造元素
			construct(start.cur-1);//左端可以是空的 
			--start.cur; 
		}
		else push_front_aux(t);
	}
	
	void pop_back(){
		if(finish.cur!=finish.first){
			//最后一个缓冲区有一个或更多元素
			--finish.cur;
			destroy(finish.cur); 
		}
		else
		//最后缓冲区没有任何元素
		pop_back_aux();		//这里将进行缓冲区的释放操作 
	}
	
	void pop_front(){
		if(start,cur!=start.last-1){
			destroy(start.cur);
			++start.cur;
		}
		else
			pop_front_aux();
	}
	
	//清除pos所指元素
	iterator erase(iterator pos){
		iterator next=pos;
		++next;
		defference_type index=pos-start;		//清楚点之前的元素个数 
		if(index<(size()>>1)){
			//如果清除点之前的元素比较少，就移动之前的元素
			copy_backward(start,pos,index);
			pop_front(); 
		}
		else {
			copy(next,finish,pos);
			pop_back();
		}
		return start+index;
	}
	//清除[first,last)区间内的所有元素
	iterator erase(iterator forst,iterator last); 
	
	iterator insert_aux(iterator pos,const value_type& x);
	
	//在position位置插入一个元素x
	iterator insert(iterator position,const value_type& x){
		if(position.cur==start.cur){
			//如果插入点是deque的最前端
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
	//专属空间配置器,每次配置一个元素大小
	typedef simple_alloc<value_type,Alloc> data_allocator;
	//专属空间配置器,每次配置一个指针大小
	typedef simple_alloc<pointer,Alloc> map_allocator;
	
	//constructor
	deque(int n,const value_type& value)
		:start(),finish(),map(0),map_size(0){
			fill_initialize(n,value);
		} 
};

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::fill_initialize(size_type n,const value_type& value){
	create_map_and_nodes(n);//把deque的结构都产生并安排好
	map_pointer cur;
	__STL_TRY{
		//为每个节点的缓冲区设定初值
		for(cur=start.node;cur<finish.node;++cur)
			uninitialized_fill(*cur,*cur+buffer_size(),value);
		//最后一个结点的设定稍有不同，因为尾端可能有备用空间，不必设定初值
		uninitialized_fill(finish.first,finish.cur,value); 
	}
	catch(...){
		...
	} 
} 

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz::create_map_and_nodes(size_type num_elements){
	//需要的map内部的节点数=(元素个数/每个缓冲区可以容纳的元素个数)+1 
	//如果刚好整除，会多配一个结点
	size_type num_nodes=num_elements/buffer_size()+1;
	
	//一个map要管理杰哥结点，最少八个，最多是所需节点数+2
	//前后各预留一个，扩充时可用
	map_size=max(initial_map_size(),num_nodes+2);
	map=map_allocator::allocate(map_size); //配置出具有map_size个节点的map
	
	//以下另nstart和nfinish指向map所拥有之全部结点的最中央区段
	//保持在最中央，可以使两头的扩充能量一样大 
	map_pointer nstart=map+(map_size-num_nodes)/2;
	map_pointer nfinish=nstart+num_nodes-1;
	
	map_pointer cur; 
	__STL_TRY{
		//为map内的每个现用节点配置缓冲区，所有缓冲区加起来就是deuqe的可用空间
		for(cur=nstart;cur<=nfinish;++cur)
			*cur=allocate_node(); 
	}
	catch(...){
		...
	}
	
	//为deque内的两个迭代器start和end设定正确内容
	start.set_node(nstart);
	finish.set_node(nfinish);
	start.cur=start.first;
	finish.cur=finish.first+num_elements%buffer_size(); 
}

template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::push_back_aux(const value_type& t){
	value_type t_copy=t;
	reserve_map_at_back();		//若符合某种条件则必须重新换一个map
	*(finish.node+1)=allocate_node(); 	//配置一个新节点
	__STL_TRY{
		construct(finish.cur,t_copy);	//针对标的元素设值 
		finish.set_node(finish.node+1); 
		finish.cur=finish.first;
	} 
	__STL_UNWIND(deallocate_node(*(finish.node+1)));
} 

//只有当start.cur==start.first才会被调用
//只有当第一个缓冲区没有任何备用元素时才会被调用
template <class T,class Alloc,size_t BufSiz>
void deque<T,Alloc,BufSiz>::push_front_aux(const value_type& t){
	value_type t_copy=t;
	reserve_map_at_front();//若符合某种条件，则必须重新换一个map
	*(start.node-1)=allocate_node();//配置一个新节点（缓冲区)
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
	size_type new_num_nodes=old_num_nodes+node_to_add; 			//新的节点数 
	
	map_pointer new_nstart;
	if(map_size>2*new_num_nodes){				//空间足够用
		//如果是向前插入，起点会右移 
		new_nstart=map+(map_size-new_num_nodes)/2)+(add_at_front?nodes_to_add:0);
		//向后插入，左移了 
		if(new_nstart<start.node)
			copy(start.node,finish.node+1,new_nstart);
		//向前插入，右移了 
		else 
			copy_backward(start.node,finish.node+1,new_nstart+old_num_nodes);
	}
	else{									//空间不够用了 
		size_type new_map_size=map_size+max(map_size,nodes_to_add)+2;
		//配置一块空间，准备给新map使用
		map_pointer new_map=map_allocator::allocate(new_map_size); 
		new_nstart=new_map+(map_size-new_num_nodes)/2)+(add_at_front?nodes_to_add:0);
		//把原来的map内容拷贝过来
		copy(start.node,finish.node+1,new_nstart);
		//释放原来的map
		map_allocator::deallocate(map,map_size);
		//设定新map的其实地址和大小
		map=new_map; 
		map_size=new_map_size;
	} 
	//重新设定迭代器start和finish
	start.set_node(new_nstart);
	finish.set_node(new_nstart+old_num_nodes-1); 
}

//只有当finish.cur==finish.first时才会被调用
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
	//以下针对头尾以外的每一个缓冲区，每一个都是饱满的
	for(map_pointer node=start.node+1;node<finish.node;++node){
		//将缓冲区内的所有元素析构，调用destroy()第二版本
		destroy(*node,*node+buffer_size());
		//释放缓冲区内存
		data_allocator::deallocate(*node,buffer_size()); 
	}
	if(start.node!=finish.node){
		//至少有头尾两个缓冲区
		destroy(start.cur,start.last);
		destroy(finish.first,finish.cur);
		//以下释放尾缓冲区，注意头缓冲区保留
		data_allocator::deallocate(finish.first,buffer_size()) ;
	} 
	else{
		//只有一个缓冲区
		destroy(start.cur,finish.cur);//并不释放缓冲区，将缓冲区内所有元素析构 
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
		defference_type n=last-first;//	清除区间的长度
		defference_type elems_before=first-start;//清除区间前方的元素个数 
		if(elems_before<(size()-n)/2){
			copy_backward(start,first,last);
			iterator new_start=start+n;
			destroy(start.new_start);
			//将冗余的缓冲区释放
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
typename deque<T,Alloc,BufSiz>::iterator	//typename标注iterator是类型 
deque<T,Alloc,BufSiz>::insert_aux(iterator pos,const value_type& x){
	difference_type index=pos-start;	//插入点之前的元素个数
	value_type x_copy=x;
	if(index<size()/2){
		//插入点之前的元素比较少
		push_front(front());
		iterator front1=start;
		++front1;
		iterator front2=front1;
		++front2;
		pos=start+index;
		iterator pos1=pos;
		++pos1;
		copy(front2,pos1,front1);		//元素移动 
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










