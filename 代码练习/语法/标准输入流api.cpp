#include <iostream>
using namespace std;

void main01()
{
	char YourName[50];
	int myInt;
	long myLong;
	double myDouble;
	float myFloat;
	unsigned int myUnsigned;

	cout << "������һ��Int: ";
	cin >> myInt;
	cout << "������һ��Long: ";
	cin >> myLong;
	cout << "������һ��Double: ";
	cin >> myDouble;

	cout << "�������������: ";
	cin >> YourName;

	cout << "\n\n����������ǣ�" << endl;
	cout << "Int: \t" << myInt << endl;
	cout << "Long: \t" << myLong << endl;
	cout << "Double: \t" << myDouble << endl;
	cout << "����: \t" << YourName << endl;
	cout<< endl << endl;
	system("pause");
	return ;
}

//1 ����Ӣ�� ok 
//2 ctr+z  �����һ�� EOF(-1)
int main02()
{
	char ch;
	while( (ch= cin.get())!= EOF)
	{
		std::cout << "�ַ�: " << ch << std::endl;
	}
	std::cout << "\n����.\n";
	system("pause");
	return 0;
}

//��ʾ:��һ���ַ� ��ʽ���
int main03()
{
	char a, b, c;
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << b << c<< endl;

	cout << "��ʼ��ʽ���" << endl;
	cout.flush();

	cin.get(a).get(b).get(c);
	cout << a << b << c<< endl;
	system("pause");
	return 0;
}


//��ʾcin.getline() ���Խ��ܿո�
int main04()
{
	char buf1[256];
	char buf2[256]; 
	cout << "\n����������ַ��� ������256" ;
	cin.getline(buf1, 256, '\n'); 
	cout << buf1 << endl;

	// 
	cout << "ע��: cin.getline() �� cin >> buf2 ������, �ܲ��ܴ��ո� " << endl;
	cin >> buf2 ; //����ȡ������ �����ո� ֹͣ��ȡ������
	cout << buf2 << endl;
	system("pause");
	return 0;
}

//������ʵ�� 
/*
1 ���� "aa bb cc dd" �ַ����뻺���� 
2 ͨ�� cin >> buf1; ������ aa 
3 ����Ҫ���� ������ͨ��cin.getline() ��ʣ��Ļ�������������
*/
int main05()
{
	char buf1[256];
	char buf2[256];

	cout << "��������пո���ַ���,���Ի�����" << endl; 
	cin >> buf1;
	cout << "buf1:" << buf1 << endl; 

	cout << "����������..." << endl;

	//������û������,�͵ȴ�; ���������������ֱ�Ӵӻ���������������
	cin.getline(buf2, 256); 
	cout << "buf2:" << buf2 << endl;
	system("pause");
	return 0;
}

// ignore �� peek
void main06()
{
	int  intchar;
	char buf1[256];
	char buf2[256];

	cout << "��������пո���ַ���,���Ի����� aa bb cc dd ee " << endl; 
	cin >> buf1;
	cout << "buf1:" << buf1 << endl; 

	cout << "����������..." << endl;
	cin.ignore(2);
	//intchar = cin.peek();
	//cout << "��������������,���ص�һ�����ݵ�asc��:" << intchar << endl;

	//������û������,�͵ȴ�; ���������������ֱ�Ӵӻ���������������
	cin.getline(buf2, 256); 
	cout << "buf2:" << buf2 << endl;

	intchar = cin.peek(); //û�л����� Ĭ��������ģʽ 
	cout << "��������������,���ص�һ�����ݵ�asc��:" << intchar << endl;
	system("pause");
}

//����:������������ַ����ֿ�����
int main() 
{
	cout << "Please, enter a number or a word: ";
	char c = std::cin.get();

	if ( (c >= '0') && (c <= '9') ) //������������ַ��� �ֿ�����
	{
		int n; //���������� �м��пո� ʹ��cin >>n
		cin.putback (c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback (c);
		getline (cin,str); // //�ַ��� �м�����пո� ʹ�� cin.getline();
		cout << "You entered a word: " << str << '\n';
	}	system("pause");
	return 0;
}

