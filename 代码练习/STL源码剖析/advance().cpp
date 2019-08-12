//advance()函数关于五种迭代器的实现
//作用：移动迭代器 
//针对 InputIterator设计的版本，只能读，单向移动 
template <class InputIterator,class Distance>
void advance_II(InputIterator& i,Distance n){
	//单向，逐一前进
	while(n--) ++i; 
} 
//针对BidirectionalIterator，可以读写，双向移动 ，只支持++ --
template <class BidirectionalIterator,class Distance>
void advanca_BI(BidirectionalIterator& i,Distance n)
{
	//双向，逐一前进
	if(n>=0) while(n--) ++i;
	else while(n++) --i; 
} 
//针对RandomAccessIterator，双向移动 支持p+n..
template <class RandomAccessIterator,class Distance>
void advance_RAI(RandomAccessIterator& i,Distance n){
	//双向，跳跃前进
	i+=n; 
} 

//三种做法合并，提高效率并且支持Inout Iterator
template <class InputIterator,class Distance>
void advance(InputIterator &i,Distance n){
	if(is_random_accee_iterator(i)) advance_RAI(i,n);
	else if(is_bidirectional_iterator(i)) advance_BI(i,n);
	else advance_II(i,n);
} 

//改进，考虑使用traits萃取出迭代器的种类
//五个作为标记用的型别(tag types)
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag:public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};

//重新设计advance()
template <class InputIterator,class Distance>
inline void _advance(InputIterator& i,Distance n,input_iterator_tag){
	//单向，逐一前进
	while(n--) ++i; 
} 
//针对BidirectionalIterator，可以读写，双向移动 ，只支持++ --
template <class BidirectionalIterator,class Distance>
inline void _advanca(BidirectionalIterator& i,Distance n,bidirectional_iterator_tag)
{
	//双向，逐一前进
	if(n>=0) while(n--) ++i;
	else while(n++) --i; 
} 
//针对RandomAccessIterator，双向移动 支持p+n..
template <class RandomAccessIterator,class Distance>
inline void _advance(RandomAccessIterator& i,Distance n,random_access_iterator_tag){
	//双向，跳跃前进
	i+=n; 
}  

//上层控制接口,交给traits机制
template <class InputIterator,class Distance>
inline void advance(InputIterator& i,Distance n){
	_advance(i,n,iterator_traits<InputIterator>::iterator_categoty());
} 
