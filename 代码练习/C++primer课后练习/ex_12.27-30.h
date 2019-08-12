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
	using LineNo=vector<string>::size_type;//�кţ�vector�±� 
	TextQuery(ifstream &);//���캯�� 
	QueryResult query(const string&) const;//��ѯ�����,����һ������ 
private:
	shared_ptr<vector<string> > input;//ÿ��Ԫ�ر���ÿһ�� 
	map<string,shared_ptr<set<LineNo> > > result;//ÿ�����ʶ�Ӧ���к�set 
};

class QueryResult{
public:
	friend ostream& print(ostream&,const QueryResult&);
	QueryResult(const string &s,shared_ptr<set<TextQuery::LineNo> > set,shared_ptr<vector<string> > v):
		word(s),nos(set),input(v){
			
		}
private:
	string word;//��ѯ�ĵ��� 
	shared_ptr<set<TextQuery::LineNo> > nos;//�õ��ʳ��ֵ������к� 
	shared_ptr<vector<string> > input;
}; 

ostream& print(ostream &,const QueryResult &);

#endif
