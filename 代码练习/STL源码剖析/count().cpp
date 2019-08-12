//difference type 
template <class I,class T>
typename iterator_traits<I>::difference_type
count(I first,I last,const T& value){
	typename iterator_traits<I>::difference_type n=0;
	for(;first!=last;++first){
		if(*first==value) ++n;
	}
	return n;
}

//正常
template <class T>
struct iterator_traits{
	//...
	typedef typename I::difference_type difference_type;//迭代器的宽度 
}; 

//针对原生指针设计的偏特化
template <class T>
struct iterator_traits<T*>{
	//...
	typedef ptrdiff_t difference_type;
};  

//针对原生的pointer-to-const而设计的偏特化
template <class T>
struct iterator_traits<const T*>{
	//...
	typedef ptrdiff difference_type;
}; 

//加入reference type 和 pointer type两个相应性别加入traits内
//正常
template <class T>
struct iterator_traits{
	//...
	typedef typename I::difference_type difference_type;
	
	typedef typename I::pointer pointer;
	typedef typename I::reference reference;
}; 

//针对原生指针设计的偏特化
template <class T>
struct iterator_traits<T*>{
	//...
	typedef ptrdiff_t difference_type;
	
	typedef T* pointer;
	typedef T& reference;
};  

//针对原生的pointer-to-const而设计的偏特化
template <class T>
struct iterator_traits<const T*>{
	//...
	typedef ptrdiff difference_type;
	
	typedef const T* pointer;
	typedef const T& reference;
}; 
