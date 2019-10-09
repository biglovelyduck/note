//65-有效数字 
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
//内功 
class Solution {
public:
    bool isNumber(string &s) {
        // regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
        int i=s.find_first_not_of(' ');						//找到字符串起始的位置 
        int d1=0, dot=0, d2=0, e=0, d3=0;
        if(s[i]=='+' || s[i]=='-') ++i;						//开头是符号位跳过 
        for(; i<s.length() && isdigit(s[i]); d1=++i);		//d1小数点前数字结尾的后一位 
        if(i<s.length() && s[i]=='.') dot=++i;				//dot是小数点的后一位 
        for(; i<s.length() && isdigit(s[i]); d2=++i);		//d2是小数点后数字结尾的后一位 
        if(dot && !d1 && !d2) return false;
        if(i<s.length() && (d1||d2) && s[i]=='e') e=++i;	//e保存e的后一位 
        if(i<s.length() && e && (s[i]=='+'|s[i]=='-')) ++i;
        for(; i<s.length() && isdigit(s[i]); d3=++i);
        if(e && (!(d1||d2) || !d3)) return false;
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length();
    }
};


//正则表达式 
class Solution1 {
public:
    bool isNumber(string &s) {
        return regex_match(s,regex("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$"));
    }
};

//状态自动机 
/*java实现：
public boolean isNumber(String s) {
    int state = 0; 
    s = s.trim();//去除头尾的空格
    //遍历所有字符，当做输入
    for (int i = 0; i < s.length(); i++) {
        switch (s.charAt(i)) {
             //输入正负号
            case '+':
            case '-':
                if (state == 0) {
                    state = 1;
                } else if (state == 4) {
                    state = 6;
                } else {
                    return false;
                }
                break;
            //输入数字
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                //根据当前状态去跳转
                switch (state) {
                    case 0:
                    case 1:
                    case 2:
                        state = 2;
                        break;
                    case 3:
                        state = 3;
                        break;
                    case 4:
                    case 5:
                    case 6:
                        state = 5;
                        break;
                    case 7:
                        state = 8;
                        break;
                    case 8:
                        state = 8;
                        break;
                    default:
                        return false;
                }
                break;
            //小数点
            case '.':
                switch (state) {
                    case 0:
                    case 1:
                        state = 7;
                        break;
                    case 2:
                        state = 3;
                        break;
                    default:
                        return false;
                }
                break;
            //e
            case 'e':
                switch (state) {
                    case 2:
                    case 3:
                    case 8:
                        state = 4;
                        break;
                    default:
                        return false;
                }
                break;
            default:
                return false;

        }
    }
    //橙色部分的状态代表合法数字
    return state == 2 || state == 3 || state == 5 || state == 8;
}

作者：windliang
链接：https://leetcode-cn.com/problems/valid-number/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
