//vector
//alloc��SGI STL�Ŀռ�������
template <class T,class Alloc=alloc>
class vector{
public:
	//vector��Ƕ���ͱ���
	typedef T			value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;
protected:
	//�ռ�������
	typedef simple_alloc<value_type,Alloc> data_allocator;
	iterator start;		//��ʾĿǰʹ�ÿռ��ͷ
	iterator finish;	//��ʾĿǰʹ�ÿռ��β
	iterator end_of_storage;//��ʾĿǰ���ÿռ��β
	
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
	
	//���캯��
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
	//���[fisrst��last)���е�Ԫ�� 
	iterator erase(iterator first,iterator last){
		iterator i=copy(last,finish,first);
		destroy(i,finish);
		finish=finish-(last-first);
		return first;
	}
	//���ĳ��λ�õ�Ԫ�� 
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
	//���ÿռ䲢����������
	iterator allocate_and_fill(size_type n,const T& x){
		iterator result=data_allocator::allocate(n);
		unitialized_fill_n(result,n,x);
	} 
}; 

template<class T,class Alloc>
void vector<T,Alloc>::insert_aux(iterator position,const T& x){
	if(finish!=end_of_storage){
		//���б��ÿռ�,�ڱ��ÿռ���ʼ������һ��Ԫ�أ�����vector���һ��Ԫ��ֵΪ���ֵ 
		construct(finish,*(finish-1)); 
		++finish��
		T x_copy=x;
		copy_backward(position,finish-2,finish-1);//stl�㷨֮�������Ӻ���ǰ���� 
		*position=x_copy; 
	}
	else{
		//�Ѿ�û�б��ÿռ� 
		const size_type old_size=size();
		const size_type len=old_szie!=0?2*old_size:1;
		iterator new_start=data_allocator::allocate(len);//ʵ������
		iterator new_finish=new_start;
		try{
			//��ԭvector�����ݿ������µ�vector
			new_finish=uninitialized_copy(start,position,new_start);
			//Ϊ��Ԫ���趨��ֵx
			construct(new_finish,x);
			++new_finish;
			new_finish=unitialized_copy(position,finish,new_finish); 
		} 
		catch(...){
			destroy(new_start,new_finish);
			data_allocator::deallocate(new_start,len);
			throw; 
		}
		//�������ͷ�ԭ����vector
		destroy(begin(),end());
		deallocate(); 
		
		//������������ָ���µ�vector
		start-new_start;
		finish=new_finish;
		end_of_storage=new_start+len; 
	}
}

template <class T,class Alloc>
void vector<T,Alloc>::insert(iterator position,size_type n,const T& x){
	if(n!=0){
		if(size_type(end_of_storage-finish)>=n){
			//���ÿռ���ڵ�������Ԫ�صĸ���
			T x_copy=x;
			//��������֮�������Ԫ�صĸ���
			const size_type elems_after=finish-position;
			iterator old_finish=finish;
			if(elems_after>n){
				//�����֮�������Ԫ�ظ�����������Ԫ�ظ���
				uninitialized_copy(finish-n,finish,finish); //����ƶ�nλ
				finish+=n;
				copy_backward(position,old_finish-n,oldfinish);//��Ŀ�ĵ���ǰ������������ 
				fill(position,position+n,x_copy);
			} 
		}
		else{
			//�����֮������Ԫ�ظ���С������Ԫ�ظ���
			uninitialized_fill_n(finish,n-elems_after,x_copy);
			finish+=n-elems_after;
			uninitialized_copy(position,old_finish.finish);
			finish+=elems_after;
			fill(position,old_position,x_copy);
		} 
	}
	else{
		//���ÿռ�С������Ԫ�ظ������Ǿͱ������ö�����ڴ�
		//���Ⱦ����³��ȣ��ɳ��ȵ����������߾ɳ���+����Ԫ�ظ���
		const size_type old_size=size();
		const size_type len=old_size+max(old_size,n);
		//����vector�ռ�
		iterator new_start=data_allocater::allocate(len); 
		iterator new_finish=new_start;
		__STL_TRY{
			//���Ƚ��ɵ�vector�Ĳ����֮ǰ��Ԫ�ظ��Ƶ��¿ռ�
			new_finish=uninitialized_fill_n(new_finish,n,x); 
			//�ٽ���Ԫ�س�ֵΪn�����¿ռ�
			new_finish=uninitialized_fill_n(new_finish,n,x);
			//�ٽ��ɵ�vector�����֮���Ԫ�ظ��Ƶ��¿ռ�
			new_finish=uninitialized_copy(position,finish,new_finish);
		}
	#ifdef __STL_USE_EXCEPTIONS
		catch(...){
			//������쳣��ʵ��"commit or rollback" semantics
			destroy(new_start,new_finish);
			data_allocator::deallocate(new_start,len);
			throw;
		}
	#endif
	//����������ͷžɵ�vector
	destroy(start,finish);
	deallocate();
	start=new_start;
	finish=new_finish;
	end_of_storage=new_start+len; 
	}
}


