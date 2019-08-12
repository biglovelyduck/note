#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	vector<int> input;
	istream_iterator<int> in(cin),eos;
	copy(in,eos,back_inserter(input)); 
	//input.assign(1);
	//cout<<input[0]<<endl;
	return 0;
}
