//я╟урвс╢╝ 
#include <bits/stdc++.h>
using namespace std;
const int M=100;
vector<string> s;
int maxCount(vector<string>& s,string &T){
	vector<int> result(T.length()+1,0);
	sort(s.begin(),s.end(),[](string &s1,string &s2)->bool{
		return s1.length()<s2.length();
	});
	int maxLen;
	for(int i=1;i<=T.length();i++){
		maxLen=0;
		for(int j=0;j<s.size()&&s[j].length()<=i;j++){
			int k=s[j].length()-1;
			for(;k>=0;--k){
				if(s[j][k]!=T[i-s[j].length()+k])	break;
			}
			if(k==-1){
				maxLen=result[i-s[j].length()]+1;
				break;
			}
		}
		result[i]=max(maxLen,result[i-1]);
	}
	return result[T.length()];
}
int main(){
	int m;string T;
	cin>>m;
	for(int i=0;i<m;i++)
		getline(cin,s[i]);
	cin>>T;
	cout<<maxCount(s,T);
	return 0;
}
