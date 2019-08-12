//vector
//alloc是SGI STL的空间配置器
template <class T,class Alloc=alloc>
class vector{
public:
	//vector的嵌套型别定义
	typedef T			value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;
protected:
	//空间配置器
	typedef simple_alloc<value_type,Alloc> data_allocator;
	iterator start;		//表示目前使用空间的头
	iterator finish;	//表示目前使用空间的尾
	iterator end_of_storage;//表示目前可用空间的尾
	
	void insert_aux(iterator position,const T& x);
	void deallocate(){
		if(start) data_allocator::deallocate(start,end_of_storage-start);
	}
	
	void fill_initialize(size_type n,const T& value){
		start=allocate_and_fill(n,value);
		finish=start+n;
		end_of_storage=finish;
	}
public:
	iterator begin(){
		return start;
	} 
	iterator end(){
		return finish;
	}
	size_type size() const{return size_type(end()-begin());}
	size_type capacity() const{return size_type(end_of_storage-begin());}
	bool empty() const{return begin()==end();}
	reference operator[](size_type n){
		return *(begin()+n);
	}
	
	//构造函数
	vector():start(0),finish(0),end_of_storage(0){}
	vector(size_type n,const T& value){
		fill_initialize(n,value);
	}
	vector(int n,const T& value){
		fill_initialize(n,value);
	}
	vector(long n,const T& value){
		fill_initialize(n,value);
	}
	explicit vector(size_type n){
		fill_initialize(n,T());
	}
	
	~vector(){
		destroy(start,finish);
		deallocate();
	}
	reference front(){return *begin();}
	referenc back(){return *(end()-1);}
	void push_back(const T& x){
		if(finish!=end_of_storage){
			construct(finish,x);
			++finish;
		}
		else 
			insert_aux(end(),x);
	}
	
	void pop_back(){
		--finish;
		destroy(finish);
	}
	//清除[fisrst和last)所有的元素 
	iterator erase(iterator first,iterator last){
		iterator i=copy(last,finish,first);
		destroy(i,finish);
		finish=finish-(last-first);
		return first;
	}
	//清除某个位置的元素 
	iterator erase(iterator position){
		if(position+1!=end())
			copy(position+1,finish,position);
		--finish;
		destroy(finish);
		return position;
	}
	void resize(size_type new_size,const T& x){
		if(new_size<size())
			erase(begin()+new_size,end());
		else
			insert(end(),new_size-size(),x);
	}
	void resize(size_type new_size){
		resize(new_size,T());
	}
	void clear(){
		erase(begin(),end());
	}
protected:
	//配置空间并且填满内容
	iterator allocate_and_fill(size_type n,const T& x){
		iterator result=data_allocator::allocate(n);
		unitialized_fill_n(result,n,x);
	} 
}; 

template<class T,class Alloc>
void vector<T,Alloc>::insert_aux(iterator position,const T& x){
	if(finish!=end_of_storage){
		//还有备用空间,在备用空间起始处构造一个元素，并以vector最后一个元素值为其初值 
		construct(finish,*(finish-1)); 
		++finish；
		T x_copy=x;
		copy_backward(position,finish-2,finish-1);//stl算法之拷贝，从后向前卡背 
		*position=x_copy; 
	}
	else{
		//已经没有备用空间 
		const size_type old_size=size();
		const size_type len=old_szie!=0?2*old_size:1;
		iterator new_start=data_allocator::allocate(len);//实际配置
		iterator new_finish=new_start;
		try{
			//将原vector的内容拷贝到新的vector
			new_finish=uninitialized_copy(start,position,new_start);
			//为新元素设定初值x
			construct(new_finish,x);
			++new_finish;
			new_finish=unitialized_copy(position,finish,new_finish); 
		} 
		catch(...){
			destroy(new_start,new_finish);
			data_allocator::deallocate(new_start,len);
			throw; 
		}
		//析构并释放原来的vector
		destroy(begin(),end());
		deallocate(); 
		
		//调整迭代器，指向新的vector
		start-new_start;
		finish=new_finish;
		end_of_storage=new_start+len; 
	}
}

template <class T,class Alloc>
void vector<T,Alloc>::insert(iterator position,size_type n,const T& x){
	if(n!=0){
		if(size_type(end_of_storage-finish)>=n){
			//备用空间大于等于新增元素的个数
			T x_copy=x;
			//计算插入点之后的现有元素的个数
			const size_type elems_after=finish-position;
			iterator old_finish=finish;
			if(elems_after>n){
				//插入点之后的现有元素个数大于新增元素个数
				uninitialized_copy(finish-n,finish,finish); //向后移动n位
				finish+=n;
				copy_backward(position,old_finish-n,oldfinish);//从目的地向前拷贝，反过来 
				fill(position,position+n,x_copy);
			} 
		}
		else{
			//插入点之后现有元素个数小于新增元素个数
			uninitialized_fill_n(finish,n-elems_after,x_copy);
			finish+=n-elems_after;
			uninitialized_copy(position,old_finish.finish);
			finish+=elems_after;
			fill(position,old_position,x_copy);
		} 
	}
	else{
		//备用空间小于新增元素个数，那就必须配置额外的内存
		//首先决定新长度：旧长度的两倍，或者旧长度+新增元素个数
		const size_type old_size=size();
		const size_type len=old_size+max(old_size,n);
		//配置vector空间
		iterator new_start=data_allocater::allocate(len); 
		iterator new_finish=new_start;
		__STL_TRY{
			//首先将旧的vector的插入点之前的元素复制到新空间
			new_finish=uninitialized_fill_n(new_finish,n,x); 
			//再将新元素初值为n填入新空间
			new_finish=uninitialized_fill_n(new_finish,n,x);
			//再将旧的vector插入点之后的元素复制到新空间
			new_finish=uninitialized_copy(position,finish,new_finish);
		}
	#ifdef __STL_USE_EXCEPTIONS
		catch(...){
			//如果有异常，实现"commit or rollback" semantics
			destroy(new_start,new_finish);
			data_allocator::deallocate(new_start,len);
			throw;
		}
	#endif
	//以下清除并释放旧的vector
	destroy(start,finish);
	deallocate();
	start=new_start;
	finish=new_finish;
	end_of_storage=new_start+len; 
	}
}


