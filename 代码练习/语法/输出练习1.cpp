/*1 ���ʵ��������������/�����
    (1)������뷽ʽ�������,���Ϊ12��
    (2)�԰˽��ơ�ʮ���ơ�ʮ����������/���������
    (3)ʵ�ָ�������ָ����ʽ�Ͷ����ʽ������/���,��ָ�����ȡ�
    (4)���ַ��������ַ������������,�Ӽ�������,Ҫ�����봮�Ŀո�Ҳȫ������,�Իس���������
    (5)������Ҫ��������Ա�����Ͳ���������һ�顣*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	long a=234;
	double b=2345.67890;
	char c[100];
	cout.fill('*');
	cout.flags(ios_base::left);//����뷽ʽ 
	cout.width(12);
	cout<<a<<endl;
	cout.fill('*');
	cout.flags(ios::right);//�Ҷ��뷽ʽ 
	cout.width(12);
	cout<<a<<endl;
	cout.flags(ios::hex);
	cout<<234<<'\t';
	cout.flags(ios::dec);
	cout<<234<<'\t';
	cout.flags(ios::oct);
	cout<<234<<endl;
	cout.flags(ios::scientific);
	cout<<b<<'\t';
	cout.flags(ios::fixed);
	cout<<b<<endl;
	cin.get(c,99);
	cout<<c<<endl;
	return 0;
}
//������ʵ��

int main01(){
	long a=234;
	double b=2345.67890;
	char c[100];
	cout<<setfill('*');
	cout<<left<<setw(12)<<a<<endl;
	cout<<right<<setw(12)<<a<<endl;
	cout<<hex<<a<<'\t'<<dec<<a<<'\t'<<oct<<a<<endl;
	cout<<scientific<<b<<'\t'<<fixed<<b<<endl;
	return 0;
}

