//65-��Ч���� 
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
//�ڹ� 
class Solution {
public:
    bool isNumber(string &s) {
        // regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
        int i=s.find_first_not_of(' ');						//�ҵ��ַ�����ʼ��λ�� 
        int d1=0, dot=0, d2=0, e=0, d3=0;
        if(s[i]=='+' || s[i]=='-') ++i;						//��ͷ�Ƿ���λ���� 
        for(; i<s.length() && isdigit(s[i]); d1=++i);		//d1С����ǰ���ֽ�β�ĺ�һλ 
        if(i<s.length() && s[i]=='.') dot=++i;				//dot��С����ĺ�һλ 
        for(; i<s.length() && isdigit(s[i]); d2=++i);		//d2��С��������ֽ�β�ĺ�һλ 
        if(dot && !d1 && !d2) return false;
        if(i<s.length() && (d1||d2) && s[i]=='e') e=++i;	//e����e�ĺ�һλ 
        if(i<s.length() && e && (s[i]=='+'|s[i]=='-')) ++i;
        for(; i<s.length() && isdigit(s[i]); d3=++i);
        if(e && (!(d1||d2) || !d3)) return false;
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length();
    }
};


//������ʽ 
class Solution1 {
public:
    bool isNumber(string &s) {
        return regex_match(s,regex("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$"));
    }
};

//״̬�Զ��� 
/*javaʵ�֣�
public boolean isNumber(String s) {
    int state = 0; 
    s = s.trim();//ȥ��ͷβ�Ŀո�
    //���������ַ�����������
    for (int i = 0; i < s.length(); i++) {
        switch (s.charAt(i)) {
             //����������
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
            //��������
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
                //���ݵ�ǰ״̬ȥ��ת
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
            //С����
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
    //��ɫ���ֵ�״̬����Ϸ�����
    return state == 2 || state == 3 || state == 5 || state == 8;
}

���ߣ�windliang
���ӣ�https://leetcode-cn.com/problems/valid-number/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-4/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
