/*List模板类*/
#include <iostream>
using namespace std; 
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*//列表结点位置(带参数的宏定义) 
//另一种写法
//template <typename T> typedef ListNode<T>* ListNodePosi; 

//声明列表结点类 
template <typename T> 
struct ListNode{//列表结点模板类，以双向链表实现 
	//成员
	T data;					//数值 
	ListNodePosi(T) pred; 	//前驱
	ListNodePosi(T) succ;	//后继
	//构造函数
	ListNode(){}		//针对header和trailer的构造
	ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T) s=NULL)
	:data(e),pred(p),succ(s){}
	//操作接口
	ListNodePosi(T) insertAsPred(T const &e);//当前结点之前插入新结点
	ListNodePosi(T) insertAsSucc(T const& e);// 前结点之后插入新结点
};

//List模板类
template <typename T>
class List{
private:
	int _size;					//规模 
	ListNodePosi(T) header;		//头哨兵 
	ListNodePosi(T) trailer;	//尾哨兵
protected:
	void init();//列表创建时的初始化
	int clear();//清除所有结点
	void copyNodes(ListNodePosi(T),int);//复制列表中自p起的n项 
	void merge(ListNodePosi(T)&,int,List<T>&,ListNodePosi(T),int);//有序列表区间归并，使用了指针的引用
	void selectionSort(ListNodePosi(T),int);//从p开始连续的n个结点选择排序
	void mergeSort(ListNodePosi(T),int);//归并排序
	void insertionSort(ListNodePosi(T),int);//插入排序 
public:
	//构造函数
	List(){//默认
		init();
	}
	List(List<T> const& L);//复制
	List(List<T> const& L,Rank r,int n);//复制列表L自第r项开始的n项
	List(ListNodePosi(T) p,int n);//复制列表中自位置p开始的n项
	//析构函数
	~List();//释放包含头尾哨兵在内的所有结点
	//只读访问接口
	Rank size() const{return _size;}
	bool empty() const{return _size<=0;}
	T& operator[](int r) const;//重载，使支持寻秩访问（效率低）
	ListNodePosi(T) first() const{return header->succ;}// 首节点位置
	ListNodePosi(T) last() const{return trailer->pred;}
	bool valid(ListNodePosi(T) p){//判断位置p是否对外合法 
		return p&&(trailer!=p)&&(header!=p);
	}
	int disordered() const;//判断列表是否已经有序
	ListNodePosi(T) find(T const &e) const{//无序列表查找 
		return find(e,_size,trailer);
	}
	ListNodePosi(T) find(T const &e,int n,ListNodePosi(T) p) const;//无序列表区间查找
	ListNodePosi(T) search(T const &e){//有序列表查找 
		return search(e,_size,trailer);
	} 
	ListNodePosi(T) search(T const &e,int n,ListNodePosi(T) p) const;//有序列表区间查找
	ListNodePosi(T) selectMax(ListNodePosi(T) p,int n);//在p及其前n-1个后继中选出最大者
	ListNodePosi(T) selectMax(){//整体最大者 
		return selectMax(header->succ,_size);
	} 
	// 可写访问接口
	ListNodePosi(T) insertAsFirst(T const& e); //将e当做首节点插入 
	ListNodePosi(T) insertAsLast(T const& e); //将e当做末节点插入 
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e); //将e当做p的前驱插入 
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e); //将e当作p的后继插入 
	T remove(ListNodePosi(T) p); //删除合法位置p的结点，返回被删除结点 
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); } //全列表归并 
	void sort(ListNodePosi(T) p, int n); //列表区间排序
	void sort() { sort(first(), _size); } //列表整体排序
	int deduplicate(); //无序去重
	int uniquify(); //有序去重
	void reverse(); //前后倒置（习题）
	// 遍历
	void traverse(void (*)(T&)); //遍历，一次实施visit操作 （函数指针，只读或局部性修改） 
	template <typename VST> //操作器
	void traverse(VST&); //遍历，依次实施visit操作（函数对象，可全局性修改）
}; 

//初始化
template <typename T> 
void List<T>::init() { //列表初始化，在创建列表对象时统一调用
	header = new ListNode<T>; //创建头哨兵节点
	trailer = new ListNode<T>; //创建尾哨兵节点
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0; //记录规模
}

//秩到位置的转换
template <typename T>
T& List<T>::operator[](Rank r) const{
	ListNodePosi(T) p=first();
	while(0<r--) p=p->succ;
	return p->data;
} 

//查找 
template <typename T> //在无序列表内节点p（可能是trailer）的n个（真）前驱中，找到等于e的最后者
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const { //0<=n<=rank(p)<_size
	while (0 < n--) //对亍p癿最近癿n个前驱，从右向左
	if (e == (p = p->pred)->data) return p; //逐个比对，直至命中戒范围越界
	return NULL; //p越出左边界意味着匙间内丌含e，查找失败
} //失败时，返回NULL

//插入
template <typename T> 
ListNodePosi(T) List<T>::insertAsFirst(T const& e)//e作首节点插入 
{ 
	_size++; 
	return header->insertAsSucc(e); 
} 
template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{ _size++; return trailer->insertAsPred(e); } //e作末节点插入

template <typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)
{ _size++; return p->insertAsPred(e); } //e作p前驱插入 

template <typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)
{ _size++; return p->insertAsSucc(e); } //e作p癿继插入

//前插入
template <typename T> 
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this); //创建新前驱节点
	pred->succ = x; pred = x; //设置正向链接
	return x; //返回新节点癿位置
}

//后插入
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	//succ未知 
	ListNodePosi(T) x = new ListNode(e, this, succ); //创建新节点
	succ->pred = x; succ = x; //设置逆向链接
	return x; //返回新节点癿位置
}

//复制的构造
template <typename T> //列表内部方法：复制列表中自位置p起癿n顷
void List<T>::copyNodes(ListNodePosi(T) p, int n) { //p合法，且至少有n-1个真后继节点
	init(); //创建头、尾哨兵节点幵做刜始化
	while(n--) { insertAsLast(p->data); p = p->succ; } //将起自p癿n顷依次作为末节点揑入
} 

//删除
template <typename T>
T List<T>::remove(ListNodePosi(T) p){//删除结点p ,返回被删除结点的值 
	T e=p->data;//备份待删除的结点 
	p->pred->succ=p->succ;
	p->succ->pred=p->pred;
	delete p;
	_size--;
	return e; 
}

//析构
template <typename T>
List<T>::~List(){//清空列表，释放头尾哨兵 
	clear();
	delete header;
	delete trailer; 
} 
template <typename T>
int List<T>::clear(){
	int oldSize=_size;
	while(0<_size){//反复删除首节点，直至列表变空 
		remove(header->succ); 
	}
	return oldSize;
} 

//无序列表唯一化
template <typename T>
int List<T>::deduplicate(){
	if(_size<2) return;//平凡列表自然无重复
	int oldSize=_size;
	ListNodePosi(T) p=first();//p从首节点开始
	Rank r=1;
	while(trailer!=(p=p->succ)){
		ListNodePosi(T) q=find(p->data,r,p);//在p的r个前驱中，查找与之雷同者 
		q?remove(q):r++; 
	}
	return oldSize-_size; //返回被删除数 
}

//有序列表唯一化
template <typename T>
int List<T>::uniquify(){//成批剔除重复元素 
	if(_size<2) return 0;
	int oldSize=_size;
	ListNodePosi(T) p=first();//p为各区段起点 
	ListNodePosi(T) q;//q为其后继
	while(trailer!=(q=p->succ))//反复考察紧邻的节点对(p,q)
		if(p->data!=q->data) p=q;
		else remove(q);
	return oldSize-_size; 
}

//有序列表的查找
template <typename T>
ListNodePosi(T) List<T>::search(T const &e,int n,ListNodePosi(T) p) const{
	while(0<=n--){
		if(((p=p->pred)->data)<=e) break;//命中 
	}
	return p;
} 

//选择排序,对列表起始于位置p的n个元素做选择排序 
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p,int n){
	ListNodePosi(T) head=p.pred;
	ListNodePosi(T) tail=p;//待排序区间(head,tail)
	for(int i=0;i<n;i++) tail=tail->succ;//head/tail可能是头尾哨兵
	while(1<n){//反复找出待排序区间内的最大者，并移至有序区间的后端
		insertBefore(tail,remove(selectMax(head->succ,n))); 
		tail=tail->pred;
		n--;
		
	} 
} 

//找到最大结点
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p,int n){
	ListNodePosi(T) max=p;
	for(ListNodePosi(T) cur=p;1<n;n--){//后序结点逐一与max比较 
		if(!lt((cur=cur->succ)->data),max->data)
			max=cur; 
	}
	return max;
} 

//插入排序,对列表中起始于位置p的连续n个元素做插入排序 
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p,int n){
	for(int r=0;r<n;r++){//r就是已经排序的前缀的长度 
		insertAfter(search(p->data,r,p),p->data);//查找+插入
		p=p->succ;//p依然是后缀的首节点 
		remove(p->pred);//转向下一个节点 
	} 
} 

int main(){
	return 0;
}
