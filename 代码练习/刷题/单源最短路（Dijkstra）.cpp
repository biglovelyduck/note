/*��Դ���·*/
//Dijkstra�㷨��������û�и��ߵ���� 
//��Bellman-Ford�㷨�����޸�
//1.�ҵ���̾����Ѿ�ȷ���Ķ��㣬���������������ڶ�����̾���
//2.�˺���Ҫ��ϵ1�е���̾����Ѿ�ȷ���Ķ��� 

//ʹ���ڽӾ���ʵ�֣����Ӷ�O(V^2) 
const int MAX_V=10000;
int cost[MAX_V][MAX_V];//cost[u][v]��ʾ��e={u,v}��Ȩֵ��������������ʱΪINF
//int d[MAX_V];//����s��������̾���
bool used[MAX_V];//�Ѿ�ʹ�ù���ͼ
//int V;//������
/*
void dijkstra1(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);//��ʼ��
	d[s]=0; 
	while(true){
		int v=-1;
		//����δʹ�ù��Ķ�����ѡ��һ��������С�Ķ���v
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
		}
		if(v==-1) break;
		used[v]=true;//��ʾv�Ѿ�ȷ���� 
		for(int u=0;u<V;u++){
			d[u]=min(d[u],d[v]+cost[v][u]);//�����u�����ڶ����d�������ܲ�������С����
			//������һ��������̵ľ��� 
		} 
	}
} */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF=100000;

//ʹ��priority_queue���ѣ��ڽӱ�ʵ�ֵ�
//���Ӷ�:O(|E|log|V|) 
struct edge{
	int to,cost;
}; 
typedef pair<int,int> P;//first����̾��룬second�Ƕ�����
int V,E;
vector<edge> G[MAX_V];//�ڽӱ� 
int d[MAX_V];
void dijkstra2(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;//ȡ��������С�Ķ���v 
		if(d[v]<p.first) continue;//����õ��Ѿ�ȷ����С�˾����� 
		for(int i=0;i<G[v].size();i++){//�õ���ڽӵ� 
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
} 

int main(){
	int from,to,weight;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>from>>to>>weight;
		edge e;
		e.to=to;
		e.cost=weight;
		G[from].push_back(e);
	}
	dijkstra2(0);
	cout<<d[3]<<endl;
	return 0;
} 

