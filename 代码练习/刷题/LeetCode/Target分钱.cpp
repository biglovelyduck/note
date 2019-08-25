//Target分钱
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
const int N=13;	//n的最大值
int counnt=0,Target,coin[4]={1,2,5,10},total=0;
vector<int>  sol;
void dfs(int index){
	if(total==Target){
		counnt++;
		cout<<"sol:";
		for(int i=0;i<sol.size();i++)
			cout<<sol[i]<<" ";
		cout<<endl;
		//sol.clear();
		//return;
	}
	else if(total>Target) return;
	
	for(int i=index;i<4;i++){
		total+=coin[i];
		sol.push_back(coin[i]);
		dfs(i);
		sol.pop_back();
		total-=coin[i];
	}
} 
int main(){
	cin>>Target;
	dfs(0);
	cout<<counnt<<endl;
}
