#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node{
	double num;//操作数
	char op;//操作符
	bool flag;//true表示操作数，false表示操作符 
};

string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char,int> op;//操作符的优先级 

//将中缀表达式转化为后缀表达式 
void change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length()&&str[i]>='0'&&str[i]<='9'){//非个位数 
				temp.num=temp.num*10+(str[i]-'0');
				i++; 
			}
			q.push(temp);//将这个操作数压入后缀表达式序列 
		}
		else{
			temp.flag=false;
			//只要操作符栈顶元素比该操作符优先级高
			//就把操作符栈顶元素弹出到后缀表达式中
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op=str[i];//优先级高
			s.push(temp);
			i++; 
		} 
	}
	//如果操作符栈中还有操作符，就把他们都弹出到后缀表达式队列中
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	} 
}

//计算后缀表达式 
double cal(){
	double temp1,temp2;//第一操作数，第二操作数 
	node cur,temp;
	while(!q.empty()){//挨个从队头取元素 
		cur=q.front();
		q.pop();
		if(cur.flag==true) s.push(cur);
		else{//操作符 
			temp2=s.top().num;//弹出第二操作数 
			s.pop();
			temp1=s.top().num;//弹出第一操作数
			s.pop();
			temp.flag=true;//临时记录操作数
			if(cur.op=='+') temp.num=temp1+temp2;
			else if(cur.op='-') temp.num=temp1-temp2;
			else if(cur.op='*') temp.num=temp1*temp2;
			else if(cur.op='/') temp.num=temp1/temp2;
			s.push(temp);
		}
	}
	return s.top().num;
} 

int main(){
	//设置操作符优先级 
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0"){
		//去除空格 
		for(string::iterator it=str.end();it!=str.begin();it--){
			if(*it==' ') str.erase(it);
		}
		while(!s.empty()) s.pop();//初始化栈
		change();
		printf("%.2f\n",cal());
	} 
	return 0;
} 
