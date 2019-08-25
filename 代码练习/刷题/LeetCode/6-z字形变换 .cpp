//6-z字形变换 
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//1.按行排序 
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
		vector<string> rows(min(numRows,int(s.size())));	//确定行数
		int curRow=0;
		bool goingDown=false;
		for(char c:s){
			rows[curRow]+=c;
			if(curRow==0||curRow==numRows-1) goingDown=!goingDown;
			curRow+=goingDown?1:-1;
		} 
		string ret;
		for(string row:rows) ret+=row;
		return ret;
    }
};

//2.按行访问 	
/**/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
		string ret;
		int n=s.size();
		int cycleLen=2*numRows-2; 
		for(int i=0;i<numRows;i++){
			for(int j=0;j+i<n;j+=cycleLen){
				ret+=s[j+i];
				if(i!=0&&i!=numRows-1&&j+cycleLen-i<n)
					ret+=s[j+cycleLen-i];
			}
		} 
		return ret;
    }
};
