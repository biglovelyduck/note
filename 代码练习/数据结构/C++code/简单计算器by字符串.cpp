#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node{
	double num;//������
	char op;//������
	bool flag;//true��ʾ��������false��ʾ������ 
};

string str;
stack<node> s;//������ջ
queue<node> q;//��׺���ʽ����
map<char,int> op;//�����������ȼ� 

//����׺���ʽת��Ϊ��׺���ʽ 
void change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.length()&&str[i]>='0'&&str[i]<='9'){//�Ǹ�λ�� 
				temp.num=temp.num*10+(str[i]-'0');
				i++; 
			}
			q.push(temp);//�����������ѹ���׺���ʽ���� 
		}
		else{
			temp.flag=false;
			//ֻҪ������ջ��Ԫ�رȸò��������ȼ���
			//�ͰѲ�����ջ��Ԫ�ص�������׺���ʽ��
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op=str[i];//���ȼ���
			s.push(temp);
			i++; 
		} 
	}
	//���������ջ�л��в��������Ͱ����Ƕ���������׺���ʽ������
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	} 
}

//�����׺���ʽ 
double cal(){
	double temp1,temp2;//��һ���������ڶ������� 
	node cur,temp;
	while(!q.empty()){//�����Ӷ�ͷȡԪ�� 
		cur=q.front();
		q.pop();
		if(cur.flag==true) s.push(cur);
		else{//������ 
			temp2=s.top().num;//�����ڶ������� 
			s.pop();
			temp1=s.top().num;//������һ������
			s.pop();
			temp.flag=true;//��ʱ��¼������
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
	//���ò��������ȼ� 
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0"){
		//ȥ���ո� 
		for(string::iterator it=str.end();it!=str.begin();it--){
			if(*it==' ') str.erase(it);
		}
		while(!s.empty()) s.pop();//��ʼ��ջ
		change();
		printf("%.2f\n",cal());
	} 
	return 0;
} 
