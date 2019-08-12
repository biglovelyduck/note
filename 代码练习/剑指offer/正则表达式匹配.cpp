//正则表达式匹配
/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符
匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/ 

/*假设字符串为str，模式串为pattern，考虑以下情况：

A. 模式串下一个字符为*，即*(pattern+1)=='*'：

如果当前字符匹配，即*str=*pattern或者*str='.' && *pattern!='\0'，三种可能：

 1、模式串当前字符出现0次，即*表示当前字符出现0次，则str=str,pattern=pattern+2;

 2、模式串当前字符出现1次，即*表示当前字符出现1次，则str=str+1,pattern=pattern+2;

 3、模式串当前字符出现2次或2次以上，即*表示当前字符出现2次或以上，则str=str+1,pattern=pattern;

如果当前字符不匹配，则只能让*表示当前字符出现0次，则str=str，pattern=pattern+2;

B. 模式串下一个字符不为*

如果当前字符匹配，即*str=*pattern或者*str='.' && *pattern!='\0'，则str=str+1,pattern=pattern+1.*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if(str==nullptr||pattern==nullptr) return false;
    	return matchCore(str,pattern);
    }
    bool matchCore(char* str,char* pattern){
    	if(*str=='\0'&&*pattern=='\0') return true;
    	if(*str!='\0'&&*pattern=='\0') return false;
    	//if(*str=='\0'&&*pattern!='\0') return false;
    	
    	if(*(pattern+1)=='*'){
    		if(*pattern==*str||(*pattern=='.'&&*str!='\0')){
    			//move on the next state
    			return matchCore(str+1,pattern+2)
				||matchCore(str+1,pattern)	//stay on the current state 
				||matchCore(str,pattern+2);	//ignore a'*'
			}
			else{
				return matchCore(str,pattern+2);
			}
		}
		if(*str==*pattern||(*pattern=='.'&&*str!=85'\0'))
			return matchCore(str+1,pattern+1);
		return false; 
	}
};
