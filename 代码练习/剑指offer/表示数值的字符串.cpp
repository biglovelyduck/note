//��ʾ��ֵ���ַ���
#include <bits/stdc++.h>
using namespace std; 
bool scanUnsignedInteger(const char** str){
	const char* before=*str;
	while(**str!='\0'&&**str>='0'&&**str<='9')
		++(*str);
	return *str>before;
}
bool scanInteger(const char** str){
	if(**str=='+'||**str=='-') ++(*str);
	return scanUnsignedInteger(str);
}
bool isNumeric(const char* str){
	if(str==nullptr) return false;
	bool numeric=scanInteger(&str);	//�������ֺϲ����� 
	//�������С���㣬������ɨ��С������
	if(*str=='.'){
		++str;
		//����û���������֣�����û��С�����֣�Ҳ���Զ��� 
		numeric=scanUnsignedInteger(&str)||numeric; 	//������С�����ֺϲ����� 
	} 
	if(*str=='e'||*str=='E'){
		++str;
		//eEǰ����������֣��������������
		numeric=numeric&&scanInteger(&str); 
	} 
	return numeric&&*str=='\0';
} 
int main(){
	char *str=new char[5];
	scanf("%s",str);
	//cout<<strlen(str);
	//str[4]='\0';
	//cout<<"yse"<<endl;
	cout<<isNumeric(str)<<endl;;
	return 0;
} 
