#include <iostream>
using namespace std;

template <typename T>
class MyVector{
	friend ostream& operator<< <T>(ostream &out, const MyVector &obj);

public:
	MyVector(int size = 0);
	MyVector(const MyVector &obj);//拷贝构造函数
	~MyVector();

	T& operator[] (int index);//MyVector的[]调用后返回T类型
	MyVector& operator= (const MyVector &obj);

	int getLen(){
		return m_len;
	}
protected:
	T *m_space;
	int m_len;
};