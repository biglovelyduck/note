#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> v1;
	cout<<v1.size()<<endl;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout<<v1.size()<<endl;
	while(v1.size()>0){
		cout<<v1.back()<<" ";
		v1.pop_back();
	}
	return 0;
} 
