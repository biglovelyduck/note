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

int main(){
	string s;
	map<char,int> mp;
	vector<int> v;
	cin>>s;
	for(int i=0;i<s.length();i++){
		mp[s[i]]=i;	//更新最长分片 
	} 
	//for(int i=0;i<s.length();i++)	cout<<mp[s[i]]<<endl;
	int maxS=0,i=0;
	for(int j=0;j<s.length();j++){
		maxS=max(maxS,mp[s[j]]);
		if(j==maxS){
			v.push_back(j-i+1);
			i=j+1; 
			maxS=0;
		}
	}
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) cout<<v[i];
		else cout<<v[i]<<" ";
	}
	return 0;
}
