//2016天梯赛模拟题 A-B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string sa;
	string sb;
	getline(cin,sa);
	getline(cin,sb);
	for(int i=0;i<sb.length();i++){
		sa.erase(remove_if(sa.begin(),sa.end(),bind2nd(equal_to<char>(),sb[i])),sa.end());
	}
	cout<<sa<<endl;
}
