//以开链法完成的hashtable
//vector的每个元素都是一个桶，桶中可能含有许多节点 

//开链法使用质数设计表格
static const int __stl_num_prime=28;
static const unsigned long __stl_prime_list[__stl_num_primes]={
	//53开头的28个质数 
}; 
//找出上述28个指数中，最接近并且大于n的那个质数
inline unsigned long __stl_next_prime(unsigned long n){
	const unsigned long *first=__stl_prime_list;
	const unsigned long *last=__stl_prime_list+__stl_num_primes;
	const unsigned long *pos=lower_bound(first,last,n);
	return pos==last?*(last-1):*pos;
} 

//hashtable的节点定义
template <class Value>
struct __hashtable_node{
	__hash_table_node* next;
	Value val;
}; 

//hashtable的迭代器
template <class Value,class Key,class HashFcn,
			class ExtractKey,class EqualKey,class Alloc>
struct __hashtable_iterator{
	typedef hashtable<Value,Key,HashFcn,ExtractKey,EqualKey,Alloc> hashtable;
	typedef __hash_table_iterator<Value,Key,HashFcn,ExtractKey,EqualKey,Alloc> iterator;
	typedef __hash_table_const_iterator<Value,Key,HashFcn,ExtractKey,EqualKey,Alloc> const_iterator;
	typedef __hashtable_node<Value> node;
	
	typedef forward_iterator__tag iterator_category; 
	typedef Value value_type;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef Value& reference;
	typedef Value* pointer;
	
	node* cur;	//迭代器目前所指节点
	hashtable* ht;	//保持对容器的连结关系，因为肯需要从bucket跳到bucket
	
	__hashtable_iterator(node* n,hashtable* tab):cur(n),ht(tab){}
	__hashtable_iterator(){}
	reference operator*() const{return cur->val;}
	pointer operator->() const{return &(operator*());}
	iterator& operator++();
	iterator operator++(int);
	bool operator==(const iterator& it) const{return cur==it.cur;}
	bool operator!=(const iterator& it) const{return cur!=it.cur;}
}; 

//hashtable的迭代器没有后退操作，也没有逆向迭代器 
template<class V,class K,class HF,class ExK,class EqK,class A>
__hashtable_iterator<V,k,HF,ExK,A>&
__hashtable_iterator<V,K,HF,ExK,A>::operator++(){
	const node* old=cur;
	cur=cur->next;	//如果存在 就是他 
	if(!cur){
		//根据元素值，定位出下一个bucket，其起头处就是我们的目的地
		size_type bucket=ht->bkt_num(old->val);
		while(!cur&&++bucket<ht->buckets.size())
			cur=ht->buckets[bucket]; 
	}
	return *this;
}
template<class V,class K,class HF,class ExK,class EqK,class A>
inline __hashtable_iterator<V,k,HF,ExK,Eqk,A>
__hashtable_iterator<V,K,HF,ExK,A>::operator++(int){
	iterator tmp=*this;
	++*this;
	return tmp; 
} 

//hashtable的数据结构 ,声明 时已经给予默认的alloc 
template <class Value,class Key,class HashFcn,class ExtractKey,class EqualKey,class Alloc=alloc>
class hashtable;
//定义
//Value:节点的实值类型
//Key:节点的键值类型
//HashFcn:hash function的函数型别
//ExtractKey:从节点中取出键值的方法，函数或者仿函数 
//EqualKey:判断键值相同与否的方法，函数或者仿函数
//Alloc:空间配置器 
template <class Value,class Key,class HashFcn,class ExtractKey,class EqualKey,class Alloc>
class hashtable{
public:
	typedef HashFcn hasher;	//为template型别参数重新定义一个名称
	typedef EqualKey key_equal;
	typedef size_t size_type;
private:
	//以下三者都是function objects,<stl_hash_fun.h>中定义有数个
	//标准型别 如 int c-style string 等的hasher
	hasher hash;
	key_equal equals;
	ExtractKey get_key;
	
	typedef __hashtable_node<Value> node;
	typedef simple_alloc<node,Alloc> node_allocator; 
	
	vector<node*,Alloc> buckets;	//以vector完成
	size_type num_elements;
public:
	//vector大小，也就是bucket个数
	size_type bucket_count() const{return buckets.size();} 
	
	//总共可以有多少buckets
	size_type max_bucket_count() const{
		return __stl_prime_list[__stl_num_primes-1];	//4294967291
	} 
	
	//节点配置函数
	node* new_node(const value_type& obj){
		node* n=node_allocator:allocate();
		n->next=0;
		__STL_TRY{
			construct(&n->val,obj);
			return n;
		}
	} 
	//节点释放函数
	void delete_node(node* n){
		destroy(&n->val);
		node_allocator::deallocate(n);
	} 
	
	//构造函数
	hashtable(size_type n,const HashFcn& hf,EqualKey& eql)
		:has(hf),equals(,),get_key(ExtractKey()),num_elements(0){
			initialize_buckets(n);
	}
	size_type next_size(size type n) const {return __stl_next_prime(n);} 
	void initialize_buckets(size_type n){
		const size_type n_buckets=next_size(n);	//返回最接近n并大于n的质数
		buckets.reserve(n_buckets);//先保留n_buckets个元素空间
		buckets.insert(buckets.end(),n_buckets,(node*)0); 	//初始化全部填0 
		num_elements=0;
	}
	
	//复制
	void copy_from(const hashtable& ht); 
	//整体删除 
	void clear();
	
	//版本3：只接受键值
	size_type bkt_num_key(const key_type& key) const{
		return bkt_num_key(key,buckets.size();
	} 
	//版本4：接受键值和个数
	size_type bkt_num_key(const key_type& key,size_t n) const{
		return hash(key)%n;		//SGI所有内建的hash 
	} 
	//判知元素的落脚处,版本1 ，接手实值和buckets个数 
	size_type bkt_num(const value_type& obj,size_t n) const {
		return bkt_num_key(get_key(obj),n);	//调用版本4 
	}
	//版本2：只接受实值
	size_type bkt_num(const value_type& obj) const{
		return bkt_num_key(get_key(obj));	//调用版本3 
	} 
	
	//判断是否需要重建表格，如果需要就扩充
	void resize(size_type num_elements_hint);
	//在不需要重建表格的情况下插入新节点，键值不允许重复
	pair<typename hashtable<V,K,HF,Ex,Eq,A>::iterator,bool> insert_unique_noresize(const value_type& obj); 
	//在不需要重建表格的情况下插入新节点，键值允许重复
	iterator insert_equal_noresize(const value_type& obj);
	//插入操作,不允许重复 
	pair<iterator,bool> insert_unique(const value_type& obj){
		resize(num_elements+1);	//判断是否需要重建表格，如果需要就扩充
		return insert_unique_noresize(obj); 
	} 
	//插入元素，允许重复
	iterator insert_equal(const value_type &obj){
		resize(num_elements+1);	//判断是否需要重建表格，如果需要就扩充
		return insert_equal_noresize(obj); 
	} 
};

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::resize(size_type num_elements_hint){
	//只要新增元素个数计入后大于vector，就要重建表格
	const size_type old_n=buckets.size(); 
	if(num_elements_hint>old_n){
		//确定真的需要重新匹配
		const size_type n=next_size(num_elements_hint);	//找出num_elements_hint的下一个质数
		if(n>old_n){
			vector<node*,A> tmp(n,(node*)0);
			__STL_TRY{
				//以下处理每一个旧的buckets
				for(size_type bucket=0;bucket<old_n;++bucket){
					node* first=buckets[bucket];	//指向结点所对应的串行的起始节点
					//以下处理每一个旧的bucket所含串行的每一个节点
					while(first){
						size_type new_bucket=bkt_num(first->val,n);
						//1.令旧的bucket指向其所对应的串行的下一个节点
						buckets[bucket]=first->next;
						//2.3.将当前节点插入到新的bucket内，成为对应串行的第一个节点
						first->next=tmp[new_bucket]; 
						tmp[new_bucket]=first;
						//回到旧的bucket所指的待处理串行，准备处理下一个节点
						first=buckets[bucket]; 
					} 
				}
				buckets.swap(tmp);//vector::swap,新旧两个buckets对调
				//注意，对调双方如果大小不同，大的会变小，小的会变大
				//离开时local tmp会自动释放 
			}
		} 
	}
}

template<class V,class K,class HF,class Ex,class Eq,class A>
pair<typename hashtable<V,K,HF,Ex,Eq,A>::iterator,bool>
hashtable<V,K,HF,Ex,Eq,A>::insert_unique_noresize(const value_type& obj){
	const size_type n=bkt_num(obj);	//决定obj应该位于 n bucket
	node* first=buckets[n];
	//如果buckets[n]已经被占用，此时first不为0
	for(node* cur=first;cur;cur=cur->next)
		if(equals(get_key(cur->val),get_key(obj)))
			//如果发现与链表中的某个键值相同，就不插入，立即返回
			return pair<iterator,bool>(iterator(cur,this),false); 
	//离开上述循环，first指向bucket所指链表的头部节点 
	node *tmp=new_node(obj);	//产生新节点 
	tmp->next=first;
	buckets[n]=tmp;
	++num_elements;
	return pair<iterator,bool>(iterator(tmp,this),true);
}

template<class V,class K,class HF,class Ex,class Eq,class A>
typename hashtable<V,K,HF,Ex,Eq,A>::iterator
hashtable<V,K,HF,Ex,Eq,A>::insert_equal_noresize(const value_type& obj){
	const size_type n=bkt_num(obj);	//决定obj应该位于 n bucket
	node* first=buckets[n];
	//如果buckets[n]已经被占用，此时first不为0
	for(node* cur=first;cur;cur=cur->next)
		if(equals(get_key(cur->val),get_key(obj)))
			//如果发现与链表中的某个键值相同，就马上插入，立即返回
			node *tmp=new_node(obj);	//产生新节点 
			tmp->next=cur->next;
			cur->next=tmp;
			++num_elements;
			return iterator(tmp,this);	
	//离开上述循环，first指向bucket所指链表的头部节点 
	node *tmp=new_node(obj);	//产生新节点 
	tmp->next=first;
	buckets[n]=tmp;
	++num_elements;
	return iterator(tmp,this);	
}

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::clear(){
	//针对每一个bucket
	for(size_type i=0;i<buckets.size();++i) {
		node* cur=buckets[i];
		//将bucket list中的每一个节点都删除掉
		while(cur!=0){
			node* next=cur->next;	//先暂存 
			delete_node(cur);
			cur=next;
		} 
		buckets[i]=0; 
	}
	num_elements=0;
	//注意vector没有释放空间，仍然保持原来的大小 
}

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::copy_from(const hash]\]table& ht){
	//先清除己方的vector，操作是vector::clear()，造成所有元素为0
	buckets.clear();
	//为己方的vector保留空间，使与对方相同
	//如果己方空间大于对方，就不动，否则，就会增大
	buckets.reverse(ht.buckets.size()) ;
	//为己方的vector初始化
	buckets.insert(buckets.end(),ht.buckets.size(),(node*)0) ;
	__STL_TRY{
		for(size_type i=0;i<ht.buckets.size();++i){
			//复制vector的每一个元素，是个指针
			if(const node *cur=ht.buckets[i]);
				node *copy=new_node(cur->val); 
				buckets[i]=copy;
				//针对同一个bucket list，复制每一个节点
				for(node* next=cur->next;next;cur=next,next=cur->next){
					copy->next=new_node(next->val);
					copy=copy->next;
				} 
		}
		num_elements=ht.num_elements;
	}
	__STL_UNWIND(clear());
}


