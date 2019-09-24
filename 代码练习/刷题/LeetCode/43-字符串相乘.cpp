//43-字符串相乘
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
using namespace std;
/* 
class Solution {
public:
	//写错了，写的字符串相加 
    string multiply1(string num1, string num2) {
        if(num1.size()==0) return num2;
        if(num2.size()==0) return num1;
		int i=num1.size()-1,j=num2.size()-1;
		int carry=0,left=0;
		string s="";
		while(i>=0&&j>=0){
			int sum=(num1[i]-'0')+(num2[j]-'0');
			left=sum%10;
			s+=to_string(left+carry);
			carry=sum/10;
			i--,j--;
		} 
		while(i>=0){
			s+=num1[i];
			i--;
		}
		while(j>=0){
			s+=num2[j];
			j--;
		}
		reverse(s.begin(),s.end());
		return s;
    }
    //算了写不出来。。。。 
    string multiply(string num1,string num2){
    	if(num1=="0"||num2=="0") return 0;
    	stirng s="";
    	for(int i=num1.size()-1;i>=0;i--){
    		for(int j=num2.size()-1;j>=0;j++){
    			int product=(num1[i]-'0')*(num2[j]-'0');
    			int carry=product/10;
    			int left=product%10;
    			int num=num1.size()-1-i;	//要乘多少个10; 
    			s=multiply1(s,to_string())
			}
		}
	} 
}; */
class Solution{
public:
	string multiply(string num1,string num2){
		int n1=num1.size();
		int n2=num2.size();
		string res(n1+n2,'0');
		for(int i=n2-1;i>=0;i--){
			for(int j=n1-1;j>=0;j--){
				int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
				res[i+j+1]=temp%10+'0';		//当前位
				//前一位加上进位,不用有意转化成数字 
				res[i+j]+=temp/10; 
			}
		}
		for(int i=0;i<n1+n2;i++){
			if(res[i]!='0') return res.substr(i);
		} 
		return "0";
	}
};
int main(){
	Solution s;
	cout<<s.multiply("123","456");
	return 0;
}
