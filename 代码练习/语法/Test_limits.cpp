#include <iostream>
#include <limits>
using namespace std;
int main(){
	int max_int=numeric_limits<int>::max();
	int min_int=numeric_limits<int>::min();
	int max_double=numeric_limits<double>::max();
	int min_double=numeric_limits<double>::min();
	int max_ll=numeric_limits<long>::max();
	int min_ll=numeric_limits<long>::min();
	cout<<min_int<<"----"<<max_int<<endl;
	cout<<min_double<<"----"<<max_double<<endl;
	cout<<min_ll<<"----"<<max_ll<<endl;
	return 0;
}
