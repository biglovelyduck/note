//POJ 3259 Wormholes 
/*�涴��ũ��Լ����F��ũ����ÿ��ũ����N��أ������M��·��W��ʱ�������ʱ�䵹���������Ƿ���ܻص���ȥ��

2.5 ������ʵ���ǡ�ͼ��

���·

��Ȼ��ˮ�ܻ����� Bellman-Ford �ж���Ȧ��ʲô�����ÿ��ǣ�һ�� Bellman-Ford �ͽ����ˡ�*/
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_E (2500+200+16)*2
struct edge{
	int from,to,cost;
	edge(){
		
	}
	edge(int from,int to,int cost):from(from),to(to),cost(cost){
		
	} 
}; 
edge es[MAX_E];
int d[MAX_E];
int V,E; 
bool find_negative_loop(){	//���ڸ�Ȧ����true 
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;i<E;j++){	//��ÿ���㿪ʼ�������еı� 
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				//���������V�Σ����ʾ���ڸ�Ȧ
				if(i==V-1)	return true; 
			} 
		}
	}
	return false;
}
int main(){
	int F;	//ũ����
	cin>>F;
	while(F--){
		int N,M,W;	//�������·�������涴��
		cin>>N>>M>>W;
		V=N;
		E=0;
		//M��·�� 
		for(int i=0;i<M;i++){
			int from,to,cost;
			cin>>from>>to>>cost;
			--from;
			--to;
			es[E].from=from;
			es[E].to=to;
			es[E].cost=cost;
			++E;
			//����ͼ����һ��
			es[E].from = to;
  			es[E].to = from;
  			es[E].cost = cost;
  			++E; 
		} 
		for(int i=0;i<W;i++){
			int from,to,cost;
			cin>>from>>to>>cost;
			--from;
			--to;
			es[E].from = from;
			es[E].to = to;
			es[E].cost = -cost;
			++E;
		}
		if (find_negative_loop())
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	} 
	return 0;
}
