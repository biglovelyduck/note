#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> //字符串流
using namespace std;
//转换规则函数 
map<string,string> buildMap(ifstream &map_file){
	map<string,string> trans_map;
	for(string ket,value;map_file>>key&&getline(map_file,value);)
		if(value.size()>1) trans_map[key]=value.substr(1).substr(0,value.find_last_not_of(' '));
		return trans_map;
}
//返回将s通过m的转换 
const string& transform(const string &s,const map<string,string> &m){
	auto map_it=m.find(s);
	return map_it==map.cend()?s:map_it->second;
}
//主函数 
void word_transform(ifstream &map,ifstream &input) {
	auto trans_map=buildMap(map);
	for(string text;getline(input,text);){
		istringstream iss(text);//转换为string流
		for(string word;iss>>word) //读取单词
			cout<<transform(word,trans_map);
		cout<<endl; 
	}
}
int main(){
	ifstream ifs_map("转换规则文件路径"),ifs_content("文件路径");
	if(ifs_map&&ifs_content) word_transform(ifs_map,ifs_content);
	else cout<<"error!"<<endl;
}
