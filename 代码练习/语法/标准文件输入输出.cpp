#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
	//��ȡ�ļ����÷�б�ܻ�˫б�� 
	ifstream OpenFile("H:/Test/word.txt");
	char s[100][100];
	char c;
	int i=0;
	//string str;
//	while(!ifs.eof()){
//		//ifs.get(c);
//		//ifs>>c;
//		//ifs.getline(s[i++],7);
//		//cout<<s[i];
//		//getline(ifs,str);
//		//cout<<str<<endl;
//		
//	}
char str[1]; //ÿ�����ʵĳ��Ȳ��ܳ���2���ַ�
while(!OpenFile.eof())
    {
       OpenFile >> str;
       cout << str << endl;;
    }
	OpenFile.close();
	return 0;
}
