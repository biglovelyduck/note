//堆
#include <vector>
#include <iostream>
using namespace std;

//插入元素 
template <class value>
void _push_heap(vector<value> &arr,int hole){
	value v=arr[hole];
	int parent=(hole-1)/2;
	while(parent>0&&arr[parent]<v){
		arr[hole]=array[parent];
		hole=parent;	//空洞一直向上走，直到走到头 
		parent=(parent-1)/2;
	}
	arr[hole]=v;
}

//删除堆顶，实际上是将堆顶移到数组末尾，（然后再删除？）
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
	arr[hole]=v;	//空洞保存原来最后位置的元素 
} 

//建堆,数组的内容大小已知 
template<class value>
void _make_heap(vector<value> &arr){
	int sz=arr.size();
	int parent=(sz-2)/2;	//第一个非叶子节点的序号，也就是说这是最后一个有孩子的节点 
	while(parent>=0){
		int hole=parent;
		int child=2*(hole+1)
		value v=arr[hole];	//v暂存被栈顶元素占据的位置原来元素的值
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
