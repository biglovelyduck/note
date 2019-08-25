//8-字符串转换成整数 
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0) return 0;
        long res=0;
        int start,i=0;
        bool minus=false;
        while(str[i]==' ') i++;
        start=i;	//cout<<"start:"<<start<<endl;
        if(str[start]=='-'){
        	minus=true;
			start+=1;	
		}
		else if(str[start]=='+')	start+=1;
		//cout<<"start:"<<start<<endl;
		if(str[start]>='0'&&str[start]<='9'){
			i=start;
			res=res*10+str[i]-'0';
			i++;
		}
		else{
			return 0;
		}
		while(str[i]>='0'&&str[i]<='9'){
			res=res*10+str[i]-'0';
			i++;
			if(res>INT_MAX||-res<INT_MIN) return minus?INT_MIN:INT_MAX;
		}
		if(minus)	return -res;
		else	return res;
    }
};

//大佬解法
class Solution {
public:
    int myAtoi(string str) {
        int digit=0;
        istringstream is(str);
        is>>digit;
        return digit;
    }
};


int main(){
	string s="42";
	Solution sol;
	cout<<sol.myAtoi(s);
	return 0;
}
