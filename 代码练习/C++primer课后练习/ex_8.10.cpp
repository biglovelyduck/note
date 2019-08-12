#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main(){
	ifstream ifs("文件路劲");//文件流 
	if(!ifs){
		cerr<<"No data"<<endl;
		return -1;
	}
	vector<string> vecLine;
	string line;
	while(getline(ifs,line)){//从参数1流中每次读取一行 放入数组 
		vecLine.push_back(line); 
	}
	for(auto &s:vecLine){
		istringstream iss(s);//将string绑定到string流中
		string word;
		while(iss>>word){//遇到空格就不读，和cin一样 
			cout<<word<<endl;
		} 
	} 
	return 0;
}
