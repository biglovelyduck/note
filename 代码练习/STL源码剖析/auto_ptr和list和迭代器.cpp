
//�򻯰��auto_ptr,����һ��������װԭ��ָ��Ķ��� 
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

//�򻯰汾��list
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
	ListItem* _next;//�������� 
};

//������
template<class Item>
struct ListIter{
	Item* ptr;//����������֮���һ����ϵ
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
		++*this;//֮ǰ��д��++ 
		return tmp;
	}
	bool operator==(const ListIter& i) const{return ptr==i.ptr;}
	bool operator!=(const ListIter& i) const{return ptr!=i.ptr;}
}; 

//ȫ�ֺ���
template <typename T>
bool operator!=(const ListItem<T>& item,T n){
	return item.value()!=n;
} 

//�������ǽ�List��find(0����ListIterճ������
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

//����Ƶ��������Ļط�ֵ�ͱ�
//������Ƕ�ͱ��ƺ��Ǹ�������
template <class T>
struct MyIter{
	typedef T value_type;//��Ƕ�ͱ�����
	T* ptr;
	MyIter(T* p=0):ptr(p){
		
	} 
	T& operator*(){
		return *ptr;
	}
};

template <class T>
typename I::value_type//�ط��ͱ������Ϲؼ���typename��ΪT��һ��template���飬���ڱ��������ֻ�֮ǰ����������Tһ����֪ 
func(I ite){
	return *ite;
}
//..
MyIter<int> ite(new int(8));
cout<<func(ite); 

//��������������֧��ԭ��ָ�붨����Ƕ�ͱ� 
template <class T>
struct iterator_traits<T*>{
	typedef T value_type;
};

template <class I>
typename iterator_traits<I>::value_type
func(I ite){
	return *ite;
}
//������ȡ��traits
template<class T>
struct iterator_traits{
	typedef typename I::iterator_categoty iterator_categoty;
	typedef typename I::value_type value_type;
	typedef typename I::difference_type deferenve_type;
	typedef typename I::pointer pointer;
	typedef typename I::reference reference;
}; 
