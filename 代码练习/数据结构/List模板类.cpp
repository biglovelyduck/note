/*Listģ����*/
#include <iostream>
using namespace std; 
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*//�б���λ��(�������ĺ궨��) 
//��һ��д��
//template <typename T> typedef ListNode<T>* ListNodePosi; 

//�����б����� 
template <typename T> 
struct ListNode{//�б���ģ���࣬��˫������ʵ�� 
	//��Ա
	T data;					//��ֵ 
	ListNodePosi(T) pred; 	//ǰ��
	ListNodePosi(T) succ;	//���
	//���캯��
	ListNode(){}		//���header��trailer�Ĺ���
	ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T) s=NULL)
	:data(e),pred(p),succ(s){}
	//�����ӿ�
	ListNodePosi(T) insertAsPred(T const &e);//��ǰ���֮ǰ�����½��
	ListNodePosi(T) insertAsSucc(T const& e);// ǰ���֮������½��
};

//Listģ����
template <typename T>
class List{
private:
	int _size;					//��ģ 
	ListNodePosi(T) header;		//ͷ�ڱ� 
	ListNodePosi(T) trailer;	//β�ڱ�
protected:
	void init();//�б���ʱ�ĳ�ʼ��
	int clear();//������н��
	void copyNodes(ListNodePosi(T),int);//�����б�����p���n�� 
	void merge(ListNodePosi(T)&,int,List<T>&,ListNodePosi(T),int);//�����б�����鲢��ʹ����ָ�������
	void selectionSort(ListNodePosi(T),int);//��p��ʼ������n�����ѡ������
	void mergeSort(ListNodePosi(T),int);//�鲢����
	void insertionSort(ListNodePosi(T),int);//�������� 
public:
	//���캯��
	List(){//Ĭ��
		init();
	}
	List(List<T> const& L);//����
	List(List<T> const& L,Rank r,int n);//�����б�L�Ե�r�ʼ��n��
	List(ListNodePosi(T) p,int n);//�����б�����λ��p��ʼ��n��
	//��������
	~List();//�ͷŰ���ͷβ�ڱ����ڵ����н��
	//ֻ�����ʽӿ�
	Rank size() const{return _size;}
	bool empty() const{return _size<=0;}
	T& operator[](int r) const;//���أ�ʹ֧��Ѱ�ȷ��ʣ�Ч�ʵͣ�
	ListNodePosi(T) first() const{return header->succ;}// �׽ڵ�λ��
	ListNodePosi(T) last() const{return trailer->pred;}
	bool valid(ListNodePosi(T) p){//�ж�λ��p�Ƿ����Ϸ� 
		return p&&(trailer!=p)&&(header!=p);
	}
	int disordered() const;//�ж��б��Ƿ��Ѿ�����
	ListNodePosi(T) find(T const &e) const{//�����б���� 
		return find(e,_size,trailer);
	}
	ListNodePosi(T) find(T const &e,int n,ListNodePosi(T) p) const;//�����б��������
	ListNodePosi(T) search(T const &e){//�����б���� 
		return search(e,_size,trailer);
	} 
	ListNodePosi(T) search(T const &e,int n,ListNodePosi(T) p) const;//�����б��������
	ListNodePosi(T) selectMax(ListNodePosi(T) p,int n);//��p����ǰn-1�������ѡ�������
	ListNodePosi(T) selectMax(){//��������� 
		return selectMax(header->succ,_size);
	} 
	// ��д���ʽӿ�
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ���� 
	ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ���� 
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e); //��e����p��ǰ������ 
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e); //��e����p�ĺ�̲��� 
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p�Ľ�㣬���ر�ɾ����� 
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); } //ȫ�б�鲢 
	void sort(ListNodePosi(T) p, int n); //�б���������
	void sort() { sort(first(), _size); } //�б���������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
	void reverse(); //ǰ���ã�ϰ�⣩
	// ����
	void traverse(void (*)(T&)); //������һ��ʵʩvisit���� ������ָ�룬ֻ����ֲ����޸ģ� 
	template <typename VST> //������
	void traverse(VST&); //����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�
}; 

//��ʼ��
template <typename T> 
void List<T>::init() { //�б��ʼ�����ڴ����б����ʱͳһ����
	header = new ListNode<T>; //����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>; //����β�ڱ��ڵ�
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0; //��¼��ģ
}

//�ȵ�λ�õ�ת��
template <typename T>
T& List<T>::operator[](Rank r) const{
	ListNodePosi(T) p=first();
	while(0<r--) p=p->succ;
	return p->data;
} 

//���� 
template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�����e�������
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const { //0<=n<=rank(p)<_size
	while (0 < n--) //��ءp�m����mn��ǰ������������
	if (e == (p = p->pred)->data) return p; //����ȶԣ�ֱ�����н䷶ΧԽ��
	return NULL; //pԽ����߽���ζ�ų׼���آ��e������ʧ��
} //ʧ��ʱ������NULL

//����
template <typename T> 
ListNodePosi(T) List<T>::insertAsFirst(T const& e)//e���׽ڵ���� 
{ 
	_size++; 
	return header->insertAsSucc(e); 
} 
template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{ _size++; return trailer->insertAsPred(e); } //e��ĩ�ڵ����

template <typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)
{ _size++; return p->insertAsPred(e); } //e��pǰ������ 

template <typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)
{ _size++; return p->insertAsSucc(e); } //e��p�m�̲���

//ǰ����
template <typename T> 
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this); //������ǰ���ڵ�
	pred->succ = x; pred = x; //������������
	return x; //�����½ڵ�mλ��
}

//�����
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	//succδ֪ 
	ListNodePosi(T) x = new ListNode(e, this, succ); //�����½ڵ�
	succ->pred = x; succ = x; //������������
	return x; //�����½ڵ�mλ��
}

//���ƵĹ���
template <typename T> //�б��ڲ������������б�����λ��p��mn��
void List<T>::copyNodes(ListNodePosi(T) p, int n) { //p�Ϸ�����������n-1�����̽ڵ�
	init(); //����ͷ��β�ڱ��ڵ�����_ʼ��
	while(n--) { insertAsLast(p->data); p = p->succ; } //������p�mn��������Ϊĩ�ڵ�I��
} 

//ɾ��
template <typename T>
T List<T>::remove(ListNodePosi(T) p){//ɾ�����p ,���ر�ɾ������ֵ 
	T e=p->data;//���ݴ�ɾ���Ľ�� 
	p->pred->succ=p->succ;
	p->succ->pred=p->pred;
	delete p;
	_size--;
	return e; 
}

//����
template <typename T>
List<T>::~List(){//����б��ͷ�ͷβ�ڱ� 
	clear();
	delete header;
	delete trailer; 
} 
template <typename T>
int List<T>::clear(){
	int oldSize=_size;
	while(0<_size){//����ɾ���׽ڵ㣬ֱ���б��� 
		remove(header->succ); 
	}
	return oldSize;
} 

//�����б�Ψһ��
template <typename T>
int List<T>::deduplicate(){
	if(_size<2) return;//ƽ���б���Ȼ���ظ�
	int oldSize=_size;
	ListNodePosi(T) p=first();//p���׽ڵ㿪ʼ
	Rank r=1;
	while(trailer!=(p=p->succ)){
		ListNodePosi(T) q=find(p->data,r,p);//��p��r��ǰ���У�������֮��ͬ�� 
		q?remove(q):r++; 
	}
	return oldSize-_size; //���ر�ɾ���� 
}

//�����б�Ψһ��
template <typename T>
int List<T>::uniquify(){//�����޳��ظ�Ԫ�� 
	if(_size<2) return 0;
	int oldSize=_size;
	ListNodePosi(T) p=first();//pΪ��������� 
	ListNodePosi(T) q;//qΪ����
	while(trailer!=(q=p->succ))//����������ڵĽڵ��(p,q)
		if(p->data!=q->data) p=q;
		else remove(q);
	return oldSize-_size; 
}

//�����б�Ĳ���
template <typename T>
ListNodePosi(T) List<T>::search(T const &e,int n,ListNodePosi(T) p) const{
	while(0<=n--){
		if(((p=p->pred)->data)<=e) break;//���� 
	}
	return p;
} 

//ѡ������,���б���ʼ��λ��p��n��Ԫ����ѡ������ 
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p,int n){
	ListNodePosi(T) head=p.pred;
	ListNodePosi(T) tail=p;//����������(head,tail)
	for(int i=0;i<n;i++) tail=tail->succ;//head/tail������ͷβ�ڱ�
	while(1<n){//�����ҳ������������ڵ�����ߣ���������������ĺ��
		insertBefore(tail,remove(selectMax(head->succ,n))); 
		tail=tail->pred;
		n--;
		
	} 
} 

//�ҵ������
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p,int n){
	ListNodePosi(T) max=p;
	for(ListNodePosi(T) cur=p;1<n;n--){//��������һ��max�Ƚ� 
		if(!lt((cur=cur->succ)->data),max->data)
			max=cur; 
	}
	return max;
} 

//��������,���б�����ʼ��λ��p������n��Ԫ������������ 
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p,int n){
	for(int r=0;r<n;r++){//r�����Ѿ������ǰ׺�ĳ��� 
		insertAfter(search(p->data,r,p),p->data);//����+����
		p=p->succ;//p��Ȼ�Ǻ�׺���׽ڵ� 
		remove(p->pred);//ת����һ���ڵ� 
	} 
} 

int main(){
	return 0;
}
