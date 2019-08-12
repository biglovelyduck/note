#include <iostream>
#include "MyVector.h"
using namespace std;

//重载<<结构：
template <typename T>
ostream & operator<< (ostream &out, const MyVector<T> &obj){//使用类要加上<T>,第二个参数为要输出的常对象
	for (int i = 0; i < obj.m_len; i++){
		out << obj.m_space[i]<<" ";
	}
	out << endl;
	return out;
}

template <typename T>
T& MyVector<T>::operator[] (int index)
{
	return m_space[index];
}

template <typename T>
MyVector<T>::MyVector(int size){
	m_space = new T[size];
	m_len = size;
}

//MyVector<int> myv2  = myv1;
template <typename T>
MyVector<T>::MyVector(const MyVector &obj){
	//根据obj的大小分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy数据
	for (int i = 0; i < m_len; i++){
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
MyVector<T>::~MyVector(){
	if (m_space != NULL){
		delete []m_space;
		m_space = NULL;
		m_len = 0;
	}
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &obj){
	//先把原来的内存释放掉
	if (m_space != NULL){
		delete[]m_sapce;
		m_sapce = NULL;
		m_len = 0;
	}
	//根据obj分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	//拷贝
	for (int i = 0; i<m_len; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;
}