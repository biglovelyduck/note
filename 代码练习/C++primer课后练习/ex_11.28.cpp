#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	multimap<string,vector<int> > m;
	m={{"Allan",{1,2,3,4,5}},{"John",{5,4,3,2,1}}};
	map<string,vector<int> >::const_iterator it=m.find("Allan");
	cout<<it->first;
	return 0;
} 
