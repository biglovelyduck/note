//67-二进制求和
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include<regex>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
    	int len_a=a.length(),len_b=b.length();
		int i=len_a-1,j=len_b-1;
		int jinwei=0;
		string s;
		while(i>=0&&j>=0){
			int sum=a[i]-'0'+b[j]-'0'+jinwei;
			s+=to_string(sum%2);
			jinwei=sum/2;
			i--,j--;
		} 
		while(i>=0){
			int sum=a[i]-'0'+jinwei;
			s+=to_string(sum%2);
			jinwei=sum/2;
			i--;
		}
		while(j>=0){
			int sum=b[j]-'0'+jinwei;
			s+=to_string(sum%2);
			jinwei=sum/2;
			j--;
		}
		if(jinwei) s+=to_string(jinwei);
		reverse(s.begin(),s.end());
		return s;
    }
};

int main(){
	Solution s;
	cout<<s.addBinary("11","1");
	return 0;
}
 
