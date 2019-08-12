#include <iostream>
using namespace std;

template <typename T>
class MyVector{
	friend ostream& operator<< <T>(ostream &out, const MyVector &obj);

public:
	MyVector(int size = 0);
	MyVector(const MyVector &obj);//�������캯��
	~MyVector();

	T& operator[] (int index);//MyVector��[]���ú󷵻�T����
	MyVector& operator= (const MyVector &obj);

	int getLen(){
		return m_len;
	}
protected:
	T *m_space;
	int m_len;
};