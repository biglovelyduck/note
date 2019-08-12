//POJ 3268 Silver Cow Party
/*��ţ�ɶԣ��зֱ����� N ��ũ���� N ͷţȥũ�� X ��Ƥ��ũ������ M ������·�����ӡ�ÿͷţ���ض�����̵�·�ߣ��������ߵ�·����󳤶ȣ�

2.5 ������ʵ���ǡ�ͼ��

���· dijkstra ��������������·�ı���

��warshall_floyd�Ļ���TLE��10003���Ӷȹ�Ȼ���Ǹǵģ�����X�ı�żǵü�һ�����������ܶ��ĵģ�
��ʹ���˼�һҲ�����ó���ȷ��10������һ�ύ��WA����������ظе������������ߵĶ��⣺*/

//warshall_floyd��ʱ
/* 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 1024
int d[MAX_V][MAX_V];
int V;
void warshall_floyd(){
	for(int k=0;k<V;++k)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
	//freopen("in.txt","r",stdin)
	//freopen("out.txt","w",stdout);
	int M,X;
	cin>>V>>M>>X;
	--X;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<V;i++){
		d[i][i]=0;
	}
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;
		--B;
		d[A][B]=T;
	}
	warshall_floyd();
	int ans=0;
	for(int i=0;i<V;i++)
		ans=max(ans,d[i][X]+d[X][i]);
	cout<<ans<<endl;
}
*/
//��ͨ��dijkstra�ǽ����Դ���·����ģ���΢�޸�һ�¾Ϳ���֧�������������·��
//�ڽӱ�ʵ�� 
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
#define MAX_V 1024
//�Ӷ���fromָ��toȨֵΪcost�ı�
struct edge{
	int to,cost;
	edge(){
	}
	edge(int to,int cost):to(to),cost(cost){
	}
}; 
typedef pair<int,int> P;	//first�����·����second�Ƕ�����
vector<edge> G[MAX_V] ;	//ͼ 

int d[MAX_V][MAX_V];	//��̾���
int V,E;	//������������
void dijkstra(int s){	//�Ӷ���s���������е����̾��� 
	priority_queue<P,vector<P>,greater<P> > que;
	memset(d[s],0x3f,MAX_V*sizeof(int));
	d[s][s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[s][v]<p.first) continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];	//�붥��v���ڵı� 
			if(d[s][e.to]>d[s][v]+e.cost){
				d[s][e.to]=d[s][v]+e.cost;
				que.push(P(d[s][e.to],e.to));
			}
		}
	}
} 
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int M,X;
	cin>>V>>M>>X;
	--X;
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;
		--B;
		G[A].push_back(edge(B,T));
	}
	for(int i=0;i<V;i++)
		dijkstra(i);	//�޸ĵ�dijkstra���ܹ���������������·��
	int ans=0;
	for(int i=0;i<V;i++){
		if(i==X)	continue;
		ans=max(ans,d[i][X]+d[X][i]);
	} 
	cout<<ans<<endl;
	return 0;
}
*/
//�ڽӾ���ʵ��
/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_V=1024;
int cost[MAX_V][MAX_V];	//��ʾ��cost[u][v]��Ȩֵ
int d[MAX_V];
bool used[MAX_V];	//�Ѿ�ʹ�ù��ĵ�
int V; 
void dijkstra(int s){
	d[s]=0;
	while(true){
		int v=-1;	//����ѭ���ı���
		//����δʹ�ù��Ľ����ѡ��һ��������С�ĵ�
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;//v������С����ĵ�
		} 
		if(v==-1) break; //����
        used[v]=true;//v�Ѿ�ȷ��
        for(int u=0;u<V;u++){//�ٴα������еĵ�
            d[u]=min(d[u],d[v]+cost[v][u]);//����
        }
	}
}
int main(){
	int M,X;
	cin>>V>>M>>X;
	--X;
	for(int i=0;i<V;i++)
		used[i]=false;
	memset(d,0x3f,sizeof(d));
	while(M--){
		int A,B,T;
		cin>>A>>B>>T;
		--A;--B;
		cost[A][B]=T;
	} 
 
	return 0;
} */

/*���������Ǹ�ʵ��̫�˷ѣ���ֻ����������յ���X��·�����·���⣬����������
while (!que.empty())��ѭ��������ж���������������ô�棺

��һ������ͼ�������ߵ������յ�õ����������ͼ������dijkstra������⣺*/
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX_V 10240
 
// �Ӷ���fromָ�򶥵�to��ȨֵΪcost�ı�
struct edge
{
	int to, cost;
	edge(){}
	edge(int to, int cost) : to(to), cost(cost){}
};
 
// first ���·����second������
typedef pair<int, int> P;
 
// ͼ
vector<vector<edge> > G(MAX_V);
// ����ͼ
vector<vector<edge> > RG(MAX_V);
 
// ��̾���
int d[MAX_V];
int rd[MAX_V];
// V�Ƕ�������E�Ǳ���
int V, E;
 
// ���Ӷ���s���������е����̾���
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	que.push(P(0, s));
 
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int M, X;
	cin >> V >> M >> X;
	--X;
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		--A;
		--B;
		G[A].push_back(edge(B, T));
		RG[B].push_back(edge(A, T));
	}
	dijkstra(X);
	G = RG;
	memcpy(rd, d, sizeof(d));
	dijkstra(X);
	for (int i = 0; i < V; ++i)
	{
		d[i] += rd[i];
	}
 
	cout << *max_element(d, d + V) << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
