//��
#include <vector>
#include <iostream>
using namespace std;

//����Ԫ�� 
template <class value>
void _push_heap(vector<value> &arr,int hole){
	value v=arr[hole];
	int parent=(hole-1)/2;
	while(parent>0&&arr[parent]<v){
		arr[hole]=array[parent];
		hole=parent;	//�ն�һֱ�����ߣ�ֱ���ߵ�ͷ 
		parent=(parent-1)/2;
	}
	arr[hole]=v;
}

//ɾ���Ѷ���ʵ�����ǽ��Ѷ��Ƶ�����ĩβ����Ȼ����ɾ������
template <class value>
void _pop_heap(vector<value> &arr,int sz){
	value v=arr[sz-1];
	arr[sz-1]=arr[0];
	--sz;
	int hole=0;
	int child=2*(hole+1);
	while(child<sz){
		if(arr[child-1]>arr[child])
			--child;
		arr[hole]=arr[child];
		hole=child;
		child=2*(hole+1);
	}
	arr[hole]=v;	//�ն�����ԭ�����λ�õ�Ԫ�� 
} 

//����,��������ݴ�С��֪ 
template<class value>
void _make_heap(vector<value> &arr){
	int sz=arr.size();
	int parent=(sz-2)/2;	//��һ����Ҷ�ӽڵ����ţ�Ҳ����˵�������һ���к��ӵĽڵ� 
	while(parent>=0){
		int hole=parent;
		int child=2*(hole+1)
		value v=arr[hole];	//v�ݴ汻ջ��Ԫ��ռ�ݵ�λ��ԭ��Ԫ�ص�ֵ
		while(child<sz){
			if(arr[child-1]>arr[child])
				--child;
			arr[hole]=arr[child];
			hole=child;
			child=2*(hole+1); 
		} 
		if(child==sz){
			arr[hole]=arr[child-1];
			hole=child-1;
		}
		arr[hole]=v;
		_push_heap(arr,hole);
		--parent;
	} 
} 
