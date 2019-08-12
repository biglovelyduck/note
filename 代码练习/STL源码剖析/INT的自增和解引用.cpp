//INT
#include <iostream>
using namespace std;

class INT{
	friend ostream& operator<<(ostream os,const INT& i);
public:
	INT(int j):m_i(j){
	}
	//先递增后取值
	INT& operator++(){
		++(this->m_i);
		return *this;
	} 
	//先取值后递增
	const INT operator++(int){
		INT temp=*this;
		++(*this);
		return temp;
	} 
	//解引用
	int& operator*() const{
		return (int&)m_i;
	} 
	int& get_i(){
		return this->m_i;
	}
private:
	int m_i;
}; 

ostream& operator<<(ostream& os,const INT &i){
	os<<'['<<*i<<']';
	return os;
}

int main(){
	INT I(5);
	cout<<I++<<endl;
	cout<<*I<<endl;
	return 0;
}
