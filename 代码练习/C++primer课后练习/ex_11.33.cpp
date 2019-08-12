#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> //�ַ�����
using namespace std;
//ת�������� 
map<string,string> buildMap(ifstream &map_file){
	map<string,string> trans_map;
	for(string ket,value;map_file>>key&&getline(map_file,value);)
		if(value.size()>1) trans_map[key]=value.substr(1).substr(0,value.find_last_not_of(' '));
		return trans_map;
}
//���ؽ�sͨ��m��ת�� 
const string& transform(const string &s,const map<string,string> &m){
	auto map_it=m.find(s);
	return map_it==map.cend()?s:map_it->second;
}
//������ 
void word_transform(ifstream &map,ifstream &input) {
	auto trans_map=buildMap(map);
	for(string text;getline(input,text);){
		istringstream iss(text);//ת��Ϊstring��
		for(string word;iss>>word) //��ȡ����
			cout<<transform(word,trans_map);
		cout<<endl; 
	}
}
int main(){
	ifstream ifs_map("ת�������ļ�·��"),ifs_content("�ļ�·��");
	if(ifs_map&&ifs_content) word_transform(ifs_map,ifs_content);
	else cout<<"error!"<<endl;
}
