//2018 天梯赛题集分享码  谁是赢家 
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
	int Pa,Pb;
	cin>>Pa>>Pb;
	bool winA;
	int numA=0,numB=0;
	for(int i=0;i<3;i++){
		int num;
		cin>>num;
		if(num==0) numA++;
		else numB++;
	}
	if(Pa>Pb&&numA>0||Pa<Pb&&numA==3)
		printf("The winner is a: %d + %d",Pa,numA);
	else
		printf("The winner is b: %d + %d",Pb,numB);
	return 0;
}
