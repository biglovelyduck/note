//2016������ģ���� ��Գ��Ӵ� 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)

//˼·������ÿ���ַ�Ȼ��ָ��ת�ұߵ��ַ������Ӻ���ǰ�Ƚ� 
int main(){
	string s;
	getline(cin,s);
	int maxLen=0;
	for(int i=0;i<s.length();i++){
		int index=s.find(s[i]);			//cout<<"index="<<index<<" ";
		//substrǰ�պ� 
		string s1=s.substr(0,index);
		string s2=s.substr(index+1,s.length());
		if(!s1.empty()) reverse(s1.begin(),s1.end());
		//cout<<s1<<endl;
		int j;
		for(j=0;j<min(s1.length(),s2.length());){
			if(s1[j]!=s2[j]) break;
			else j++;
		}
		maxLen=max(maxLen,j);
	}
	cout<<maxLen*2+1<<endl;
	return 0;
}
