#include "ex_12.27-30.h"
#include <sstream>//stirng�� 
#include <algorithm>
#include <iostream>

using namespace std;

//��ȡ�ļ� 
TextQuery::TextQuery(ifstream &ifs):input(new vector<string>){
	LineNo lineNo{0};//��ʼ��lineNo=0 
	for(string line;getline(ifs,line);++lineNo){//��ȡһ�� 
		input->push_back(line);//vector����ÿ��
		istringstream line_stream(line);//���������תΪstring��
		//ÿ�ζ�ȡһ���ַ����������ո���߽�βֹͣ 
		for(string text,word;line_stream>>text;word.clear()) {//�������� 
			//avoid read a word followed by punctuation(such as:word,)  ��� 
			//[b,e) ɾp�������������r
			//������c�Ƿ�Ϊ�����Ż�������š�����TRUEҲ���Ǵ������cΪ�ǿո񡢷����ֺͷ�Ӣ����ĸ��
			//��textȥ��������word ispunct�жϱ������������ 
			remove_copy_if(text.begin(),text.end(),back_inserter(word),ispunct);
			//std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			//use reference aviod count of shared_ptr add.
			auto &nos=result[word];//nos��һ��ָ��set��ָ������� 
			// ���������ʵ�һ�γ��� �����½�һ��set 
			if(!nos) nos.reset(new set<LineNo>); 
			nos->insert(lineNo); 
		}
	}
}
//���ҵ��� 
QueryResult TextQuery::query(const string &str) const{
	//use static just allocate once. ʹ�þ�ֻ̬����һ��
	static shared_ptr<set<LineNo> > nodate(new set<LineNo>);//nodate��һ������ָ�룬ָ���set
	auto found=result.find(str);//found�Ƿ��صĵ����� 
	//û��������� 
	if(found==result.end()) return QueryResult(str,nodate,input);
	else return QueryResult(str,found->second,input);
} 
//�����ҵĽ����ӡ 
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
