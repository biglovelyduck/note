/*�˾��벦110,��ʹ�ֻ�Ƿ��Ҳ�ɲ�ͨ��
Ϊ�˱���������򣬱�������Ⱥ�������Ʋ���ȫ������������Ҫ���ﷸ���Ƕ��£������Ҫ�����Եؽ�������ѵ��������ѵ����

ĳ�������������ڽ�������ѵ����
1 2 3 4 5 6 7 8 9 = 110

�뿴�ϱߵ���ʽ��Ϊ��ʹ��ʽ��������Ҫ�����ּ�����ӺŻ��߼��ţ����Բ�������������������ţ���֮��û��������ŵ�������ϳ�һ���������磺12+34+56+7-8+9 ����һ�ֺϸ�����123+4+5+67-89 ����һ�����ܵĴ𰸡�

�������ü���������ƣ�����������������ҵ����д𰸡�
ÿ����ռһ�С����磺
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
//a:�μ������Ԫ��
//k:Ŀǰ����Ԫ�ص��±�
//so:�����
//goal:Ŀ��ֵ 
void f(int a[],int k,string so,int goal){
	if(k==0){
		if(a[0]==goal) cout<<so<<endl;
		return ;
	}
	
	f(a,k-1,pinjie("+",a[k],so),goal-a[k]);

	f(a,k-1,pinjie("-",a[k],so),goal+a[k]);
	
	int old=a[k-1];//old��ʱ���ԭ��k-1λ�õ�Ԫ�� 
	a[k-1]=str2num(pinjie("",a[k-1],a[k]);//a[k-1]���������������ֺϲ�������� 
	f(a,k-1,so,goal);
	a[k-1]=old;//��ԭa[k] 
} 
//����ת�ַ���
string num2str(int i){
	stringstream ss;
	ss<<i;
	return ss.str();
} 
/*�ַ���ת����*/ 
int str2num(string s){
	int num;
	stringstream ss(s);
	ss>>num;
	return num;
}
/*�ַ���ƴ��*/
string pinjie(string s,int a,int b){
	stringstream ss;
	ss<<s<<a<<b;
	return ss.str();
}
//��һ�ַ��� 
//int i=atoi(s.c_str());
