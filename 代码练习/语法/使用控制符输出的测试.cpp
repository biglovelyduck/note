#include <iostream>
#include <iomanip>
using namespace std; 
int main()
{
	int a;
	cout<<"input a:";
	cin>>a;
	cout<<"dec:"<<dec<<a<<endl; //��ʮ������ʽ�������
	cout<<"hex:"<<hex<<a<<endl; //��ʮ��������ʽ�������a
	cout<<"oct:"<<setbase(8)<<a<<endl; //�԰˽�����ʽ�������a
	char *pt="China"; //ptָ���ַ���"China"
	cout<<setw(10)<<pt<<endl; //ָ�����Ϊ,����ַ���
	cout<<setfill('*')<<setw(10)<<pt<<endl; //ָ�����,����ַ���,�հ״���'*'���
	double pi=22.0/7.0; //����piֵ
	//��ָ����ʽ���,8λС��
	cout<<setiosflags(ios::scientific)<<setprecision(8);
	cout<<"pi="<<pi<<endl; //���piֵ
	cout<<"pi="<<setprecision(4)<<pi<<endl; //��ΪλС��
	cout<<"pi="<<setiosflags(ios::fixed)<<pi<<endl; //��ΪС����ʽ���
	system("pause");
	return 0;
}

