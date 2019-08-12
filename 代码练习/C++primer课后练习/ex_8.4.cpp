#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using std::cin;
using std::vector;using std::string;using std::ifstream;using std::cout;using std::endl;

void ReadFileToVec(const string& fileName,vector<string>& vec){
	ifstream ifs(fileName);
	if(ifs){
		string buf;
		while(std::getline(ifs,buf))
			vec.push_back(buf);
		//若是读取单个单词：
		/*
		while(ifs>>buf)
			vec.push_back(buf); 
		*/ 
	}
}
int main(int argc,char* argv[]){
	cin>>argc;
	if(argc!=2) cout<<"number Error!"<<endl;
	return 0;
} 
