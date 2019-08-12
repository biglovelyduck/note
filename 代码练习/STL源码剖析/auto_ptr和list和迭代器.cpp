
//简化版的auto_ptr,这是一个用来包装原生指针的对象 
template <class T>
class auto_ptr{
public:
	explicit auto_ptr(T *p=0):pointee(p){
		
	}
	template<class U>
	auto_ptr(auto_ptr<U>& rhs):pointee(rhs.release()){
		
	}
	~auto_ptr(){
		delete pointee;
	}
	
	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs){
		if(this!=&rhs) reset(rhs.release());
		return *this;
	}
	
	T& operator*() const{return *pointee}
	T* operator->() const{return pointee}
	T* get() const{return pointee;}
private:
	T *pointee;
};

//简化版本的list
template <typename T>
eeclass List{
	void insert_front(T value);
	void insert_end(T value);
	void display(std::ostream &os=std::cout) const;
	//..
private:
	ListItem<T>* _end;
	ListItem<T>* _front;
	long _size; 
}; 

template<typename T>
class ListItem{
public:
	T value() const{return _value;}
	ListItem* next() const{return _next;}
	//...
private:
	T _value;
	ListItem* _next;//单向链表 
};

//迭代器
template<class Item>
struct ListIter{
	Item* ptr;//保持与容器之间的一个联系
	ListIter(Item *p=0):ptr(p) {
		
	}
	Item& operator*() const{return *ptr;}
	Item* operator->() const {return ptr;}
	//pre-increment operator
	ListIter& operator++(){
		ptr=ptr->next();
		return *this;
	} 
	//post-increment operator
	ListIter& operator++(int){
		ListIte tmp=*this;
		++*this;//之前重写的++ 
		return tmp;
	}
	bool operator==(const ListIter& i) const{return ptr==i.ptr;}
	bool operator!=(const ListIter& i) const{return ptr!=i.ptr;}
}; 

//全局函数
template <typename T>
bool operator!=(const ListItem<T>& item,T n){
	return item.value()!=n;
} 

//现在我们将List和find(0藉由ListIter粘合起来
void main(){
	List<int> mylist;
	
	for(int i=0;i<5;i++){
		mylist.insert_front(i);
		mylist.insert_end(i+2);
	}
	mylist.display();
	
	ListIter<ListItem<int> > begin(mylist.front());
	ListIter<ListItem<int> > end;//default 0 null
	ListIter<ListItem<int> > iter;
	
	iter=find(begin,end,3);
	if(iter==end) cout<<"not found"<<endl;
	else cout<<"found."<<iter->value()<<endl;
	
	iter=find(begin,end,7);
	if(iter==end) cout<<"not found"<<endl;
	else  cout<<"found."<<iter->value()<<endl;
} 

//如何推导出函数的回返值型别
//声明内嵌型别似乎是个好主意
template <class T>
struct MyIter{
	typedef T value_type;//内嵌型别声明
	T* ptr;
	MyIter(T* p=0):ptr(p){
		
	} 
	T& operator*(){
		return *ptr;
	}
};

template <class T>
typename I::value_type//回返型别必须加上关键词typename因为T是一个template擦书，他在编译器具现化之前，编译器对T一无所知 
func(I ite){
	return *ite;
}
//..
MyIter<int> ite(new int(8));
cout<<func(ite); 

//这样还不够，不支持原生指针定义内嵌型别 
template <class T>
struct iterator_traits<T*>{
	typedef T value_type;
};

template <class I>
typename iterator_traits<I>::value_type
func(I ite){
	return *ite;
}
//特性萃取机traits
template<class T>
struct iterator_traits{
	typedef typename I::iterator_categoty iterator_categoty;
	typedef typename I::value_type value_type;
	typedef typename I::difference_type deferenve_type;
	typedef typename I::pointer pointer;
	typedef typename I::reference reference;
}; 
