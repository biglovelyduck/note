//��̬����ʵ�� 
//��������ĵ�һ�������һ��Ԫ����Ϊ����Ԫ�ش����������ݡ�
//ͨ����δʹ�õ�����Ԫ�س�Ϊ���������������һ��Ԫ�أ�
//���±�Ϊ0��Ԫ�ص�cur�ʹ�ű�������ĵ�һ�������±ꣻ
//����������һ��Ԫ�ص�cur���ŵ�һ������ֵ��Ԫ�ص��±꣬
//�൱�������е�ͷ������ã�����������Ϊ��ʱ����Ϊ02��

#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 1000
 
template<typename T>
class StaticList
{
public:
	typedef struct
	{
		T data;
		int next;
	}Node;
	StaticList();
	~StaticList();
	bool Insert(const T& e, int index = 1);
	bool Delete( T& e, int index = 1);
	void Show()const;
private:
	int NewSpace();
	void DeleteSpace(int index);
	bool Empty()const;
	bool Full()const;
	vector<Node> v;
	int Length;
};

template<typename T>
StaticList<T>::StaticList() :Length(0)
{
	v.resize(MAX_SIZE);
	for (int i = 0; i < MAX_SIZE - 1;++i)
	{
		v[i].next = i + 1;
	}
	v[MAX_SIZE - 1].next = 0; 
}
 
 
template<typename T>
StaticList<T>::~StaticList()
{
	
}
 
template<typename T>
bool StaticList<T>::Insert(const T& e, int index )
{
	if (Full())
	{
		return false;
	}
	if (index<1||index>Length+1)
	{
		return false;
	}
	int k = NewSpace();
	int j = MAX_SIZE - 1;
	if (k)
	{
		v[k].data = e;
		for (int i = 1; i <= index - 1;++i)
		{
			j = v[j].next;
		}
		v[k].next = v[j].next;
		v[j].next = k;
		++Length;
		return true;
	}	
	return false;
}
 
template<typename T>
bool StaticList<T>::Delete(T& e, int index)
{
	if (Empty())
	{
		return false;
	}
	if (index<1 || index>Length )
	{
		return false;
	}
	int k = MAX_SIZE - 1;
	int i = 1;
	for (; i <= index - 1;++i)
	{
		k = v[k].next;
	}
	i = v[k].next;
	v[k].next = v[i].next;
	e = v[i].data;
	DeleteSpace(i);
	--Length;
	return true;
}
 
template<typename T>
void StaticList<T>::Show() const
{
	if (Empty())
	{
		return;
	}
	int k = v[MAX_SIZE - 1].next;
	for (int i = 1; i <= Length;++i)
	{
		cout << v[k].data << " ";
		k = v[k].next;
	}
	cout << endl;
}
 
template<typename T>
bool StaticList<T>::Full() const
{
	if (Length > MAX_SIZE - 2)
	{
		return true;
	}
	return false;
}
 
template<typename T>
bool StaticList<T>::Empty() const
{
	return(Length == 0);
}
 
template<typename T>
void StaticList<T>::DeleteSpace(int index)
{
	v[index].next = v[0].next;
	v[0].next = index;
}
 
template<typename T>
int StaticList<T>::NewSpace()
{
	int i = v[0].next;
 
	if (v[0].next)
	{
		v[0].next = v[i].next;
	}
	return i;
}


int main()
{
	StaticList<int> list;
	list.Insert(12);
	list.Insert(12);
	list.Insert(34);
 
	list.Insert(23);
	list.Insert(12);
 
	list.Insert(99,4);
	list.Show();
	int m = 0;
	list.Delete(m,3);
	list.Show();
	list.Insert(222);
	list.Show();
	return 0;
}

