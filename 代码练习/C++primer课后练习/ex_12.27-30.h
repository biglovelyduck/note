#ifndef _ex_12.27-30_h
#define _ex_12.27-30_h
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std; 

class QueryResult;

class TextQuery{
public:
	using LineNo=vector<string>::size_type;//行号，vector下标 
	TextQuery(ifstream &);//构造函数 
	QueryResult query(const string&) const;//查询结果集,传入一个单词 
private:
	shared_ptr<vector<string> > input;//每个元素保存每一行 
	map<string,shared_ptr<set<LineNo> > > result;//每个单词对应的行号set 
};

class QueryResult{
public:
	friend ostream& print(ostream&,const QueryResult&);
	QueryResult(const string &s,shared_ptr<set<TextQuery::LineNo> > set,shared_ptr<vector<string> > v):
		word(s),nos(set),input(v){
			
		}
private:
	string word;//查询的单词 
	shared_ptr<set<TextQuery::LineNo> > nos;//该单词出现的所有行号 
	shared_ptr<vector<string> > input;
}; 

ostream& print(ostream &,const QueryResult &);

#endif
