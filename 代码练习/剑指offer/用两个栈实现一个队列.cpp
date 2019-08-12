//用两个栈实现一个队列
#include <iostream>
#include <stack>
#include <exception>
using namespace std;
template<typename T> class CQueue{
public:
	CQueue();
	~CQueue();
	
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;	
};

template<typename T>
void CQueue<T>::appendTail(const T& node){
	stack1.append(node);
} 

template<typename T>
T CQueue<T>::deleteHead(){
	if(stack2.size()<=0){
		while(stack1.size()>0){
			T& data=stack1.top();stack1.pop();
			stack2.push(data);
		}
	}
	if(stack2.size()==0)
		//throw new std::expection("queue is empty.");	//stack1为空 
		return NULL;
	T head=stack2.top();
	stack2.pop();
	
	return head;
}

class Solution
{
public:
    void push(int node) {
        stack1.push(node); 
    }

    int pop() {
        if(stack2.size()<=0){
			while(stack1.size()>0){
				int& data=stack1.top();stack1.pop();
				stack2.push(data);
			}
		}
		if(stack2.size()==0)
			//throw new expection("queue is empty.");	//stack1为空 
			return NULL;
		int head=stack2.top();
		stack2.pop();
		
		return head;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
 
