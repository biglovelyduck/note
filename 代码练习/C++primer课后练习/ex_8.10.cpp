#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main(){
	ifstream ifs("�ļ�·��");//�ļ��� 
	if(!ifs){
		cerr<<"No data"<<endl;
		return -1;
	}
	vector<string> vecLine;
	string line;
	while(getline(ifs,line)){//�Ӳ���1����ÿ�ζ�ȡһ�� �������� 
		vecLine.push_back(line); 
	}
	for(auto &s:vecLine){
		istringstream iss(s);//��string�󶨵�string����
		string word;
		while(iss>>word){//�����ո�Ͳ�������cinһ�� 
			cout<<word<<endl;
		} 
	} 
	return 0;
}
