#include <iostream>
using namespace std;
int ans=0;
int a[8];
bool attack(int x0,int y0,int x1,int y1){//表示两个位置是否可以攻击，是返回true 
	if(x0==x1||y0==y1) return true;
	if(x0+y0==x1+y1||x0-y0==x1-y1) return true;
	return false;
} 
void dfs(int x){//从第x行开始 
	if(x==8){
		ans++;
		return;
	} 
	for(int i=0;i<8;i++){//逐列试探 
		bool ok=true;
		for(int j=0;j<x;j++){//检查之前的行 
			if(attack(j,a[j],x,i)){
				ok=false;
				break;//这一列不符合,找下一列 
			} 
		}
		if(ok){
			a[x]=i;//这一列符合 
			dfs(x+1);//递归深搜 
		} 
	}
}
int main(){
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
