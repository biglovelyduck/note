//2018天梯赛兰州理工大学校内选拔赛 拯救007
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
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
int n;	
double d;
int a[101][101];	//用来保存下标
//pair<int,int> last(0,0);	//上一次踩到的位置 
bool visited[101][101]={false}; 
bool yes=false;
bool dfs(int x,int y){
	if(abs(x)+d>=50||abs(y)+d>=50||((50-abs(x))*(50-abs(x))+(50-abs(y))*(50-abs(y)))<=d*d){
		yes=true;
		return true;
	} 
	if(x==0&&y==0){
		visited[50][50]=true;
		for(int i=-50;i<=50;i++){
			for(int j=-50;j<=50;j++){
				if(a[i+50][j+50]==1&&(abs(i-x)*abs(i-x)+abs(j-y)*abs(j-y)<=(double)((7.5+d)*(7.5+d)))&&!visited[i+50][j+50]){
					visited[i+50][j+50]=true;
					dfs(i,j);
				}
			}
		}
	}
	for(int i=-50;i<=50;i++){
		for(int j=-50;j<=50;j++){	
			if(a[i+50][j+50]==1&&(abs(i-x)*abs(i-x)+abs(j-y)*abs(j-y)<=d*d)&&!visited[i+50][j+50]){
				visited[i+50][j+50]=true;
				dfs(i,j);
			}
		}
	}
	if(!yes) return false;
	else return true;
	//return false;
} 
int main(){
	//memset(a,0,sizeof(a));
	cin>>n>>d;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[x+50][y+50]=1;
	}
	if(dfs(0,0)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

