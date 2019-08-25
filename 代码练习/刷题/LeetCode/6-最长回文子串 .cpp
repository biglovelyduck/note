//6-������Ӵ� 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//1.��̬�滮 ��״̬ѹ���� 	babad->bab
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        int len=s.length();
        
        string res="";	
		//����״̬ѹ��
		bool* state=new bool[len];
		state[len-1]=true;
		for(int i=len-2;i>=0;i--){
			for(int j=len-1;j>=i;j--){
				if(i==j)
					state[j]=true;
				else if(s[i]==s[j]){ 
					if(i+1==j) state[j]=true;
					else state[j]=state[j-1];	//state[j]==state[i][j]
				} 
				else
					state[j]=false;
				if(state[j]&&(j-i+1)>res.length()) 
					res=s.substr(i,(j-i+1));
			}
		} 
		return res;
    }
};

//2.��������չ ��ע�⣺�ַ��������Ŀ����Ƕ����ͬ���ַ�������ÿ�δ�������������ͬ�ַ�Ϊ����
 class Solution {
public:
    string longestPalindrome(string s) {
		if(s.length()<=1) return s;
		
		string res="";
		int j;
		for(int i=0;i<s.length();i++){
			//�����ҵ���һ������ȵ��ַ� ,i~j-1Ϊ��ͬ�ַ� 
			for(j=i+1;j<s.length()&&s[j]==s[i];j++){
			}
			int len=longestPalindrome(s,i,j-1); 
			if(len>res.length())
				res+=s.substr(i-(len-(j-i))/2,len); 
		}
		return res;
	}
private:
	int longestPalindrome(const string& s,int i,int j){
		int l=i-1,r=j+1,len=s.length();
		int count=j-i+1;
		while(l>=0&&r<len&&s[l--]=s[r++]) count+=2;
		return count;
	}
};
