//°üº¬minº¯ÊýµÄÕ» 
#include <bits/stdc++.h>
#include <stack>
using namespace std;
/*
class Solution {
public:
    void push(int value) {
        data.push(value);
        if(m.size()==0) m.push(value);
        if(m.top()>value) m.push(value);
        else
        	m.push(m.top());
    }
    void pop() {
        if(data.size()>0&&m.size()>0){
        	data.pop();
        	m.pop();
		}
    }
    int top() {
        if(data.size()>0&&m.size()>0){
        	data.top();
        	m.top();
		}
    }
    int min() {
    	if(data.size()>0&&m.size()>0){
        	return m.top();
		}
    }

	stack<int> data;
	stack<int> m;
};*/



class Solution {
public:
     
    stack<int> stack1,stack2;
     
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value<=stack2.top())
        {
            stack2.push(value);
        }
    }
     
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
         
    }
     
    int top() {
        return stack1.top();       
    }
     
    int min() {
        return stack2.top();
    }
     
};
