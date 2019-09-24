//44-ͨ���ƥ��
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
//��̬�滮
//1.״̬��f[i][j]��ʾs1��ǰi���ַ���s2��ǰj���ַ��ܷ�ƥ��
//2.ת�Ʒ��̣� 1)���ij��Ӧ���ַ���Ȼ�s2[j]=.		f[i][j]=f[i-1][j-1]
//				2)���s2[j]Ϊ*��
//					1.��ƥ��մ���f[i][j]=f[i][j-1]		�����ӣ�(a,a*) 
//					2.f[i][j]=f[i-1][j]
//3.��ʼ����f[0][i]=f[0][i-1]&&s2[i]==* 
class Solution {
public:
    bool isMatch(string s, string p) {
    	int m=s.size(),n=p.size(); 
//		//��һ�ַ��� 	
//		bool **f=new bool*[m+1];
//		for(int i=0;i<m+1;i++){
//			f[i]=new bool[n+1]; 
//			memset(f[i],false,sizeof(f));
//		}
//		//�ڶ��ַ�����
//		bool **f=(bool**)malloc(sizeof(bool)*(m+1));
//		for(int i=0;i<m+1;i++){
//			f[i]=new bool[n+1]; 
//			memset(f[i],false,sizeof(f));
//		} 
//		//�����ַ���
//		vector<vector<int> > swp(n);//��ʾ��ά������  4��  ��������> >�м�Ŀո���ʡ��
//		for(int i=0;i<n;i++)
//		{swp[i].resize(m);}//��ʾ��ά������   2��		

		bool f[m+1][n+1]={false};
		f[0][0]=true;
		for(int i=1;i<=n;i++){
			f[0][i]=f[0][i-1]&&p[i-1]=='*';
		}
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(s[i-1]==p[j-1]||p[j-1]=='?') f[i][j]=f[i-1][j-1];
				if(p[j-1]=='*') f[i][j]=f[i][j-1]||f[i-1][j];
			}
		}
		return f[m][n];
	}
};

//����
class Solution1{
public:
	bool isMatch(string s,string p){
		int int start=0,i=0,last=0,j=0;
		while(i<s.length()){
			if(j<p.size()&&(s[i]==p[j]||p[j]=='?')) i++,j++;
			else if(j<p.size()&&p[j]=='*') last=i,start=++j;	//last���浱ǰi��λ�ã�start����*����j�ĵ�λ�� 
			else if(start!=0)	i=++last,j=start;
			else return 0;
		}
		for(;j<p.size()&&p[j]=='*';++j);
		return j==p.size(); 
	}
}; 

int main(){
	Solution1 s;
	cout<<s.isMatch("abefcdgiescdfimde","ab*cd?i*de");
}
