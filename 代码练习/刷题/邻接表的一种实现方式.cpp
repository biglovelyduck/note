/*ͼ-�ڽӱ�ʵ�֣���ϡ��ʱ����*/
//����1 
#include <vector>
vector<int> G[MAX_V];
//���������Ե����
/*
struct edge{
	int to,cost;
}; 
vector<edge> G[MAX_V];*/

int main(){
	int V,E;
	cin>>V>>E;//������������
	for(int i=0;i<E;i++){
		//��s��t����
		int s,t;
		cin>>s>>t;
		G[s].push_back(t); 
	} 
	/*ͼ�Ĳ���*/
	return 0; 
}

//����2
struct vertex{
	vector<vertex*> edge;
	/*���������*/
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
	/*ͼ�Ĳ���*/
} 
