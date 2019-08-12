//stack,修改了deque的接口，称为adapter(配接器)
template <class T,class Sequece=deque<T> >
class stack{
	friend bool operator==__STL_NULL_TMP_ARGS(const stack&,const stack&);
	friend bool operator< __STL_NULL_TMPL_ARFS(const stack&,const stack&);
public:
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;
protected:
	Sequence c;				//底层容器 
public:
	bool empty() const{return c.empty();}
	size_type size() const{return c.size();}
	reference top(){
		return c.back();
	}
	const_reference top() const{return c.back();}
	void push(const value_type& x){
		c.push_back(x);
	}
	void pop(){
		c.pop_back();
	}
};

template <class T,class Sequence>
bool operator==(const stack<T,Sequence>& x,const stack<T,Sequence>& y){
	return x.c==y.c;
} 
template<class T,class Sequence>
bool operator<(const stack<T,Sequence>& x,const stack<T,Sequence>& y){
	return x.c<y.c;
}
