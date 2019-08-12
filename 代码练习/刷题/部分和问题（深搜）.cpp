/*部分和问题*/
/*给定整数a1、a2、…、an，判断是否可以从中选出若干数，使它们的和恰好为k。
限制条件
. 1 ≤ n ≤ 20
. -10^8 ≤ ai ≤ 10^8
. -10^8 ≤ k ≤ 108*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100000000
int a[4]={1,2,4,7};
queue<int> q;
int n,k=13;

bool dfs(int i,int sum){
	if(i==n) return sum=k;
	if(dfs(i+1,sum)){
		return true;	
	} 
	if(dfs(i+1,sum+a[i])){
		return true;	
	}
	return false;
} 

void solve(){
	if(dfs(0,0)){
		cout<<"Yes	"<<k<<"="<<endl;
//		while(!q.empty()){
//			cout<<q.front()<<"+";
//			q.pop();
//		}	
	} 
	else cout<<"No"<<endl;
}

int main(){
	solve();
	return 0;
}
