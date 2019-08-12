/*Vector模板类*/
typedef int Rank;//秩
#define DEFAULT_CAPACITY 3 //默认初始容量

template<typename T> 
class Vector{
protected:
	Rank _size;int _capacity;T* _elem;//规模，容量，数据区
	void copyFrom(T const* A,Rank lo,Rank hi);
	void expand();//空间不足时扩容
	void shrink();//装填因子过小时 
	Rank bubble(Rank lo,Rank hi);//扫描交换
	void bubbleSort(Rank lo,Rank hi);//冒泡排序
	Rank max(Rank lo,Rank hi);//选取最大元素
	void selectionSort(Rank lo,Rank hi);//选择排序
	void mergeSort(Rank lo,Rank hi); 
	void merge(Rank lo,Rank mi,Rank hi);//二路归并
	Rank partition(Rank lo,Rank hi);//轴点构造算法
	void quickSort(Rank lo,Rank hi);//快速排序
	void heapSort(Rank lo,Rank hi);//堆排序 
	void permute(Vector<T> &);//随机置乱算法，使各个元素等概率出现在每一位置 
public:
	//构造函数
	Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0){//容量c，规模当前大小s，所有元素初始化为v 
		_elem=new T[_capacity=c];
		for(_size=0;_size<s;_elem[_size++]=v);
	} 
	Vector(T const* A,Rank lo,Rank hi){//数组区间复制
		copyFrom(A,lo,hi);
	}
	Vector(T const* A,Rank n){//数组区间整体复制 
		copyFrom(A,0,n);
	}
	Vector(Vector<T> const& V,Rank lo,Rank hi){//向量区间复制 
		copyFrom(V._elem,0,lo,hi);
	} 
	Vector(Vector<T> const& V){//向量整体复制 
		copyFrom(V._elem,0,V._size);
	} 
	//析构函数
	~Vector(){
		delete []_elem;
	} 
	//只读访问接口
	Rank size() const{return _size;}
	bool empty() const{return !_size;}
	int disordered() const;//判断向量是否已经排序
	Rank find(T const& e) const{return find(e,0,(Rank)_size);} //无序向量整体查找
	Rank find(T const&e,Rank lo,Rank hi) const;//无序向量区间查找 
	Rank search(T const& e) const{//有序向量整体查找 
		return (0>=_size)?-1:search(e,(Rank)0,(Rank)_size);
	}
	Rank search(T const& e,Rank lo,Rank hi) const;//有序向量区间查找
	//可写访问接口
	T& operator[](Rank r) const;
	Vector<T>& operator=(Vector<T> const&);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e); 
	Rank insert(T const& e) { return insert(_size, e); } 
	void sort(Rank lo, Rank hi); //对[lo, hi)排序
	void sort() { sort(0, _size); } //整体排序
	void unsort(Rank lo, Rank hi); //对[lo, hi)置乱
	void unsort() { unsort(0, _size); } //整体置乱
	int deduplicate(); //无序去重
	int uniquify(); //有序去重
	// 遍历
	void traverse(void (*)(T&)); //遍历（使用函数指针，叧读戒尿部性修改）
	template <typename VST> void traverse(VST&); //遍历（使用函数对象，可全尿性修改）
}; 
