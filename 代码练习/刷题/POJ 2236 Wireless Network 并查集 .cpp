//POJ 2236 Wireless Network 并查集 
/*无线网络：ACM团队只修电脑不过夜！有N台电脑坏了，它们原本组成这样一个局域网：
距离d内的两台电脑互联。现在通过修理和查看操作，求查看时两台电脑是否互联？

2.4 加工并储存数据的数据结构

并查集

这是并查集的基本应用，两台修好的电脑若距离d内则加入合并。不过不小心的话会TLE，比如：*/
/*
#include <iostream>
using namespace std;
#define MAX_N 1001+16
int parent[MAX_N];
int height[MAX_N];
bool status[MAX_N];
int distance[MAX_N][MAX_N];
void init(const int &n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		height[i]=0;
	}
}
int find(const int& x){
	if(parent[x]==x)
		return x;
	else return parent[x]=find(parent[x]);	
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(height[x]<height[y]) parent[x]=y;
	else{
		parent[y]=x;
		if(height[x]==height[y])
			++height[x];
	}
}
bool same(const int& x,const int &y){
	return find(x)==find(y);
}

pair<int,int> computer[MAX_N];
int square(const int& x){
	return x*x;
}

int main(int argc, char *argv[]){
	int N,d;
	cin>>N>>d;	//N台电脑  距离最大为d
	for(int i=0;i<N;i++){
		cin>>computer[i].first>>computer[i].second;	//xi,yi表示每台计算机的坐标 
	} 
	init(N);
	char operation;
	int x,y;
	while(cin>>operation){
		//修复计算机  
		if(operation=='O'){
			cin>>x;
			--x;
			status[x]=true;
			for(int i=0;i<N;i++){
				if(i==x) continue;
				if(status[i]&&(square(computer[x].first-computer[i].first)+square(computer[x].second-computer[i].second))<=square(d))
					unite(x,i);
			}
		}
		else{
			//测试两台计算机是否连通
			cin>>x>>y;
			--x;--y; 
			if(same(x,y))
				cout<<"SUCCESS"<<endl;
			else 
				cout<<"FAIL"<<endl;
		}
	}
	return 0;
}*/


//平方计算太多了，初始化的时候算一次记录在一个二维数组中就够了。
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
using namespace std;
 
#define MAX_N 1001 + 16
int parent[MAX_N];
int height[MAX_N];
bool status[MAX_N];
bool able[MAX_N][MAX_N];
 
void init(const int& n)
{
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
		height[i] = 0;
	}
}
 
int find(const int& x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}
 
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}
 
	if (height[x] < height[y])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
		if (height[x] == height[y])
		{
			++height[x];
		}
	}
}
 
bool same(const int& x, const int& y)
{
	return find(x) == find(y);
}
 
pair<int, int> computer[MAX_N];
int square(const int& x)
{
	return x * x;
}
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, d;
	cin >> N >> d;
	for (int i = 0; i < N; ++i)
	{
		cin >> computer[i].first >> computer[i].second;
	}
	init(N);
	for (int i = 0; i < N; ++i)
	{
		for (int x = i; x < N; ++x)
		{
			if (square(computer[x].first - computer[i].first) + square(computer[x].second - computer[i].second) <= square(d))
			{
				able[i][x] = true;
				able[x][i] = true;
			}
		}
	}
	char operation;
	int x, y;
	while (cin >> operation)
	{
		if (operation == 'O')
		{
			cin >> x;
			--x;
			status[x] = true;
			for (int i = 0; i < N; ++i)
			{
				if (i == x)
				{
					continue;
				}
				if (status[i] && able[x][i])
				{
					unite(x, i);
				}
			}
		}
		else
		{
			cin >> x >> y;
			--x; --y;
			if (same(x, y))
			{
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "FAIL" << endl;
			}
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
