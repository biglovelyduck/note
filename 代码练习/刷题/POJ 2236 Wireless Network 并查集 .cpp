//POJ 2236 Wireless Network ���鼯 
/*�������磺ACM�Ŷ�ֻ�޵��Բ���ҹ����N̨���Ի��ˣ�����ԭ���������һ����������
����d�ڵ���̨���Ի���������ͨ������Ͳ鿴��������鿴ʱ��̨�����Ƿ�����

2.4 �ӹ����������ݵ����ݽṹ

���鼯

���ǲ��鼯�Ļ���Ӧ�ã���̨�޺õĵ���������d�������ϲ���������С�ĵĻ���TLE�����磺*/
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
	cin>>N>>d;	//N̨����  �������Ϊd
	for(int i=0;i<N;i++){
		cin>>computer[i].first>>computer[i].second;	//xi,yi��ʾÿ̨����������� 
	} 
	init(N);
	char operation;
	int x,y;
	while(cin>>operation){
		//�޸������  
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
			//������̨������Ƿ���ͨ
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


//ƽ������̫���ˣ���ʼ����ʱ����һ�μ�¼��һ����ά�����о͹��ˡ�
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
