//2019������ģ���⼯  ���ݵ�ͼ  
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
/*������������Dijkstra + DFS��һ�������·���������ͬ��·������������
һ�������·���������ͬ��������С�����������������·������ֱ����Dijkstra��
����ǰ�����Timepre����~~~�����·����ΪҪ��������С������������Ҫ��dispre��
��ά����洢���н������·����Ȼ����DFS������������Ľ������С����������*/
int dis[510],Time[510];	//��̾��룬���ʱ��
int e[510][510],w[510][510];	//����u��v���ѵľ��룬ʱ�� ,�ڽӾ���洢 
int Timepre[510],weight[510];	//���·��ǰ��������飬���ﶥ��i���õ����·�� 
bool visit[510];
vector<int> Timepath,dispath,temppath,dispre[510];
int st,fin,minnode=inf;

void dfsTimepath(int v){
	Timepath.push_back(v);
	if(v==st) return;
	dfsTimepath(Timepre[v]);
} 

void dfsdispath(int v){
	temppath.push_back(v);
	if(v==st){
		if(temppath.size()<minnode){
			minnode=temppath.size();
			dispath=temppath;
		}
		temppath.pop_back();
		return;
	}
	for(int i=0;i<dispre[v].size();i++)		//dispre[v]�����ж������ 
		dfsdispath(dispre[v][i]);
	temppath.pop_back();
}

int main(){
	fill(dis,dis+510,inf);	//��ʼ������������
	fill(Time,Time+510,inf);	//��ʼ���������ʱ�� 
	fill(weight,weight+510,inf);
	fill(e[0],e[0]+510*510,inf);
	fill(w[0],w[0]+510*510,inf);
	int n,m;	//�����������·��
	cin>>n>>m;
	int a,b,flag,len,t;
	for(int i=0;i<m;i++){
		cin>>a>>b>>flag>>len>>t;	//����a->b �Ƿ��ǵ����  ����   ʱ��
		e[a][b]=len; 
		w[a][b]=t;
		if(flag!=1){	//˫��� 
			e[b][a]=len;
			w[b][a]=t;
		} 
		cin>>st>>fin;	//�����յ�ı�� 
	}
	
	Time[st]=0;	//����ʱ��Ϊ0
	for(int i=0;i<n;i++){
		//������ 0-N-1
		Timepre[i]=i; 	//��ʼ������������ 
	}
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;	//minn����ӵ�ǰ����������ڵ�����ʱ�� 
		for(int j=0;j<n;j++){
			if(!visit[j]&&Time[j]<minn){
				u=j;	//�������ʱ��ȷ���ĵ� 
				minn=Time[j];
			}
		}
		if(u==-1) break;
		visit[u]=true;	//u���Ѿ�ȷ��ok
		//ȥ����ǰ��ĵ� 
		for(int v=0;v<n;v++){
			if(visit[v]==false&&w[u][v]!=inf){
				if(w[u][v]+Time[u]<Time[v]){
					Time[v]=Time[u]+w[u][v];
					Timepre[v]=u;	//����ǰһ�����ʱ��ĵ�
					weight[v]=weight[u]+e[u][v] ;
				}
				else if(w[u][v]+Time[u]==Time[v]&&weight[v]>weight[u]+e[u][v]){
					//�������·����
					weight[v]=weight[u]+e[u][v];
					Timepre[v]=u; 
				}
			}
		} 
	} 
	//�Ѿ�ȷ�������е����ʱ��ĵ���
	dfsTimepath(fin); 	//�������յ� 
	
	//��ʼ�������·��
	fill(visit,visit+510,false);
	dis[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<minn){
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1) break;	//ÿ�ζ��ҵ����ŵ�
		//�������ŵ��ɳ���Χ
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v]&&e[u][v]!=inf){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];
					dispre[v].clear();
					dispre[v].push_back(u);
				}
				else if(dis[u]+e[u][v]==dis[v]){
					dispre[v].push_back(u);
				}
			}
		} 
	} 
	dfsdispath(fin);
	
	cout<<"Time = "<<Time[fin];
	if(dispath==Timepath)	//���·�����·�غ� 
		cout<<"; Distance = "<<dis[fin]<<": ";
	else{
		cout<<": ";
		for(int i=Timepath.size()-1;i>=0;i--){
			cout<<Timepath[i];
			if(i!=0) cout<<" =>";
		}
		cout<<endl;
		cout<<"Distance = "<<dis[fin]<<": ";
	}
	for(int i=dispath.size()-1;i>=0;i--){
		cout<<dispath[i];
		if(i!=0) cout<<" =>";
	}
	return 0;
}
