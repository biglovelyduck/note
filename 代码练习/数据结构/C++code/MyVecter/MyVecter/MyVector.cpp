#include <iostream>
#include "MyVector.h"
using namespace std;

//����<<�ṹ��
template <typename T>
ostream & operator<< (ostream &out, const MyVector<T> &obj){//ʹ����Ҫ����<T>,�ڶ�������ΪҪ����ĳ�����
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
	//����obj�Ĵ�С�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy����
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
	//�Ȱ�ԭ�����ڴ��ͷŵ�
	if (m_space != NULL){
		delete[]m_sapce;
		m_sapce = NULL;
		m_len = 0;
	}
	//����obj�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];
	//����
	for (int i = 0; i<m_len; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;
}