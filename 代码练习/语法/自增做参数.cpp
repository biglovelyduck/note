//���������� 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
void func(char str[2]){		//�������С����2ûӰ�� 
	cout<<*str<<endl;
	printf("%s\n",str);
}
int main(){
	char* str="HelloWorld";
	func(++str);
	cout<<*str<<endl;
	cout<<sizeof(++str)<<endl;	//�����ָ��Ĵ�С������strû��++ 
	cout<<strlen(str++)<<endl; 
}
