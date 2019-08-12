//queue
template <class T,class Sequence=deque<T> >
class queue{
	friend bool operator==__STL_NULL_TMP_ARGS(const queue&,const queue&);
	friend bool operator< __STL_NULL_TMPL_ARFS(const queue&,const queue&);
public:
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;
protected:
	Sequence c;				//µ×²ãÈÝÆ÷ 
public:
	bool empty() const{return c.empty();}
	size_type size() const{return c.size();}
	reference front(){return c.front();}
	const_reference front() const{return c.front();}
	reference back(){return c.back();}
	const_reference back() const{return c.back();}
	
	void push(const value_type& x){
		c.push_back(x);
	}
	void pop(){
		c.pop_front();
	}
};

template <class T,class Sequence>
bool operator==(const queue<T,Sequence>& x,const queue<T,Sequence>& y){
	return x.c==y.c;
} 
template<class T,class Sequence>
bool operator<(const queue<T,Sequence>& x,const queue<T,Sequence>& y){
	return x.c<y.c;
}

