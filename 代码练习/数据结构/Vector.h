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
