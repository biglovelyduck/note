#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

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

//拷贝指定的数组区间 
template <typename T> //元素类型
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) { 
	_elem = new T[_capacity = 2 * (hi - lo)]; 
	_size = 0; 
	while (lo < hi) 
		_elem[_size++] = A[lo++]; 
}

//重载=运算符 
template <typename T> 
Vector<T>& Vector<T>::operator=(Vector<T> const& V ) { //重载赋值操作符
	if (_elem) 
		delete [] _elem; //释放原有内容
	copyFrom(V._elem, 0, V.size());
	return *this; 
}

//扩容
template <typename T>
void Vector<T>::expand(){
	if(_size<_capacity) return;//尚未满员，不必扩容
	if(_capacity<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY;//不低于最小容量
	T *oldElem=_elem;
	_elem=new T[_capacity<<=1];//容量加倍
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];//还原 
	}
	delete []oldElem;//释放原空间 
} 

//缩容
template <typename T>
void Vector<T>::shrink(){
	if(_capacity<DEFAULT_CAPACITY<<1) return;//合格，不需要缩容 
	if(_size<<2>_capacity) return;//以25%为界，合格，不需要缩容 
	T *oldElem=_elem;
	_elem=new T[_capacity>>=1];//容量减半
	for(int i=0;i<_size;i++) _elem[i]=oldElem[i];
	delete []oldElem; 
} 

//重载[]运算符
template <typename T>
T& Vector<T>::operator[](Rank r) const{
	return _elem[r];
} 

//置乱算法
template <typename T>
void permute(Vector<T> &V){
	for(int i=V.size();i>0;i--){
		//这里的swap()是在std::标准名词空间中的。 
		swap(V[i-1],V[rand()%i]);
	}
}

//区间置乱接口
template <typename T>
void Vector<T>::unsort(Rank lo,Rank hi){
	T *V=_elem+lo;
	for(Rank i=hi-lo;i>0;i--){
		swap(V[i-1],V[rand()%i]);
	}
} 

//比对和比较两个向量 
template <typename T> static bool lt(T* a, T* b) { return lt(*a, *b); } //less than
template <typename T> static bool lt(T& a, T& b) { return a < b; } //less than
template <typename T> static bool eq(T* a, T* b) { return eq(*a, *b); } //equal
template <typename T> static bool eq(T& a, T& b) { return a == b; } //equal 

//仅支持比对，但未必支持比较的向量叫做无序向量 
//无序向量区间的查找算法
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const{
	while((lo<hi--)&&(e!=_elem[hi]));
	return hi;
}

//插入算法 
template <typename T>
Rank Vector<T>::insert(Rank r,T const& e){
	expand();//若有必要就扩容
	for(int i=_size;i>r;i--){
		_elem[i]=_elem[i-1];
	} 
	_elem[r]=e;
	return r;
}

//删除区间算法
template <typename T> 
int Vector<T>::remove(Rank lo, Rank hi) { 
	if (lo == hi) return 0; //出于效率考虑，单独处理退化情况 
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo; 
	shrink();
	return hi - lo; //返回被删除元素的数目 
} 

//单元素删除
template <typename T> 
T Vector<T>::remove(Rank r) { 
	T e = _elem[r]; 
	remove(r, r + 1);
	return e;//返回被删除元素 	
} 

//唯一化算法
template <typename T>
int Vector<T>::deduplicate(){
	int oldSize=_size;
	Rank i=1;
	while(i<_size){
		(find(_elem[i],0,i)<0)?i++:remove(i);
	}
	return oldSize-_size;
} 

//遍历接口
template <typename T>
void Vector<T>::traverse(void (*visit)(T&)){//利用函数指针机制的遍历 
	for(int i=0;i<_size;i++) visit(_elem[i]); 
} 
template <typename T> template <typename VST>//元素类型，操作器
void Vector<T>::traverse(VST& visit){//函数对象机制的遍历 ，行为类似函数的对象 
	for(int i=0;i<_size;i++) visit(_elem[i]); //重载（）运算符 
}

//函数对象的形式指定基本操作，递增一个T类对象
template <typename T> 
struct Increase{
	virtual void operator()(T& e){
		e++;
	}
};
template <typename T>
void increase(Vector<T> &V){//同一递增向量各元素 
	V.traverse(Increase<T>()); 
}

//有序性甄别
template <typename T>
int Vector<T>::disordered() const{//返回向量中逆序相邻对的总数 
	int n=0;
	for(int i=1;i<_size;i++){
		if(_elem[i-1]>_elem[i]) n++;
	}
	return n;//向量有序（从小到大）返回0 
}

//唯一化（低效版）
/*template <typename T> 
int Vector<T>::uniquify() { 
	int oldSize = _size; 
	int i = 0; 
	while (i < _size - 1) 
		(_elem[i] == _elem[i + 1]) ? remove(i + 1) : i++; 
	return oldSize - _size; //返回被删除元素的数量 
} */
//唯一化（高效版）
template <typename T>
int Vector<T>::uniquify(){
	Rank i = 0, j = 0; //各对互异相邻元素的秩 
	while (++j < _size) 
		if (_elem[i] != _elem[j]) 
			_elem[++i] = _elem[j]; 
	_size = ++i; 
	shrink();
	return j - i; //返回被删除元素的数量 
}

//二分查找改进版(只比较一次)
template <typename T>
static Rank binSearch(T* A,T const &e,Rank lo,Rank hi){
	while(1<hi-lo){
		Rank mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi;
	}
	return (e==A[lo])?lo:-1;//返回命中元素的秩或者-1 
} 

//冒泡排序终极改进版 
template <typename T>
void Vector<T>::bubbleSort(Rank lo,Rank hi){
	while(lo<(hi=bubble(lo,hi)));//不停地起泡 
}
template <typename T>
Rank Vector<T>::bubble(Rank lo,Rank hi){
	Rank last=lo;
	while(++lo<hi)//自左至右，逐个检查各对相邻元素
		if(_elem[lo-1]>_elem[lo]){
			last=lo;//若逆序，则更新最右侧逆序对位置记录
			swap(_elem[lo-1],_elem[lo]);
		}
	return last;//返回最右侧逆序对的位置 
} 

//归并排序
template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi){
	if(hi-lo<2) return;
	int mi=(lo+hi)/2;
	mergeSort(lo,mi);//对前半段排序 
	mergeSort(mi,hi);//对后半段排序 
	merge(lo,mi,hi);//二路归并 
} 
template <typename T>
void Vector<T>::merge(Rank lo,Rank mi,Rank hi){
	T *A=_elem+lo;//合并后的向量A[0,hi-lo)=_elem[lo,hi) 
	int lb=mi-lo; T *B=new T[lb];//前子向量B[0,lb]=_elem[lo,mi]
	for(Rank i=0;i<lb;B[i]=A[i++]);//复制前子向量B
	int lc=hi-mi; T *C=_elem+mi;//后子向量C[0,lc)=_elem[mi,hi)
	for(Rank i=0,j=0,k=0;(j<lb)||(k<lc);){//B[j]和C[k]中小者转至A的末尾 
		if((j<lb)&&(lc<=k||(B[j]<=C[k]))) A[i++]=B[j++];
		if((k<lc)&&(lb<=j||(C[k]<B[j]))) A[i++]=C[k++];
	}
	delete []B; 
} 

int main(){
	return 0;
} 
 
