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

//����
template <class T>
struct iterator_traits{
	//...
	typedef typename I::difference_type difference_type;//�������Ŀ�� 
}; 

//���ԭ��ָ����Ƶ�ƫ�ػ�
template <class T>
struct iterator_traits<T*>{
	//...
	typedef ptrdiff_t difference_type;
};  

//���ԭ����pointer-to-const����Ƶ�ƫ�ػ�
template <class T>
struct iterator_traits<const T*>{
	//...
	typedef ptrdiff difference_type;
}; 

//����reference type �� pointer type������Ӧ�Ա����traits��
//����
template <class T>
struct iterator_traits{
	//...
	typedef typename I::difference_type difference_type;
	
	typedef typename I::pointer pointer;
	typedef typename I::reference reference;
}; 

//���ԭ��ָ����Ƶ�ƫ�ػ�
template <class T>
struct iterator_traits<T*>{
	//...
	typedef ptrdiff_t difference_type;
	
	typedef T* pointer;
	typedef T& reference;
};  

//���ԭ����pointer-to-const����Ƶ�ƫ�ػ�
template <class T>
struct iterator_traits<const T*>{
	//...
	typedef ptrdiff difference_type;
	
	typedef const T* pointer;
	typedef const T& reference;
}; 
