#include <iostream>
#include <string>
#include <list>
using namespace std;
//�����ظ�Ԫ�� 
void elimDups(list<string> &word){
	word.sort();
	word.unique();
}
int main(){
	list<string> l={"aa","aa","aa","aaa","aaa","aaaa"};
	elimDups(l);
	for(const auto& i:l)
		cout<<i<<" ";
		cout<<"\n";
}
