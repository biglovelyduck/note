//第一个只出现一次的字符 
#include <map>
using namespace std;
class Solution{
public:
	int FirstNotRepeatingChar(string str){
		map<char,int> m;
		for(int i=0;i<str.size();i++){
			m[str[i]]++;
		}
		for(int i=0;i<str.size();i++){
			if(m[str[i]]==1) return i;
		}
		return -1;
	}
};
