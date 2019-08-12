//2019天梯赛模拟题集  L1-6 Wifi密码
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
	int n;
	cin>>n;
	//freopen("./test.txt","r",stdin);
	vector<int> v;
	while(n--){
		int num=4;
		while(num--){
			char a,b;
			getchar();
			scanf("%c-%c",&a,&b);
			if(b=='T'){
				if(a=='A') v.push_back(1);
				else if(a=='B') v.push_back(2);
				else if(a=='C') v.push_back(3);
				else if(a=='D') v.push_back(4);
			}
	 	}
	}
	for(int i=0;i<v.size();i++) cout<<v[i];
	fclose(stdin);
	return 0;
}
