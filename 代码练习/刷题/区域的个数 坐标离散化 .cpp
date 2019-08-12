//区域的个数  坐标离散化 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX_N 501
//输入
int W,H,N;
int X1[MAX_N],X2[MAX_N],Y1[MAX_N],Y2[MAX_N];
//填充用
bool fld[MAX_N*6][MAX_N*6];
//方向用
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0}; 

//对x1和x2进行坐标离散化，并返回离散化之后的宽度
int compress(int *x1,int *x2,int w){
	vector<int> xs;
	
	for(int i=0;i<N;i++){		//N条直线 
		for(int d=-1;d<=1;d++){
			int tx1=x1[i]+d,tx2=x2[i]+d;	//每个直线的起点和终点的横坐标的相邻的格子的横坐标 
			if(1<=tx1&&tx1<=W) xs.push_back(tx1);
			if(1<=tx2&&tx2<=W) xs.push_back(tx2);
		}
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	
	for(int i=0;i<N;i++){
		x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
		x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
	} 
	
	return xs.size();
} 
 
 
void solve(){
	//坐标离散化
	W=compress(X1,X2,W);
	H=compress(Y1,Y2,H);
	
	//填充有直线的部分
	memset(fld,0,sizeof(fld));	//bool类型也可以用0填充
	for(int i=0;i<N;i++){
		for(int y=Y1[i];y<=Y2[i];y++){
			for(int x=X1[i];x<=X2[i];x++){
				fld[y][x]=true;
			}
		}
	}
	
	//求区域的个数
	int ans=0;
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(fld[y][x]) continue;
			ans++;								//发现新大陆 
			
			//BFS
			queue<pair<int,int> > que;
			que.push(make_pair(x,y));
			while(!que.empty()){				//广搜该新大陆 
				int sx=que.front().first,sy=que.front().second;
				que.pop();
				
				for(int i=0;i<4;i++){
					int tx=sx+dx[i],ty=sy+dy[i];
					if(tx<0||W<=tx||ty<0||ty>=H) continue;
					if(fld[ty][tx]) continue;
					que.push(make_pair(tx,ty));	//相邻的空白空格
					fld[ty][tx]=true;			//表示该点已经被访问过 
				}
			} 
		}
	}
	cout<<ans<<endl; 
}

int main(){
	cin>>W>>H>>N;
	for(int i=0;i<N;i++)
		cin>>X1[i];
	for(int i=0;i<N;i++)
		cin>>X2[i];
	for(int i=0;i<N;i++)
		cin>>Y1[i];
	for(int i=0;i<N;i++)
		cin>>Y2[i];
	solve();	
	return 0;
} 
