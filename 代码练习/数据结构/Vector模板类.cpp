#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*Vectorģ����*/
typedef int Rank;//��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ����

template<typename T> 
class Vector{
protected:
	Rank _size;int _capacity;T* _elem;//��ģ��������������
	void copyFrom(T const* A,Rank lo,Rank hi);
	void expand();//�ռ䲻��ʱ����
	void shrink();//װ�����ӹ�Сʱ 
	Rank bubble(Rank lo,Rank hi);//ɨ�轻��
	void bubbleSort(Rank lo,Rank hi);//ð������
	Rank max(Rank lo,Rank hi);//ѡȡ���Ԫ��
	void selectionSort(Rank lo,Rank hi);//ѡ������
	void mergeSort(Rank lo,Rank hi); 
	void merge(Rank lo,Rank mi,Rank hi);//��·�鲢
	Rank partition(Rank lo,Rank hi);//��㹹���㷨
	void quickSort(Rank lo,Rank hi);//��������
	void heapSort(Rank lo,Rank hi);//������ 
	void permute(Vector<T> &);//��������㷨��ʹ����Ԫ�صȸ��ʳ�����ÿһλ�� 
public:
	//���캯��
	Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0){//����c����ģ��ǰ��Сs������Ԫ�س�ʼ��Ϊv 
		_elem=new T[_capacity=c];
		for(_size=0;_size<s;_elem[_size++]=v);
	} 
	Vector(T const* A,Rank lo,Rank hi){//�������临��
		copyFrom(A,lo,hi);
	}
	Vector(T const* A,Rank n){//�����������帴�� 
		copyFrom(A,0,n);
	}
	Vector(Vector<T> const& V,Rank lo,Rank hi){//�������临�� 
		copyFrom(V._elem,0,lo,hi);
	} 
	Vector(Vector<T> const& V){//�������帴�� 
		copyFrom(V._elem,0,V._size);
	} 
	//��������
	~Vector(){
		delete []_elem;
	} 
	//ֻ�����ʽӿ�
	Rank size() const{return _size;}
	bool empty() const{return !_size;}
	int disordered() const;//�ж������Ƿ��Ѿ�����
	Rank find(T const& e) const{return find(e,0,(Rank)_size);} //���������������
	Rank find(T const&e,Rank lo,Rank hi) const;//��������������� 
	Rank search(T const& e) const{//��������������� 
		return (0>=_size)?-1:search(e,(Rank)0,(Rank)_size);
	}
	Rank search(T const& e,Rank lo,Rank hi) const;//���������������
	//��д���ʽӿ�
	T& operator[](Rank r) const;
	Vector<T>& operator=(Vector<T> const&);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e); 
	Rank insert(T const& e) { return insert(_size, e); } 
	void sort(Rank lo, Rank hi); //��[lo, hi)����
	void sort() { sort(0, _size); } //��������
	void unsort(Rank lo, Rank hi); //��[lo, hi)����
	void unsort() { unsort(0, _size); } //��������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
	// ����
	void traverse(void (*)(T&)); //������ʹ�ú���ָ�룬�����������޸ģ�
	template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; 

//����ָ������������ 
template <typename T> //Ԫ������
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) { 
	_elem = new T[_capacity = 2 * (hi - lo)]; 
	_size = 0; 
	while (lo < hi) 
		_elem[_size++] = A[lo++]; 
}

//����=����� 
template <typename T> 
Vector<T>& Vector<T>::operator=(Vector<T> const& V ) { //���ظ�ֵ������
	if (_elem) 
		delete [] _elem; //�ͷ�ԭ������
	copyFrom(V._elem, 0, V.size());
	return *this; 
}

//����
template <typename T>
void Vector<T>::expand(){
	if(_size<_capacity) return;//��δ��Ա����������
	if(_capacity<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY;//��������С����
	T *oldElem=_elem;
	_elem=new T[_capacity<<=1];//�����ӱ�
	for(int i=0;i<_size;i++){
		_elem[i]=oldElem[i];//��ԭ 
	}
	delete []oldElem;//�ͷ�ԭ�ռ� 
} 

//����
template <typename T>
void Vector<T>::shrink(){
	if(_capacity<DEFAULT_CAPACITY<<1) return;//�ϸ񣬲���Ҫ���� 
	if(_size<<2>_capacity) return;//��25%Ϊ�磬�ϸ񣬲���Ҫ���� 
	T *oldElem=_elem;
	_elem=new T[_capacity>>=1];//��������
	for(int i=0;i<_size;i++) _elem[i]=oldElem[i];
	delete []oldElem; 
} 

//����[]�����
template <typename T>
T& Vector<T>::operator[](Rank r) const{
	return _elem[r];
} 

//�����㷨
template <typename T>
void permute(Vector<T> &V){
	for(int i=V.size();i>0;i--){
		//�����swap()����std::��׼���ʿռ��еġ� 
		swap(V[i-1],V[rand()%i]);
	}
}

//�������ҽӿ�
template <typename T>
void Vector<T>::unsort(Rank lo,Rank hi){
	T *V=_elem+lo;
	for(Rank i=hi-lo;i>0;i--){
		swap(V[i-1],V[rand()%i]);
	}
} 

//�ȶԺͱȽ��������� 
template <typename T> static bool lt(T* a, T* b) { return lt(*a, *b); } //less than
template <typename T> static bool lt(T& a, T& b) { return a < b; } //less than
template <typename T> static bool eq(T* a, T* b) { return eq(*a, *b); } //equal
template <typename T> static bool eq(T& a, T& b) { return a == b; } //equal 

//��֧�ֱȶԣ���δ��֧�ֱȽϵ����������������� 
//������������Ĳ����㷨
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const{
	while((lo<hi--)&&(e!=_elem[hi]));
	return hi;
}

//�����㷨 
template <typename T>
Rank Vector<T>::insert(Rank r,T const& e){
	expand();//���б�Ҫ������
	for(int i=_size;i>r;i--){
		_elem[i]=_elem[i-1];
	} 
	_elem[r]=e;
	return r;
}

//ɾ�������㷨
template <typename T> 
int Vector<T>::remove(Rank lo, Rank hi) { 
	if (lo == hi) return 0; //����Ч�ʿ��ǣ����������˻���� 
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo; 
	shrink();
	return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ 
} 

//��Ԫ��ɾ��
template <typename T> 
T Vector<T>::remove(Rank r) { 
	T e = _elem[r]; 
	remove(r, r + 1);
	return e;//���ر�ɾ��Ԫ�� 	
} 

//Ψһ���㷨
template <typename T>
int Vector<T>::deduplicate(){
	int oldSize=_size;
	Rank i=1;
	while(i<_size){
		(find(_elem[i],0,i)<0)?i++:remove(i);
	}
	return oldSize-_size;
} 

//�����ӿ�
template <typename T>
void Vector<T>::traverse(void (*visit)(T&)){//���ú���ָ����Ƶı��� 
	for(int i=0;i<_size;i++) visit(_elem[i]); 
} 
template <typename T> template <typename VST>//Ԫ�����ͣ�������
void Vector<T>::traverse(VST& visit){//����������Ƶı��� ����Ϊ���ƺ����Ķ��� 
	for(int i=0;i<_size;i++) visit(_elem[i]); //���أ�������� 
}

//�����������ʽָ����������������һ��T�����
template <typename T> 
struct Increase{
	virtual void operator()(T& e){
		e++;
	}
};
template <typename T>
void increase(Vector<T> &V){//ͬһ����������Ԫ�� 
	V.traverse(Increase<T>()); 
}

//���������
template <typename T>
int Vector<T>::disordered() const{//�����������������ڶԵ����� 
	int n=0;
	for(int i=1;i<_size;i++){
		if(_elem[i-1]>_elem[i]) n++;
	}
	return n;//�������򣨴�С���󣩷���0 
}

//Ψһ������Ч�棩
/*template <typename T> 
int Vector<T>::uniquify() { 
	int oldSize = _size; 
	int i = 0; 
	while (i < _size - 1) 
		(_elem[i] == _elem[i + 1]) ? remove(i + 1) : i++; 
	return oldSize - _size; //���ر�ɾ��Ԫ�ص����� 
} */
//Ψһ������Ч�棩
template <typename T>
int Vector<T>::uniquify(){
	Rank i = 0, j = 0; //���Ի�������Ԫ�ص��� 
	while (++j < _size) 
		if (_elem[i] != _elem[j]) 
			_elem[++i] = _elem[j]; 
	_size = ++i; 
	shrink();
	return j - i; //���ر�ɾ��Ԫ�ص����� 
}

//���ֲ��ҸĽ���(ֻ�Ƚ�һ��)
template <typename T>
static Rank binSearch(T* A,T const &e,Rank lo,Rank hi){
	while(1<hi-lo){
		Rank mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi;
	}
	return (e==A[lo])?lo:-1;//��������Ԫ�ص��Ȼ���-1 
} 

//ð�������ռ��Ľ��� 
template <typename T>
void Vector<T>::bubbleSort(Rank lo,Rank hi){
	while(lo<(hi=bubble(lo,hi)));//��ͣ������ 
}
template <typename T>
Rank Vector<T>::bubble(Rank lo,Rank hi){
	Rank last=lo;
	while(++lo<hi)//�������ң��������������Ԫ��
		if(_elem[lo-1]>_elem[lo]){
			last=lo;//��������������Ҳ������λ�ü�¼
			swap(_elem[lo-1],_elem[lo]);
		}
	return last;//�������Ҳ�����Ե�λ�� 
} 

//�鲢����
template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi){
	if(hi-lo<2) return;
	int mi=(lo+hi)/2;
	mergeSort(lo,mi);//��ǰ������� 
	mergeSort(mi,hi);//�Ժ������� 
	merge(lo,mi,hi);//��·�鲢 
} 
template <typename T>
void Vector<T>::merge(Rank lo,Rank mi,Rank hi){
	T *A=_elem+lo;//�ϲ��������A[0,hi-lo)=_elem[lo,hi) 
	int lb=mi-lo; T *B=new T[lb];//ǰ������B[0,lb]=_elem[lo,mi]
	for(Rank i=0;i<lb;B[i]=A[i++]);//����ǰ������B
	int lc=hi-mi; T *C=_elem+mi;//��������C[0,lc)=_elem[mi,hi)
	for(Rank i=0,j=0,k=0;(j<lb)||(k<lc);){//B[j]��C[k]��С��ת��A��ĩβ 
		if((j<lb)&&(lc<=k||(B[j]<=C[k]))) A[i++]=B[j++];
		if((k<lc)&&(lb<=j||(C[k]<B[j]))) A[i++]=C[k++];
	}
	delete []B; 
} 

int main(){
	return 0;
} 
 
