//advance()�����������ֵ�������ʵ��
//���ã��ƶ������� 
//��� InputIterator��Ƶİ汾��ֻ�ܶ��������ƶ� 
template <class InputIterator,class Distance>
void advance_II(InputIterator& i,Distance n){
	//������һǰ��
	while(n--) ++i; 
} 
//���BidirectionalIterator�����Զ�д��˫���ƶ� ��ֻ֧��++ --
template <class BidirectionalIterator,class Distance>
void advanca_BI(BidirectionalIterator& i,Distance n)
{
	//˫����һǰ��
	if(n>=0) while(n--) ++i;
	else while(n++) --i; 
} 
//���RandomAccessIterator��˫���ƶ� ֧��p+n..
template <class RandomAccessIterator,class Distance>
void advance_RAI(RandomAccessIterator& i,Distance n){
	//˫����Ծǰ��
	i+=n; 
} 

//���������ϲ������Ч�ʲ���֧��Inout Iterator
template <class InputIterator,class Distance>
void advance(InputIterator &i,Distance n){
	if(is_random_accee_iterator(i)) advance_RAI(i,n);
	else if(is_bidirectional_iterator(i)) advance_BI(i,n);
	else advance_II(i,n);
} 

//�Ľ�������ʹ��traits��ȡ��������������
//�����Ϊ����õ��ͱ�(tag types)
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag:public input_iterator_tag{};
struct bidirectional_iterator_tag:public forward_iterator_tag{};
struct random_access_iterator_tag:public bidirectional_iterator_tag{};

//�������advance()
template <class InputIterator,class Distance>
inline void _advance(InputIterator& i,Distance n,input_iterator_tag){
	//������һǰ��
	while(n--) ++i; 
} 
//���BidirectionalIterator�����Զ�д��˫���ƶ� ��ֻ֧��++ --
template <class BidirectionalIterator,class Distance>
inline void _advanca(BidirectionalIterator& i,Distance n,bidirectional_iterator_tag)
{
	//˫����һǰ��
	if(n>=0) while(n--) ++i;
	else while(n++) --i; 
} 
//���RandomAccessIterator��˫���ƶ� ֧��p+n..
template <class RandomAccessIterator,class Distance>
inline void _advance(RandomAccessIterator& i,Distance n,random_access_iterator_tag){
	//˫����Ծǰ��
	i+=n; 
}  

//�ϲ���ƽӿ�,����traits����
template <class InputIterator,class Distance>
inline void advance(InputIterator& i,Distance n){
	_advance(i,n,iterator_traits<InputIterator>::iterator_categoty());
} 
