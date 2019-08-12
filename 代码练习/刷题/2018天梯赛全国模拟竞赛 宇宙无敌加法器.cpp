//2018天梯赛全国模拟竞赛 宇宙无敌加法器
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
//又错了，救救孩子把 
 /*
int main(){
	string s;
	string s1,s2;
	cin>>s>>s1>>s2;
	int n[s.length()];	//进制表
	int a[s.length()]={0},b[s.length()]={0};
	int jw[s.length()+1]={0};
	int result[s.length()];
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') n[i]=10;
		else n[i]=s[i]-'0';
	}
	int index=s.length()-1;
	for(int i=s1.length()-1;i>=0;i--){
		a[index--]=s1[i]-'0';
	}
	index=s.length()-1;
	for(int i=s2.length()-1;i>=0;i--){
		b[index--]=s2[i]-'0';
	}
	for(int i=s.length()-1;i>=0;i--){
		result[i]=(a[i]+b[i]+jw[i+1])%n[i];
		jw[i]=(a[i]+b[i]+jw[i+1])/n[i];
	}
	if(jw[0]!=0) cout<<jw[0];
	int start=0;
	for(int i=0;i<s.length();i++){
		if(result[i]!=0){
			start=i;
			break;
		}
	}
	for(int i=start;i<s.length();i++)
		cout<<result[i];
}*/

//柳神代码 
#include <iostream>
using namespace std;
int main() {
	string s, s1, s2, ans;
	int carry = 0, flag = 0;
	cin >> s >> s1 >> s2;
	ans = s;
	string ss1(s.length() - s1.length(), '0');
	s1 = ss1 + s1;
	string ss2(s.length() - s2.length(), '0');
	s2 = ss2 + s2;
	for(int i = s.length() - 1; i >= 0; i--) {
		int mod = s[i] == '0' ? 10 : (s[i] - '0');
		ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
	}
	if (carry != 0) ans = '1' + ans;
	for(int i = 0; i < ans.size(); i++) {
		if (ans[i] != '0' || flag == 1) {
			flag = 1;
			cout << ans[i];
		}
	}
	if (flag == 0) cout << 0;
	return 0;
}

