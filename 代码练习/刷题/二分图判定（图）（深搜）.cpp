//����ͼ�ж�
//����һ������n�������ͼ����ÿ����Ⱦɫ��Ҫ�����ڶ�����ɫ��ͬ�����ܷ����������ɫ
//��֤���ر��Ի�
//��ͼ����Ⱦɫ����Ҫ����С��ɫ������Ϊ��С��ɫ��
//��С��ɫ����2�Ľ�����ͼ
#include <iostream>
vector <int> G[MAX_V];//ͼ
int V; //������
int color[MAX_V];//����i����ɫ1��-1
//�Ѷ���Ⱦ��1��-1
bool dfs(int v,int c){
	color[v]=c;
	for(int i=0;i<G[v].size();i++){
		//������ڶ���ͬɫ������false
		if(color[G[v][i]]==c) return false;
		//������ڶ��㻹û��Ⱦɫ����Ⱦ��-c
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false; 
	}
	return true;//���ж��㶼��Ⱦ��ɫ�� 
} 

//�����Ƿ���ͨͼ��������д 
void solve(){
	for(int i=0;i<V;i++){
		if(color[i]==0){
			//����Ⱦɫ�������ж� 
			if(!dfs(i,1)){
				cout<<"no";
				return;
			}
		}
	}
	cout<<"yes"; 
} 
