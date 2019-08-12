#include <cstdio>
#include <iostream> 
#include <stack>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct Matrix{
	int a,b;
	Matrix(int a=0,int b=0):a(a),b(b){//构造函数，默认初始化参数为0 
	}
}m[26];//用来存放26个大写字母

stack<Matrix> s;//全局变量保存矩阵 

bool isalpha(char c){
	if(c>=65&&c<=90) return true;
	else return false;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;//输入的矩阵数量
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		int k=name[0]-'A';
		cin>>m[k].a>>m[k].b;
	} 
	string expr;//要计算结果的字符串 
	while(cin>>expr){
		int len=expr.length();
		bool error=false;//列行不相等会出错 
		int ans=0;//积的结果 
		for(int i=0;i<len;i++){
			if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
			else if(expr[i]==')'){
				Matrix m2=s.top(); s.pop();
				Matrix m1=s.top(); s.pop();
				if(m1.b!=m2.a){
					error=true;
					break;
				}
				ans+=m1.a*m1.b*m2.b;
				s.push(Matrix(m1.a*m2.b));
			}
		}
		if(error) printf("error.");
		else printf("%d",ans); 
	} 
	return 0;
}
