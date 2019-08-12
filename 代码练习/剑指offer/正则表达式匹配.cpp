//������ʽƥ��
/*��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�
ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��*/ 

/*�����ַ���Ϊstr��ģʽ��Ϊpattern���������������

A. ģʽ����һ���ַ�Ϊ*����*(pattern+1)=='*'��

�����ǰ�ַ�ƥ�䣬��*str=*pattern����*str='.' && *pattern!='\0'�����ֿ��ܣ�

 1��ģʽ����ǰ�ַ�����0�Σ���*��ʾ��ǰ�ַ�����0�Σ���str=str,pattern=pattern+2;

 2��ģʽ����ǰ�ַ�����1�Σ���*��ʾ��ǰ�ַ�����1�Σ���str=str+1,pattern=pattern+2;

 3��ģʽ����ǰ�ַ�����2�λ�2�����ϣ���*��ʾ��ǰ�ַ�����2�λ����ϣ���str=str+1,pattern=pattern;

�����ǰ�ַ���ƥ�䣬��ֻ����*��ʾ��ǰ�ַ�����0�Σ���str=str��pattern=pattern+2;

B. ģʽ����һ���ַ���Ϊ*

�����ǰ�ַ�ƥ�䣬��*str=*pattern����*str='.' && *pattern!='\0'����str=str+1,pattern=pattern+1.*/

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
