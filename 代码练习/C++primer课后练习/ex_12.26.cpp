#include <iostream>
#include <string>
#include <memory>
using namespace std;

void input_reverse_output_string(int n){
	allocator<string> alloc;
	auto const p=alloc.allocate(n);
	string s;
	auto q=p;
	while(cin>>s&&q!=p+n){
		alloc.construct(q++,s);
	}
	while(q!=p){
		cout<<*--q<<" ";
		alloc.destroy(q);
	}
	alloc.deallocate(p,n);
	
}

int main(){
	input_reverse_output_string(5);
	return 0;
}
