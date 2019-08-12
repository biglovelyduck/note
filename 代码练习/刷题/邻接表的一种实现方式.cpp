/*图-邻接表实现，边稀疏时适用*/
//样例1 
#include <vector>
vector<int> G[MAX_V];
//边上有属性的情况
/*
struct edge{
	int to,cost;
}; 
vector<edge> G[MAX_V];*/

int main(){
	int V,E;
	cin>>V>>E;//顶点数，边数
	for(int i=0;i<E;i++){
		//从s向t连边
		int s,t;
		cin>>s>>t;
		G[s].push_back(t); 
	} 
	/*图的操作*/
	return 0; 
}

//样例2
struct vertex{
	vector<vertex*> edge;
	/*顶点的属性*/
}; 
vertex G[MAX_V];

int main(){
	int V,E;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		int s,t;
		cin>>s>>t;
		G[s].edge.push_back(&G[t];
	}
	/*图的操作*/
} 
