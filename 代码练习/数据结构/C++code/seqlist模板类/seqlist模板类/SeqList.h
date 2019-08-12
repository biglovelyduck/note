#pragma once

#include <string>


template <typename T>
class SeqList
{
public:
	SeqList(int cap);
	~SeqList();

	int getLen();

	int getCapacity();

	int insert(T &t, int pos);

	int get(int pos, T &t);

	int del(int pos, T &t);

private:
	int length;
	int capacity;

	T *pArray;
};

