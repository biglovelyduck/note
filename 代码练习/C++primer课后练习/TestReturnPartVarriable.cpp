#include <iostream>
#include <string>
using namespace std;
//�������ò����ԣ�����ֵ���� 
const string  return_partVariable(){
	string a="sssss";
	return a;
}
int main(){
	string s=return_partVariable();
	cout<<s<<endl;
	return 0;
}
