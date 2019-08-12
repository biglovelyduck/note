//�Կ�������ɵ�hashtable
//vector��ÿ��Ԫ�ض���һ��Ͱ��Ͱ�п��ܺ������ڵ� 

//������ʹ��������Ʊ��
static const int __stl_num_prime=28;
static const unsigned long __stl_prime_list[__stl_num_primes]={
	//53��ͷ��28������ 
}; 
//�ҳ�����28��ָ���У���ӽ����Ҵ���n���Ǹ�����
inline unsigned long __stl_next_prime(unsigned long n){
	const unsigned long *first=__stl_prime_list;
	const unsigned long *last=__stl_prime_list+__stl_num_primes;
	const unsigned long *pos=lower_bound(first,last,n);
	return pos==last?*(last-1):*pos;
} 

//hashtable�Ľڵ㶨��
template <class Value>
struct __hashtable_node{
	__hash_table_node* next;
	Value val;
}; 

//hashtable�ĵ�����
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
	
	node* cur;	//������Ŀǰ��ָ�ڵ�
	hashtable* ht;	//���ֶ������������ϵ����Ϊ����Ҫ��bucket����bucket
	
	__hashtable_iterator(node* n,hashtable* tab):cur(n),ht(tab){}
	__hashtable_iterator(){}
	reference operator*() const{return cur->val;}
	pointer operator->() const{return &(operator*());}
	iterator& operator++();
	iterator operator++(int);
	bool operator==(const iterator& it) const{return cur==it.cur;}
	bool operator!=(const iterator& it) const{return cur!=it.cur;}
}; 

//hashtable�ĵ�����û�к��˲�����Ҳû����������� 
template<class V,class K,class HF,class ExK,class EqK,class A>
__hashtable_iterator<V,k,HF,ExK,A>&
__hashtable_iterator<V,K,HF,ExK,A>::operator++(){
	const node* old=cur;
	cur=cur->next;	//������� ������ 
	if(!cur){
		//����Ԫ��ֵ����λ����һ��bucket������ͷ���������ǵ�Ŀ�ĵ�
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

//hashtable�����ݽṹ ,���� ʱ�Ѿ�����Ĭ�ϵ�alloc 
template <class Value,class Key,class HashFcn,class ExtractKey,class EqualKey,class Alloc=alloc>
class hashtable;
//����
//Value:�ڵ��ʵֵ����
//Key:�ڵ�ļ�ֵ����
//HashFcn:hash function�ĺ����ͱ�
//ExtractKey:�ӽڵ���ȡ����ֵ�ķ������������߷º��� 
//EqualKey:�жϼ�ֵ��ͬ���ķ������������߷º���
//Alloc:�ռ������� 
template <class Value,class Key,class HashFcn,class ExtractKey,class EqualKey,class Alloc>
class hashtable{
public:
	typedef HashFcn hasher;	//Ϊtemplate�ͱ�������¶���һ������
	typedef EqualKey key_equal;
	typedef size_t size_type;
private:
	//�������߶���function objects,<stl_hash_fun.h>�ж���������
	//��׼�ͱ� �� int c-style string �ȵ�hasher
	hasher hash;
	key_equal equals;
	ExtractKey get_key;
	
	typedef __hashtable_node<Value> node;
	typedef simple_alloc<node,Alloc> node_allocator; 
	
	vector<node*,Alloc> buckets;	//��vector���
	size_type num_elements;
public:
	//vector��С��Ҳ����bucket����
	size_type bucket_count() const{return buckets.size();} 
	
	//�ܹ������ж���buckets
	size_type max_bucket_count() const{
		return __stl_prime_list[__stl_num_primes-1];	//4294967291
	} 
	
	//�ڵ����ú���
	node* new_node(const value_type& obj){
		node* n=node_allocator:allocate();
		n->next=0;
		__STL_TRY{
			construct(&n->val,obj);
			return n;
		}
	} 
	//�ڵ��ͷź���
	void delete_node(node* n){
		destroy(&n->val);
		node_allocator::deallocate(n);
	} 
	
	//���캯��
	hashtable(size_type n,const HashFcn& hf,EqualKey& eql)
		:has(hf),equals(,),get_key(ExtractKey()),num_elements(0){
			initialize_buckets(n);
	}
	size_type next_size(size type n) const {return __stl_next_prime(n);} 
	void initialize_buckets(size_type n){
		const size_type n_buckets=next_size(n);	//������ӽ�n������n������
		buckets.reserve(n_buckets);//�ȱ���n_buckets��Ԫ�ؿռ�
		buckets.insert(buckets.end(),n_buckets,(node*)0); 	//��ʼ��ȫ����0 
		num_elements=0;
	}
	
	//����
	void copy_from(const hashtable& ht); 
	//����ɾ�� 
	void clear();
	
	//�汾3��ֻ���ܼ�ֵ
	size_type bkt_num_key(const key_type& key) const{
		return bkt_num_key(key,buckets.size();
	} 
	//�汾4�����ܼ�ֵ�͸���
	size_type bkt_num_key(const key_type& key,size_t n) const{
		return hash(key)%n;		//SGI�����ڽ���hash 
	} 
	//��֪Ԫ�ص���Ŵ�,�汾1 ������ʵֵ��buckets���� 
	size_type bkt_num(const value_type& obj,size_t n) const {
		return bkt_num_key(get_key(obj),n);	//���ð汾4 
	}
	//�汾2��ֻ����ʵֵ
	size_type bkt_num(const value_type& obj) const{
		return bkt_num_key(get_key(obj));	//���ð汾3 
	} 
	
	//�ж��Ƿ���Ҫ�ؽ���������Ҫ������
	void resize(size_type num_elements_hint);
	//�ڲ���Ҫ�ؽ���������²����½ڵ㣬��ֵ�������ظ�
	pair<typename hashtable<V,K,HF,Ex,Eq,A>::iterator,bool> insert_unique_noresize(const value_type& obj); 
	//�ڲ���Ҫ�ؽ���������²����½ڵ㣬��ֵ�����ظ�
	iterator insert_equal_noresize(const value_type& obj);
	//�������,�������ظ� 
	pair<iterator,bool> insert_unique(const value_type& obj){
		resize(num_elements+1);	//�ж��Ƿ���Ҫ�ؽ���������Ҫ������
		return insert_unique_noresize(obj); 
	} 
	//����Ԫ�أ������ظ�
	iterator insert_equal(const value_type &obj){
		resize(num_elements+1);	//�ж��Ƿ���Ҫ�ؽ���������Ҫ������
		return insert_equal_noresize(obj); 
	} 
};

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::resize(size_type num_elements_hint){
	//ֻҪ����Ԫ�ظ�����������vector����Ҫ�ؽ����
	const size_type old_n=buckets.size(); 
	if(num_elements_hint>old_n){
		//ȷ�������Ҫ����ƥ��
		const size_type n=next_size(num_elements_hint);	//�ҳ�num_elements_hint����һ������
		if(n>old_n){
			vector<node*,A> tmp(n,(node*)0);
			__STL_TRY{
				//���´���ÿһ���ɵ�buckets
				for(size_type bucket=0;bucket<old_n;++bucket){
					node* first=buckets[bucket];	//ָ��������Ӧ�Ĵ��е���ʼ�ڵ�
					//���´���ÿһ���ɵ�bucket�������е�ÿһ���ڵ�
					while(first){
						size_type new_bucket=bkt_num(first->val,n);
						//1.��ɵ�bucketָ��������Ӧ�Ĵ��е���һ���ڵ�
						buckets[bucket]=first->next;
						//2.3.����ǰ�ڵ���뵽�µ�bucket�ڣ���Ϊ��Ӧ���еĵ�һ���ڵ�
						first->next=tmp[new_bucket]; 
						tmp[new_bucket]=first;
						//�ص��ɵ�bucket��ָ�Ĵ������У�׼��������һ���ڵ�
						first=buckets[bucket]; 
					} 
				}
				buckets.swap(tmp);//vector::swap,�¾�����buckets�Ե�
				//ע�⣬�Ե�˫�������С��ͬ����Ļ��С��С�Ļ���
				//�뿪ʱlocal tmp���Զ��ͷ� 
			}
		} 
	}
}

template<class V,class K,class HF,class Ex,class Eq,class A>
pair<typename hashtable<V,K,HF,Ex,Eq,A>::iterator,bool>
hashtable<V,K,HF,Ex,Eq,A>::insert_unique_noresize(const value_type& obj){
	const size_type n=bkt_num(obj);	//����objӦ��λ�� n bucket
	node* first=buckets[n];
	//���buckets[n]�Ѿ���ռ�ã���ʱfirst��Ϊ0
	for(node* cur=first;cur;cur=cur->next)
		if(equals(get_key(cur->val),get_key(obj)))
			//��������������е�ĳ����ֵ��ͬ���Ͳ����룬��������
			return pair<iterator,bool>(iterator(cur,this),false); 
	//�뿪����ѭ����firstָ��bucket��ָ�����ͷ���ڵ� 
	node *tmp=new_node(obj);	//�����½ڵ� 
	tmp->next=first;
	buckets[n]=tmp;
	++num_elements;
	return pair<iterator,bool>(iterator(tmp,this),true);
}

template<class V,class K,class HF,class Ex,class Eq,class A>
typename hashtable<V,K,HF,Ex,Eq,A>::iterator
hashtable<V,K,HF,Ex,Eq,A>::insert_equal_noresize(const value_type& obj){
	const size_type n=bkt_num(obj);	//����objӦ��λ�� n bucket
	node* first=buckets[n];
	//���buckets[n]�Ѿ���ռ�ã���ʱfirst��Ϊ0
	for(node* cur=first;cur;cur=cur->next)
		if(equals(get_key(cur->val),get_key(obj)))
			//��������������е�ĳ����ֵ��ͬ�������ϲ��룬��������
			node *tmp=new_node(obj);	//�����½ڵ� 
			tmp->next=cur->next;
			cur->next=tmp;
			++num_elements;
			return iterator(tmp,this);	
	//�뿪����ѭ����firstָ��bucket��ָ�����ͷ���ڵ� 
	node *tmp=new_node(obj);	//�����½ڵ� 
	tmp->next=first;
	buckets[n]=tmp;
	++num_elements;
	return iterator(tmp,this);	
}

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::clear(){
	//���ÿһ��bucket
	for(size_type i=0;i<buckets.size();++i) {
		node* cur=buckets[i];
		//��bucket list�е�ÿһ���ڵ㶼ɾ����
		while(cur!=0){
			node* next=cur->next;	//���ݴ� 
			delete_node(cur);
			cur=next;
		} 
		buckets[i]=0; 
	}
	num_elements=0;
	//ע��vectorû���ͷſռ䣬��Ȼ����ԭ���Ĵ�С 
}

template<class V,class K,class HF,class Ex,class Eq,class A>
void hashtable<V,K,HF,Ex,Eq,A>::copy_from(const hash]\]table& ht){
	//�����������vector��������vector::clear()���������Ԫ��Ϊ0
	buckets.clear();
	//Ϊ������vector�����ռ䣬ʹ��Է���ͬ
	//��������ռ���ڶԷ����Ͳ��������򣬾ͻ�����
	buckets.reverse(ht.buckets.size()) ;
	//Ϊ������vector��ʼ��
	buckets.insert(buckets.end(),ht.buckets.size(),(node*)0) ;
	__STL_TRY{
		for(size_type i=0;i<ht.buckets.size();++i){
			//����vector��ÿһ��Ԫ�أ��Ǹ�ָ��
			if(const node *cur=ht.buckets[i]);
				node *copy=new_node(cur->val); 
				buckets[i]=copy;
				//���ͬһ��bucket list������ÿһ���ڵ�
				for(node* next=cur->next;next;cur=next,next=cur->next){
					copy->next=new_node(next->val);
					copy=copy->next;
				} 
		}
		num_elements=ht.num_elements;
	}
	__STL_UNWIND(clear());
}


