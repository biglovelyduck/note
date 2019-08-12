#include "ex_12.27-30.h"
#include <sstream>//stirng流 
#include <algorithm>
#include <iostream>

using namespace std;

//读取文件 
TextQuery::TextQuery(ifstream &ifs):input(new vector<string>){
	LineNo lineNo{0};//初始化lineNo=0 
	for(string line;getline(ifs,line);++lineNo){//读取一行 
		input->push_back(line);//vector保存每行
		istringstream line_stream(line);//将输入的行转为string流
		//每次读取一个字符串，遇到空格或者结尾停止 
		for(string text,word;line_stream>>text;word.clear()) {//遍历单词 
			//avoid read a word followed by punctuation(such as:word,)  标点 
			//[b,e) 删p条件，结果存入r
			//检查参数c是否为标点符号或特殊符号。返回TRUE也就是代表参数c为非空格、非数字和非英文字母。
			//将text去除标点存入word ispunct判断标点或者特殊符号 
			remove_copy_if(text.begin(),text.end(),back_inserter(word),ispunct);
			//std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			//use reference aviod count of shared_ptr add.
			auto &nos=result[word];//nos是一个指向set的指针的引用 
			// 如果这个单词第一次出现 ，就新建一个set 
			if(!nos) nos.reset(new set<LineNo>); 
			nos->insert(lineNo); 
		}
	}
}
//查找单词 
QueryResult TextQuery::query(const string &str) const{
	//use static just allocate once. 使用静态只分配一次
	static shared_ptr<set<LineNo> > nodate(new set<LineNo>);//nodate是一个共享指针，指向空set
	auto found=result.find(str);//found是返回的迭代器 
	//没有这个单词 
	if(found==result.end()) return QueryResult(str,nodate,input);
	else return QueryResult(str,found->second,input);
} 
//将查找的结果打印 
ostream& print(ostream &out,const QueryResult &qr){
	out<<qr.word<<" occurs"<<qr.nos->size()<<(qr.nos->size()>1?" times":"time")<<endl;
	for(auto i:*qr.nos)
		out<<"\t(line "<<i+1<<") "<<qr.input->at(i)<<endl;
	return out;
}

void runQueries(ifstream &infile){
	TextQuery tq(infile);
	while(true){
		cout<<"enter word to look for, or q to quit: ";
		string s;
		if(!(cin>>s)||s=="q") break;
		print(cout,tq.query(s))<<endl;
	}		
}

int main(){
	std::ifstream file("../data/storyDataFile.txt");
    runQueries(file);
}
