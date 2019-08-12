#include <iostream>
using namespace std;
class HasPtr{
public:
	HasPtr(const string &s=string()):ps(new string(s)),i(0){
		
	}
	HasPtr(const HasPtr &hp):ps(new string(*hs.ps)),i(hp.i){
		
	}
	HasPtr& operator=(const HasPtr &hp){
		auto new_p=new string(*hp.ps);
		delete ps;//删除ps原来指向的空间
		ps=new_p;//ps指向新空间
		i=hp.i;
		return *this; 
	}
	~HasPtr(){
		delete ps;
	}
private:
	string *ps;
	int i;
};
