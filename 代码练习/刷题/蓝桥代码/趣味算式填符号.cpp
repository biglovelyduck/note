/*匪警请拨110,即使手机欠费也可拨通！
为了保障社会秩序，保护人民群众生命财产安全，警察叔叔需要与罪犯斗智斗勇，因而需要经常性地进行体力训练和智力训练！

某批警察叔叔正在进行智力训练：
1 2 3 4 5 6 7 8 9 = 110

请看上边的算式，为了使等式成立，需要在数字间填入加号或者减号（可以不填，但不能填入其它符号）。之间没有填入符号的数字组合成一个数，例如：12+34+56+7-8+9 就是一种合格的填法；123+4+5+67-89 是另一个可能的答案。

请你利用计算机的优势，帮助警察叔叔快速找到所有答案。
每个答案占一行。形如：
12+34+56+7-8+9
123+4+5+67-89
......*/ 

#include <iostream>
#include <string>
#include <cstdlib> 
#include <sstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void f(int a[],int k,string so,int goal); 
string num2str(int i);
int str2num(string s);
string pinjie(string s,int a,int b);



int main(int argc, char** argv) {
	int a[]={1,2,3,4,5,6,7,8,9};
	f(a,8,"",110);
	return 0;
}
//a:参加运算的元素
//k:目前考虑元素的下标
//so:结果串
//goal:目标值 
void f(int a[],int k,string so,int goal){
	if(k==0){
		if(a[0]==goal) cout<<so<<endl;
		return ;
	}
	
	f(a,k-1,pinjie("+",a[k],so),goal-a[k]);

	f(a,k-1,pinjie("-",a[k],so),goal+a[k]);
	
	int old=a[k-1];//old暂时存放原来k-1位置的元素 
	a[k-1]=str2num(pinjie("",a[k-1],a[k]);//a[k-1]用来存放与后面数字合并后的数字 
	f(a,k-1,so,goal);
	a[k-1]=old;//还原a[k] 
} 
//数字转字符串
string num2str(int i){
	stringstream ss;
	ss<<i;
	return ss.str();
} 
/*字符串转数字*/ 
int str2num(string s){
	int num;
	stringstream ss(s);
	ss>>num;
	return num;
}
/*字符串拼接*/
string pinjie(string s,int a,int b){
	stringstream ss;
	ss<<s<<a<<b;
	return ss.str();
}
//另一种方法 
//int i=atoi(s.c_str());
