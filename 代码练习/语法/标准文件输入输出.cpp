#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
	//读取文件名用反斜杠或双斜杠 
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
char str[1]; //每个单词的长度不能超过2个字符
while(!OpenFile.eof())
    {
       OpenFile >> str;
       cout << str << endl;;
    }
	OpenFile.close();
	return 0;
}
