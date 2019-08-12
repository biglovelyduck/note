#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
//打印序列的模板 
template<typename Sequence>
void print(Sequence const& seq){
	for(const auto& i:seq){
		cout<<i<<" ";
	}
	cout<<endl; 
}
int main(){
	
	//27
	std::vector<int> vec{1,1,3,3,3,5,5,5,5,7,7,9};
	std::list<int> lst;
	std::unique_copy(vec.cbegin(),vec.cend(),inserter(lst,lst.begin()));
	for(auto i:lst) 
		std::cout<<i<<" ";
	std::cout<<std::endl;
	
	//28
	vector<int> vec1={1,2,3,4,5,6,7,8,9};
	list<int> lst1,lst2,lst3;
	copy(vec1.cbegin(),vec1.cend(),inserter(lst1,lst1.begin()));
	copy(vec1.cbegin(),vec1.cend(),back_inserter(lst2));
	copy(vec1.cbegin(),vec1.cend(),front_inserter(lst3));
	print(lst1);
	print(lst2);
	print(lst3);
	return 0;
}
