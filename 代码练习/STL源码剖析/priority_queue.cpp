//priority_queue  
//缺省情况下以vector为底部容器
template <class T,class Sequence=vector<T> >,class Compare=less<typename Sequece::value_type> >
class priority_queue{
public:
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;
protected:
	Sequence c;//底层容器
	Compare comp;//元素大小比较标准
public:
 	priority_queue():c(){}
 	explicit priority_queue(const Compare& x):c(),comp(x){}
 	
 	template <class InputIterator>
 	priority_queue(InputIterator first,InputIterator last,const Compare& x)
 	:c(first,last){
 		make_heap(c.begin(),c.end(),comp);	
	}
	template<class InputIterator>
	priority_queue(InputIterator first,InputIterator last)
	:c(first,last)
	{
		make_heap(c.begin(),c.end(),comp);	
	}
	bool empty() const{return c.empty();}
	size_type size() const{return c.size();}
	reference top(){
		return c.front();
	}
	
	void push(const value_type &x){
		__STL_TRY{
			c.push_back(x);
			push_heap(c.begin(),e.end(),comp);
		}
		__STL_UNWIND(c.clear());
	}
	
	void pop(){
		__STL_TRY{
			pop_heap(c.begin(),e.end(),comp);
			c.pop_back();
		}
		__STL_UNWIND(c.clear());
	}
}; 
