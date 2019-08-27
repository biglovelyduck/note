//12-整数转罗马数字
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std; 
//1.完全查表法 
class Solution {
public:
	string bit1[10] { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	string bit10[10] { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	string bit100[10] { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	string bit1000[4] { "", "M", "MM", "MMM" };
    string intToRoman(int num) {
        return bit1000[num / 1000] + bit100[num % 1000 / 100] + bit10[num % 100 / 10] + bit1[num % 10];
    }
}; 

//0ms解法
char * intToRoman(int num){
    char * ret = NULL;
    if (num <= 0 || num > 3999) return ret;
    ret = (char *) malloc (sizeof(char) * 16);
    if (ret == NULL) {
        printf("申请内存出错");
        exit(0);
    }
    ret[15] = 0; // memset(ret, 0, 16);
    
    char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char i = 14, j = 0, m = 0;
    
    while(num) {
        m = num % 10;
        num /= 10;
        while (1) {
            if (m == 9) {ret[i--] = Rome[j+2]; m = 1;}
            else if (m == 8) {ret[i--] = Rome[j]; m--;}
            else if (m == 7) {ret[i--] = Rome[j]; m--;}
            else if (m == 6) {ret[i--] = Rome[j]; m--;}
            else if (m == 5) {ret[i--] = Rome[j+1]; break;}
            else if (m == 4) {ret[i--] = Rome[j+1]; m=1;}
            else if (m == 3) {ret[i--] = Rome[j]; m--;}
            else if (m == 2) {ret[i--] = Rome[j]; m--;}
            else if (m == 1) {ret[i--] = Rome[j]; break;}
            else break;
        }
        j += 2;
    }
    return (ret + i + 1);
}

//3.hash方法
class Solution {
public:
    	string intToRoman(int num) {
		vector<int> value = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		vector<string> dic = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string str;
		int i = 0;
		while (num > 0 && i < dic.size()) {
			if (num >= value[i]) {
				str += dic[i];
				num -= value[i];
			}
			else
				i++;
		}
		return str;
	}

};


