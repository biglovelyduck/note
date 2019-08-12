//表示数值的字符串
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
	bool numeric=scanInteger(&str);	//整数部分合不合适 
	//如果遇到小数点，接下来扫描小数部分
	if(*str=='.'){
		++str;
		//可以没有整数部分，可以没有小数部分，也可以都有 
		numeric=scanUnsignedInteger(&str)||numeric; 	//整数和小数部分合不合适 
	} 
	if(*str=='e'||*str=='E'){
		++str;
		//eE前面必须有数字，后面必须有整数
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
