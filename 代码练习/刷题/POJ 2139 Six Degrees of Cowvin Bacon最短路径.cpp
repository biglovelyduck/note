//POJ 2139 Six Degrees of Cowvin Bacon
/*六度空间：为了向“六度分割：你和任何一个陌生人之间所间隔的人不会超过五个”致敬，
奶牛们决定拍一系列电影叫做……《六度空间》。N头牛，拍了M部电影，同一部电影中的搭档们距离1，
求最小度数之和。*/
//Floyed_Warshall算法
#include <iostream>
#include <algorithm>
#include <iomanip> //与输出格式有关 
#include <cstring>

using namespace std;

#define MAX_V 300+16
int d[MAX_V][MAX_V];	//d[u][v]表示边e=(u,v)的权值，不存在的时候等于无穷大或者d[i][i] = 0
int V;
int x[MAX_V];	//存放每一行的牛 

void floyed_warshall(){
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
	int M;
	cin>>V>>M;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<V;i++)
		d[i][i]=0;
	while(M--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i];
			--x[i];	//转换为数组下标 
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				d[x[i]][x[j]]=d[x[j]][x[i]]=1;	//双向连通 
			}
		}
	}
	floyed_warshall();
	int ans=0x3f3f3f3f;
	for(int i=0;i<V;i++){
		int sum=0;
		for(int j=0;j<V;j++){
			sum+=d[i][j];
		}
		ans=min(ans,sum); 
	}
	cout<<100*ans/(V-1)<<endl;
	return 0;
} 
