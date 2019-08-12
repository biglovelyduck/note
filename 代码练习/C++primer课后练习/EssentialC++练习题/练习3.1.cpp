#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <fstream>
using namespace std;
void initialize_exclusion_set(set<string>&);
void process_file(map<string,int>&,const set<string>&,ifstream&);
void user_query(const map<string,int>&);
void display_word_count(const map<string,int>&,ofstream&);
int main(){
	ifstream ifile("H:/Test/column.txt");
	ofstream ofile("H:/Test/column.map");
	if(!ifile||!ofile){
		cerr<<"Unable to oepn file -- bailing out!"<<endl;
		return -1;
	}
	set<string> excluded_set;
	initialize_exclusion_set(excluded_set);
	
	map<string,int> word_count;
	process_file(word_count,excluded_set,ifile);
	user_query(word_count);
	display_word_count(word_count,ofile);
	return 0;
}
void initialize_exclusion_set(set<string> &exs){
	static string _excluded_words[25]={
		"the","and","but","that","then","are","been",
		"can","a","could","did","for","of","had","have","him",
		"his","her","its","is","were","which","when","with","would"
	} ;
	exs.insert(_excluded_words,_excluded_words+25);
}
void process_file(map<string,int> &word_count,const set<string> &excluded_set,ifstream &ifile){
	string word;
	while(ifile>>word){
		if(excluded_set.count(word)) continue;
		word_count[word]++;
	}
}
void user_query(const map<string,int> &word_map){
	string search_word;
	cout<<"Please enter a word to search:q to quit";
	cin>>search_word;
	while(search_word.size()&&search_word!="q"){
		map<string,int>::const_iterator it;
		if((it=word_map.find(search_word))!=word_map.end()){
			cout<<"Found! "<<it->first<<"occurs "<<it->second<<"times.\n";
		}
		else cout<<search_word<<" was not found in text.\n";
		cout<<"\nAnother search? (q to quit) ";
		cin>>search_word;
	}
}
void display_word_count(const map<string,int> &word_map,ofstream &os){
	map<string,int>::const_iterator iter=word_map.begin(),end_it=word_map.end();
	while(iter!=end_it){
		os<<iter->first<<" ( "<<iter->second<<" ) "<<endl;
		++iter;
	}
	os<<endl;
}
