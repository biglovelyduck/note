//输入一串数字，翻译成指定的字符串,问有几种翻译方法
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <functional>
using namespace std;
int getTransferCounts(const string& s){
	int len = s.length();
	int *counts = new int[len];
	int count = 0;
	for (int i = len - 1; i >= 0; i--){
		count = 0;
		//i不是最后一位
		if (i < len - 1)
			count = counts[i + 1];
		else//i是最后一位
			count = 1;
		if (i < len - 1){
			int digit1 = s[i] - '0';
			int digit2 = s[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <=25){
				if (i < len - 2) count += counts[i + 2];
				else count += 1;
			}
		}
		counts[i] = count;
	}
	count = counts[0];
	return count;
}
int getTransferCount(int number){
	if (number < 0)  return 0;
	string s = to_string(number);
	return getTransferCounts(s);
}

int main(){
	cout << getTransferCount(12258);
	return 0;
}
