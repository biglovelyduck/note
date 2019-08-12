#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
int main(){
	vector<int> v={5,7,8,9};
	modulus<int> mod;
	int num;
	while(cin>>num){
		string ret="no\n";
		for(auto i:v){
//			if(!mod(num,i)){
//				ret="yes\n";
//				break;
//			}
			cout<<mod(num,i)<<endl;
		}
		cout<<ret;
	}
	return 0;
}
