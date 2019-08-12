#include "SeqList.h"
#include <string>

template <typename T>
SeqList<T>::SeqList(int cap)
{
	pArray = new T[cap];
	this->capacity = cap;
	this->length = 0;
}

template <typename T>
SeqList<T>::~SeqList(void)
{
	delete[]pArray;
	pArray = NULL;
	this->length = 0;
	this->capacity = 0;
}

template <typename T>
int SeqList<T>::getLen(){
	return this->length;
}

template <typename T>
int SeqList<T>::getCapacity(){
	return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T &t, int pos){
	/*if (t == NULL || pos<0){
		return -1;
	}*/
	for (int i = length; i>pos; i--){//因为后移了，所以i初始为len
		pArray[i] = pArray[i - 1];
	}
	pArray[pos] = t;
	this->length++;
	return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T &t){
	/*if (t == NULL || pos<0){
	return -1;
	}*/
	t = pArray[pos];
	return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t){
	/*if (t == NULL || pos<0){
	return -1;
	}*/
	t = pArray[pos];
	for (int i = pos+1; i<length; i++){//因为后移了，所以i初始为len
		pArray[i-1] = pArray[i ];
	}
	this->length--;
	return 0;
}