#include <iostream>
using namespace std;
bool saw[10][10],visited[10]; //saw[][]中保存的是小Hi看到哪两个点是直接相连的,相连为true
//如看到2-3相连，那么saw[2][3]和saw[3][2]的值就都等于true 
int f[10][10]={0},a[10],t,n,x,y,ans;
int cover_sum(int num){
	int cnt=0;
	for(int i=2;i<=num;i++){
		if(saw[a[i]a[i-1]])
	}
}
int main(){
	return 0;
}
