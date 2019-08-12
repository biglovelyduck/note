#include <cstdio>
#include <iostream> 
#include <stack>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct Matrix{
	int a,b;
	Matrix(int a=0,int b=0):a(a),b(b){//���캯����Ĭ�ϳ�ʼ������Ϊ0 
	}
}m[26];//�������26����д��ĸ

stack<Matrix> s;//ȫ�ֱ���������� 

bool isalpha(char c){
	if(c>=65&&c<=90) return true;
	else return false;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;//����ľ�������
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		int k=name[0]-'A';
		cin>>m[k].a>>m[k].b;
	} 
	string expr;//Ҫ���������ַ��� 
	while(cin>>expr){
		int len=expr.length();
		bool error=false;//���в���Ȼ���� 
		int ans=0;//���Ľ�� 
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
